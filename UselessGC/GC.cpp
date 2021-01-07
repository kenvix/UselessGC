#include "GC.h"
#include <set>

#include "Object.h"

using std::set;

SysLog GC::logger = SysLog("GC");
set<Object*> GC::objects = set<Object*>();

bool GC::contains(Object* obj) {
	return objects.find(obj) != objects.end();
}

Object* GC::allocate(size_t size) {
	logger.debug("Allocating object with size ", size);
	Object* mem = (Object*)malloc(size);
	objects.insert(mem);

	if (mem) {
		return mem; //return malloc(size);
	} else {
		throw bad_alloc();
	}
}

void GC::destroy(Object* object) {
	logger.debug("Deleting object with address ", object);

	if (object && contains(object)) {
		objects.erase(object);
		free(object);
	}
}

void GC::runGCFor(Object* object) {
    if (object->referencesNum <= 0) {
        GC::destroy(object);
    }
}
