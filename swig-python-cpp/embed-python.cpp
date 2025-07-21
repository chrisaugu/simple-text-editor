// sudo apt-get install python3-dev
#include <Python.h>

int main()
{
    Py_Initialize(); // Initialize interpreter

    PyRun_SimpleString("print('Hello from Python!')");

    Py_Finalize(); // Finalize interpreter
    return 0;
}
// g++ main.cpp -o main `python3-config --includes --ldflags`