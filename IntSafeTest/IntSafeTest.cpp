#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_MEMORY 1
#define __STDC_WANT_SECURE_LIB__ 1

#include <windows.h>
#include <intsafe.h>
#include <stdlib.h>
#include <assert.h>
#include <memory.h>

#define ASSERT

#include "SafeInt3.hpp"
#include <cstdlib>
#include <iostream>

void intsafe() {
    DWORD value1 = UINT_MAX/2 + 10;
    DWORD result;

    // *2 and +1
    if (SUCCEEDED(ULongMult(value1, 2, &result)) &&
        SUCCEEDED(ULongAdd(result, 1, &result))) {

        void* mem = malloc(result);
        if (mem != NULL) {
            free(mem);
        }
    }
}

void safeint() {

    SafeInt<unsigned int> value1 = 5000; 

    //  *2 and +1
    SafeInt<unsigned int> result = value1 * 2 + 1;

    void* mem = std::malloc(result);

    if (mem != nullptr) {
        std::free(mem);
    }
}

int main() {
    intsafe();
    safeint();
}
