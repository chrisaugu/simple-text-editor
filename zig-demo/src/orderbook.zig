const std = @import("std");

pub fn main() !void {
    const user = User {
        .name = "Alice",
        .age = 30,
    }

    std.debug.print("User: {}, Age: {}\n", .{user.name, user.age});
}

pub const User = struct {
    name: []const u8,
    age: u32,
};