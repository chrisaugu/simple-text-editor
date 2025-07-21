#include <iostream>
#include <string>
#include <cmath>
// #include "linkedlist.h"

using namespace std;

enum ROLE
{
    ADMIN,
    USER,
    GUEST
} roles;

struct Person
{
    string name;
    int age;
    bool do_programming;
};

struct Point2d
{
    int x;
    int y;
};

struct Point3d
{
    int x;
    int y;
    int z;
};

class Point
{
public:
    int x;
    int y;

    void move(int x, int y)
    {
        this->x += x;
        this->y += y;
    }

    void print()
    {
        cout << "Point(x, y) = {" << x << "," << y << "}" << endl;
    }
};

void myFunction()
{
    char alpha[26] = {
        'a',
        'b',
        'c'};

    cout << alpha[2] << endl;

    Point p1;
    p1.x = 10;
    p1.y = 20;
    p1.move(2, 3);
    p1.print();
}

void myPointers()
{
    int a = 5;
    int *b = 0;

    cout << "\"b\" is initialized and now pointing to memory-address:  " << b << endl
         << endl;

    // make the pointer point to address of a
    // '*' - pointers
    // '&' - address
    // address must be assigned to pointers only
    // address cannot be assigned to vr
    b = &a;

    cout << "\"a\" is stored at memory-address:  " << &a << endl;
    cout << "\"b\" is stored at memory-address:  " << &b << endl;
    cout << "\"b\" is pointing to memory-address now:  " << b << endl
         << endl;

    cout << "The value of \"a\" is: " << a << endl; // returns the value of a
    cout << "The value of \"b\" is: " << b << endl; // returns the value of a

    int n = 1;
    // void *p1;
    int *p2;
    int *p3;
    int n1;
    // // p2 = p1;         // Valid in C but not C++
    // p1 = &n;
    // p2 = (int *)p1; // In C++ we have to typecast the pointer!
    // *p2 += 1;

    p2 = &n;
    // p3 = n;

    cout << n << endl;
}

void addOneByValue(int n)
{
    // n is local variable which only exists within the function scope
    n++; // therefore incrementing it has no effect
    // increment will not take effect in value passed to n;
}

void addOneByRef(int *n)
{
    (*n)++;
}
// similar to addOneByRef but returns value;
int addOneNReturn(int n)
{
    n++;
    return n;
}

void move(Point2d *p)
{
    (*p).x++;
    (*p).y++;

    // p->x++;
    // p->y++;
}

// execute c/c++ program
// g++ program-source-code.cpp -o program-source-code
// g++ program-source-code.C -o program-source-code
// gcc program-source-code.c -o executable-file-name
// make program-source-code
int main(void)
{
    typedef int counter;
    counter tick_c = 11;

    // int foo;
    // int bar = 11;

    // int a = 3;
    // float b = 4.5;
    // double c = 5.25;
    // double sum;

    // sum = a + b + c;

    // cout << "The sum of a, b, and c is " << sum << endl;

    myFunction();

    // string str = "hello";

    // getline(cin, str);

    // cout << "You entered " << str << endl;

    // int i = 0;
    // for (; i < 10;)
    // {
    //     cout << i << endl;
    //     i++;
    // }

    // // Pass by Value
    // int arr[] = {1, 2, 3, 4, 5, 6};
    // for (int n : arr)
    // {
    //     cout << n << endl;
    // }

    // // Pass by const Reference
    // // fetch each array-element and print it out (readonly)
    // int arr[] = {1, 2, 3, 4, 5, 6};
    // for (const int &n : arr)
    // {
    //     cout << n << endl;
    // }

    myPointers();

    Person p1;
    p1.name = "bob";
    p1.age = 19;
    p1.do_programming = false;

    int n = 5;
    printf("Before: %d\n", n);
    // addOneByRef(&n);
    n = addOneNReturn(n);
    printf("After: %d\n", n);

    double x{};
tryAgain:
    std::cout << "Enter a non-negative number: ";
    std::cin >> x;

    if (x < 0.0)
    {
        goto tryAgain;
    }

    std::cout << "The square root of " << x << " is " << std::sqrt(x) << endl;

    return 0;
}