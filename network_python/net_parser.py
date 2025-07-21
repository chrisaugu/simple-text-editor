from networkparse import parse
import os

import paramiko

device_message = "This is a device:"

network_devices = ["SW1","R1","R2","ASA1"]

for device in network_devices:
    print(device_message)
    print(device)

running_configuration = """
hostname R1
!
boot-start-marker
boot-end-marker
!
no aaa new-model
!
mmi polling-interval 60
no mmi auto-configure
no mmi pvc
mmi snmp-timeout 180
!
ip cef
no ipv6 cef
!
multilink bundle-name authenticated
!
redundancy
!
interface GigabitEthernet0/1
 ip address 192.168.12.1 255.255.255.0
 duplex auto
 speed auto
 media-type rj45
!
interface GigabitEthernet0/2
 ip address 192.168.13.1 255.255.255.0
 duplex auto
 speed auto
 media-type rj45
!
router bgp 1
 bgp log-neighbor-changes
 network 1.1.1.1 mask 255.255.255.255
 neighbor 192.168.12.2 remote-as 2
 neighbor 192.168.13.3 remote-as 3
!
ip forward-protocol nd
!
no ip http server
no ip http secure-server
!         
ipv6 ioam timestamp
!

control-plane
!
line con 0
line aux 0
line vty 0 4
 login
 transport input none
!
no scheduler allocate
!
end
"""


config = parse.ConfigIOS(running_configuration)

interfaces = config.filter("interface .+")
for interface in interfaces:
    ip_address = interface.children.filter("ip address .*").one()
    print(interface)
    print(ip_address)

# config_file = open("config.txt")
# print(config_file.readlines())

# config_file.close()

with open("config.txt", "w") as text_file:
    lines = text_file.write(running_configuration)

with open("config.txt") as text_file:
    lines = text_file.readlines()

print(lines)

file_to_delete = "demo2.txt"

if os.path.exists(file_to_delete):
    os.remove(file_to_delete)
else:
  print("File does not exist.")



router_ip = "172.30.4.55" #"172.16.1.100"
router_username = "onix"
router_password = "vpng@24wts"

ssh = paramiko.SSHClient()

def run_command_on_device(ip_address, username, password, command):
    """ Connect to a device, run a command, and return the output."""

    # Load SSH host keys.
    ssh.load_system_host_keys()
    # Add SSH host key when missing.
    ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
    
    total_attempts = 3
    for attempt in range(total_attempts):
        try:
            print("Attempt to connect: %s" % attempt)
            # Connect to router using username/password authentication.
            ssh.connect(router_ip, 
                        username=router_username, 
                        password=router_password,
                        look_for_keys=False )
            # Run command.
            ssh_stdin, ssh_stdout, ssh_stderr = ssh.exec_command(command)
            # Read output from command.
            output = ssh_stdout.readlines()
            # Close connection.
            ssh.close()
            return output

        except Exception as error_message:
            print("Unable to connect")
            print(error_message)


# Run function
router_output = run_command_on_device(router_ip, router_username, router_password, "show ip route")

# Analyze show ip route output
# Make sure we didn't receive empty output.
if router_output != None:
    for line in router_output:
        if "0.0.0.0/0" in line:
            print("Found default route:")
            print(line)