#pragma once
#include "GC.h"

class R
{
private:
	Object* object;

public:
	R(Object* obj);

	~R();

	Object& get();
};
