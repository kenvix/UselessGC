#include "R.h"
#include "Object.h"

using std::to_string;

R::R(Object* obj) {
	GC::logger.debug("NEW Reference of object ", obj, " Reference num: ", to_string(obj->referencesNum + 1));
	this->object = obj;
	this->object->referencesNum++;
	if (!this->object->getDepends().empty()) {
        for (auto dep : this->object->getDepends()) {
            dep->referencesNum++;
        }
	}
}

R::~R() {
	GC::logger.debug("DELETE Reference of object ", object, " Reference num: ", to_string(object->referencesNum - 1));
	this->object->referencesNum--;
    if (!this->object->getDepends().empty()) {
        for (auto dep : this->object->getDepends()) {
            dep->referencesNum--;
            GC::runGCFor(dep);
        }
    }
    GC::runGCFor(this->object);
}

Object& R::get() {
	return *object;
}
