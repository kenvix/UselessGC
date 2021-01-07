#include "SysLog.h"

#include <iostream>
#include <string>

using std::string;
using std::bad_alloc;
using std::size_t;
using std::endl;
using std::cerr;

SysLog::SysLog(const string& name) {
	this->name = name;
}