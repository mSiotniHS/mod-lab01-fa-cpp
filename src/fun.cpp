// Copyright 2022 UNN-IASR
#include <cstring>
#include <cctype>
#include "fun.h"

using namespace std;

const char space = ' ';

unsigned int faStr1(const char *str) {
    size_t length = strlen(str);

    bool inWord = false;
    bool digitless = true;
    unsigned int digitlessCount = 0;

    for (int i = 0; i < length; i++)
    {
        char character = str[i];
        bool isLastIteration = i == length - 1;

        if (!inWord && character != space)
        {
            inWord = true;
            digitless = true;
        }

        if (inWord && digitless && isdigit(character))
        {
            digitless = false;
        }

        if (inWord && character == space || inWord && isLastIteration)
        {
            inWord = false;
            digitlessCount += digitless;
        }
    }

    return digitlessCount;
}

unsigned int faStr2(const char *str) {
    return 0;
}

unsigned int faStr3(const char *str) {
    return 0;
}
