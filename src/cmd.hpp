#include <iostream>
#include <string>
#include <algorithm>

int exit(std::vector<std::string> **args){
	exit(1);
	return 0;
}

int bar(std::vector<std::string> **args){
	std::cout << "bar" << std::endl;
	return 1;
}
int foo(std::vector<std::string> **args){
	std::cout << "foo" << std::endl;
	return 1;
}

int (*func[])(std::vector<std::string> **) = {
	&bar,
	&foo,
	&exit
};
const char *func_names[] = {
	"foo",
	"bar",
	"exit"
};
