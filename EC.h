#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <iostream>
#include <memory>
#include <string.h>
#include <string>
#include <sstream>

namespace EC {

class String {
private:
	std::string sval;
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
	template<typename T>
	operator T() {
		//REALLY secret service!
		std::stringstream rss;
		rss<<sval;
		T rval;
		rss>>rval;
		return rval;
	}
};

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
