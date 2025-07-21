#include <Python.h>

int main() {
    Py_Initialize();

    // Set Python script path to current directory (optional if script is elsewhere)
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('.')");

    // Run Python script
    PyRun_SimpleString("import myscript");

    Py_Finalize();
    return 0;
}


// g++ main.cpp -o run_python_with_cpp `python3-config --includes --ldflags`