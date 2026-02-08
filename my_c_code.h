#ifndef MY_C_CODE_H
#define MY_C_CODE_H

// Prevent C++ name mangling when included in C++ code
#ifdef __cplusplus
extern "C"
{
#endif

    void say_hello_from_c(void);

#ifdef __cplusplus
}
#endif

#endif // MY_C_CODE_H
