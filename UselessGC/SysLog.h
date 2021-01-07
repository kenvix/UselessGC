#pragma once
#include <iostream>
#include <string>

using std::string;
using std::bad_alloc;
using std::size_t;
using std::cerr;
using std::endl;

class SysLog
{
private:
	string name;
public:
	SysLog(const string& name);
	
	template <typename T1>
	inline void debug(const T1& m1) {
		cerr << "[" << name << "] " << m1 << endl;
	}

	template <typename T1, typename T2>
	inline void debug(const T1& m1, const T2& m2) {
		cerr << "[" << name << "] " << m1 << m2 << endl;
	}

	template <typename T1, typename T2, typename T3>
	inline void debug(const T1& m1, const T2& m2, const T3& m3) {
		cerr << "[" << name << "] " << m1 << m2 << m3 << endl;
	}

	template <typename T1, typename T2, typename T3, typename T4>
	inline void debug(const T1& m1, const T2& m2, const T3& m3, const T4& m4) {
		cerr << "[" << name << "] " << m1 << m2 << m3 << m4 << endl;
	}
};

