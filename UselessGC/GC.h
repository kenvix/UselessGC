#pragma once
#include <map>
#include <set>

#include "Object.h"

using std::set;

class GC
{
private:
	static set<Object*> objects;
	static SysLog logger;
	static  bool contains(Object* obj);
public:
	static Object* allocate(size_t size);
	static void reduceReference(Object* object);
	static void addOneReference(Object* object);
	static void destroy(Object* object);
	static void runGCFor(Object* object);
	friend class Object;
	friend class R;
};