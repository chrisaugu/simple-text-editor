#!/usr/local/bin/lua

local i, j
local f = 5

print("hello World")

io.write("Hello WOrld, from ", _VERSION, "!\n")

j = 5/3

print("var j = ", j)

g, l = 30, 20

print("var g = ", g)

print(type("What is my type"))


function max(num1, num2)
  if (num1 > num2) then
    result = num1
  else 
    result = num2
  end

  return result
end

print("The max Value: ", max(5, 4))


-- while (true) 
-- do
--   print("This loop will run forever")
-- end

anonFunc = function(param)
  print("This is my print function - ##", param, "##")
end

function add(num1, num2, functionPrint)
  result = num1 + num2
  functionPrint(result)
end

anonFunc(10)
add(2, 3, anonFunc)

