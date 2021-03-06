#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <iostream>
#include <memory>
#include <string.h>
#include <string>
#include <sstream>
#include <functional>
#define var auto
namespace EC {
template<typename T>
class ReadOnlyProperty {
public:
	std::function<T()> get;
	operator T() {
return get();
	}
};
class String {
private:
	std::string sval;
	void Initialize() {
		length.get = [this]() {
			return sval.size();
		};
	}
public:
	String() {
	}
	String(const std::string& other) {
		sval = other;
	}
	String operator+(const String& other) {
	  return String(sval+other.sval);
	}
	String& operator+=(const String& other) {
	  sval+=other.sval;
	  return *this;
	}
	String& operator<<(const String& other){
	  sval+=other.sval;
	  return *this;
	}
	template<typename T>
	void operator>>(T& val) {
	  //Top secret service
	  std::stringstream tss;
	  tss<<sval;
	  tss>>val;
	}
	template<typename T>
	String(const T& other) {
		//Secret service
		std::stringstream ss;
		ss<<other;
		sval = ss.str();
	}
	const char& operator[](size_t idx) const {
		return sval[idx];
	}
	char& operator[](size_t idx) {
		return sval[idx];
	}
	operator std::string() const {
		return sval;
	}
	ReadOnlyProperty<size_t> length;
	template<typename T>
	operator T() const {
		//REALLY secret service!
		std::stringstream rss;
		rss<<sval;
		T rval;
		rss>>rval;
		return rval;
	}
};
void Write(const String& val) {
	std::string ms = val;
	std::cout<<ms;
}
void WriteLine(const String& val) {
	std::string ms = val;
	std::cout<<ms<<std::endl;
}


template<typename T>
void Parse(const String& val, T& output) {
	output = val;
}
template<typename T, typename Y>
void ToString(const T& input, Y& output) {
	String m = input;
	std::string mem = m;
	memcpy(output,mem.data(),mem.size()+1);
}

template<typename T>
void Write(const T& val) {
	std::cout<<val;
}
template<typename T>
void WriteLine(const T& val) {
	std::cout<<val<<std::endl;
}
template<typename T>
void ReadLine(T& output) {
	std::cin.getline(output,sizeof(output));
}
String ReadLine() {
	char mv[256];
	std::cin.getline(mv,256);
	return mv;
}

}
