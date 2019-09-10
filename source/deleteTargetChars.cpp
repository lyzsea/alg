//
// Created by yz L on 2019-09-10.
//
#include "../header/deleteTargetChars.h"

int CDeleteTarget::delTargetChars(char *src, const char *delTarget) {
    if (src == nullptr || delTarget == nullptr) {
        return -1;
    }

    const unsigned int nTableSize = 256;
    int hashTables[nTableSize] = {0};
    const char *pTemp = delTarget;
    while ('\0' != *pTemp) {
        hashTables[*pTemp] = 1;
        ++pTemp;
    }

    char *pFast = src;
    char *pSlow = src;
    while ('\0' != *pFast) {
        if (hashTables[*pFast] == 1) {
            pFast++;
        } else {
            if (pFast != pSlow) {
                *pSlow = *pFast;
            }
            pFast++;
            pSlow++;
        }
    }

    *pSlow = '\0';

    return 0;
}


int CDeleteTarget::delTargetCharsBetter(char *src, const char *delTarget) {
    if (src == nullptr || delTarget == nullptr) {
        return -1;
    }

    const unsigned int nTableSize = 256;
    int hashTables[nTableSize] = {0};
    const char *pTemp = delTarget;
    while ('\0' != *pTemp) {
        hashTables[*pTemp] = 1;
        ++pTemp;
    }

    char *pFast = src;
    char *pSlow = src;
    while ('\0' != *pFast) {
        if (hashTables[*pFast] != 1) {
            *pSlow = *pFast;
            ++pSlow;
        }
        pFast++;
    }

    *pSlow = '\0';
    return 0;
}