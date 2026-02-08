#include "my_c_code.h" // Includes C function declaration

int main()
{
    say_hello_from_c(); // Call the C function
    return 0;
}

// gcc -c my_c_code.c       # Compile C file to object file
// g++ main.cpp my_c_code.o -o mixed_program
// ./mixed_program