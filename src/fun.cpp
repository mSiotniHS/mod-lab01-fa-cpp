// Copyright 2022 UNN-IASR
#include <cstring>
#include <cctype>
#include <cmath>
#include "fun.h"

const char space = ' ';

unsigned int faStr1(const char *str) {
    std::size_t length = strlen(str);

    bool inWord = false;
    bool digitless = true;
    unsigned int digitlessCount = 0;

    for (std::size_t i = 0; i < length; i++) {
        char character = str[i];
        bool isLastIteration = i == length - 1;

        if (!inWord && character != space) {
            inWord = true;
            digitless = true;
        }

        if (inWord && digitless && isdigit(character)) {
            digitless = false;
        }

        if (inWord && character == space || inWord && isLastIteration) {
            inWord = false;
            digitlessCount += digitless ? 1 : 0;
        }
    }

    return digitlessCount;
}

unsigned int faStr2(const char *str) {
    std::size_t length = strlen(str);

    bool inWord = false;
    bool isHeadUppercase = false;
    bool isTailLowercase = false;
    unsigned int capitalizedWordCount = 0;

    for (std::size_t i = 0; i < length; i++) {
        char character = str[i];
        bool isLastIteration = i == length - 1;

        if (!inWord && character != space) {
            inWord = true;
            isHeadUppercase = isupper(character);
            isTailLowercase = true;
        } else if (inWord && character != space &&
                   isHeadUppercase && isTailLowercase) {
            isTailLowercase = islower(character);
        }

        if (inWord && character == space || inWord && isLastIteration) {
            inWord = false;
            capitalizedWordCount += isHeadUppercase && isTailLowercase ? 1 : 0;
        }
    }

    return capitalizedWordCount;
}

unsigned int faStr3(const char *str) {
    std::size_t length = strlen(str);

    bool inWord = false;
    unsigned int wordCount = 0;
    unsigned int lengthSum = 0;

    for (std::size_t i = 0; i < length; i++) {
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

    return round(static_cast<float>(lengthSum) / wordCount);
}
