#include "Object.h"
#include "R.h"
#include "XString.h"

class ObjectWrapper : public Object {
private:
    Object* obj;
    set<Object*> depends;
public:
    ObjectWrapper(Object* o) : obj(o) {
        depends = set<Object*>();
        depends.insert(o);
    }

    set<Object *> & getDepends() override {
        return depends;
    }

    string toString() override {
        return "ObjectWrapper: " + obj->toString();
    }
};

void test() {
	R obj = new Object();
    std::cerr << obj.get().toString() << endl;
    string s = "Written by student code 1807004718";
    R obj2 = new XString(s);
    std::cerr << obj.get().toString() << endl;
    std::cerr << obj2.get().toString() << endl;

    R x = new ObjectWrapper(&obj2.get());
    std::cerr << x.get().toString() << endl;
}

int main(int argc, char* argv[]) {
	test();
	return 0;
}