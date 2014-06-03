#include "EC.h"
//Linux sample application.
using namespace EC;



int main(int argc, char** argv){
	 String s;
	 s<<"Hello"<<" "<<"world"<<"!";
	 WriteLine(s);
	 
	 
	 String mint = "5";
	 int val;
	 mint>>val;
	 WriteLine(val);
	return 0;
}
