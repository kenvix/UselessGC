//
// Created by Kenvix on 2021/1/7.
//

#include "XString.h"

string XString::toString() {
    return value;
}

XString::XString(string &string) {
    this->value = string;
}
