#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <iostream>
#include <memory>
#include <string.h>
#include <string>
#include <sstream>
#include <functional>
namespace EC {
template<typename T>
class ReadOnlyProperty {
public:
	std::function<T()> get;
	operator T() {

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
	template<typename T>
	String(const T& other) {
		//Secret service
		std::stringstream ss;
		ss<<other;
		sval = other;
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
void Write(const T& val) {
	std::cout<<val;
}
template<typename T>
void WriteLine(const T& val) {
	std::cout<<val<<std::endl;
}
template<typename T>
void ReadLine(const T& output) {
	std::cin.getline(output,sizeof(output));
}
String ReadLine() {
	char mv[256];
	std::cin.getline(mv,256);
	return mv;
}

}
