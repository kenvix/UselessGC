#include <iostream>

#include "Object.h"

#include "GC.h"
#include "SysLog.h"
#include "R.h"

using std::string;
using std::bad_alloc;
using std::size_t;
using std::set;

SysLog Object::logger = SysLog("Object");
set<Object*> Object::emptyDependsSet = set<Object*>();

void* Object::operator new(size_t size) {
	return GC::allocate(size);
}

void Object::operator delete(void* ptr) {
	GC::destroy((Object*) ptr);
}

R Object::operator=(Object& other) {
	return R(&other);
}

//inline R Object::operator=(Object& other)
//{
//	return R(&other);
//}

Object::Object() {
	//references = set<R*>();
	referencesNum = 0;
}

bool Object::equals(const Object& other) {
	return (&other) == this;
}

string Object::toString() {
	return "Object object";
}

bool Object::operator ==(const Object& other) {
	return equals(other);
}

bool Object::operator !=(const Object& other) {
	return !equals(other);
}

set<Object *> &Object::getDepends() {
    return emptyDependsSet;
}
