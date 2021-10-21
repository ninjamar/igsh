#include <iostream>
#include <string>
#include <algorithm>


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
	&foo
};
const char *func_names[] = {
	"foo",
	"bar"
};
