#include "EC.h"
//Linux sample application.
using namespace EC;



int main(int argc, char** argv){
	String strong = "hello world";
	strong[0] = 2;
	WriteLine(strong);
	return 0;
}
