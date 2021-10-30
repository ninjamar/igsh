#include <iostream>
#include <string>
#include <algorithm>

// this command exits the program

int exit(std::vector<std::string> **args){
	exit(1);
	return 0;
}

// prints bar to the screen
int bar(std::vector<std::string> **args){
	std::cout << "bar" << std::endl;
	return 1;
}

// prints foo to the screen
int foo(std::vector<std::string> **args){
	std::cout << "foo" << std::endl;
	return 1;
}

// this holds the memory addresses of the functions above
int (*func[])(std::vector<std::string> **) = {
	&bar,
	&foo,
	&exit
};

// this holds the names of the functions in relation to their position inside func
const char *func_names[] = {
	"foo",
	"bar",
	"exit"
};
