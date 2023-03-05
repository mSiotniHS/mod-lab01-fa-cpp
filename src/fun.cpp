// Copyright 2022 UNN-IASR
#include <cstring>
#include <cctype>
#include <cmath>
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
    size_t length = strlen(str);

    bool inWord = false;
    bool isHeadUppercase = false;
    bool isTailLowercase = false;
    unsigned int capitalizedWordCount = 0;

    for (size_t i = 0; i < length; i++)
    {
        char character = str[i];
        bool isLastIteration = i == length - 1;

        if (!inWord && character != space)
        {
            inWord = true;
            isHeadUppercase = isupper(character);
            isTailLowercase = true;
        }
        else if (inWord && character != space && isHeadUppercase && isTailLowercase)
        {
            isTailLowercase = islower(character);
        }

        if (inWord && character == space || inWord && isLastIteration)
        {
            inWord = false;
            capitalizedWordCount += isHeadUppercase && isTailLowercase; // наверное, не шибко читабельно
        }
    }

    return capitalizedWordCount;
}

unsigned int faStr3(const char *str) {
    size_t length = strlen(str);

    bool inWord = false;
    unsigned int wordCount = 0;
    unsigned int lengthSum = 0;

    for (size_t i = 0; i < length; i++) {
        char character = str[i];

        if (!inWord && character != space) {
            inWord = true;
            wordCount++;
        }

        if (inWord && character != space) {
            lengthSum++;
        }

        if (inWord && character == space) {
            inWord = false;
        }
    }

    return round((float) lengthSum / wordCount);
}
