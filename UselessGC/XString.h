//
// Created by Kenvix on 2021/1/7.
//

#ifndef USELESSGC_XSTRING_H
#define USELESSGC_XSTRING_H

#include "Object.h"

class XString : public Object {
private:
    string value;
public:
    XString(string& string);
    string toString() override;
};

#endif //USELESSGC_XSTRING_H
