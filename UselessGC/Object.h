#pragma once
#include <set>
#include "SysLog.h"

using std::string;
using std::bad_alloc;
using std::size_t;
using std::set;

class R;
class Object {
private:
	static SysLog logger;
	int referencesNum;
	static set<Object*> emptyDependsSet;

public:
	Object();
	void* operator new(size_t size);
	virtual ~Object() = default;

    virtual set<Object*>& getDepends();

    inline R operator =(Object& other);

	virtual bool equals(const Object& other);
	virtual string toString();
	virtual bool operator ==(const Object& other);
	virtual bool operator !=(const Object& other);

	friend class GC;
	friend class R;

	void operator delete(void* ptr);
};