/**********************************************
Made by @ninjamar (https://github.com/ninjamar)

-----------------------------------------------
split_line(s) -> std::vector<std::string>{
	split s into different strings by whitespace

}
read_cin() -> std::vector<std::string>{
	read data from cin until newline and split whitespace by using "split_line"
}
igsh_main() -> int{
	main function of code
}
-----------------------------------------------
***********************************************/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "cmd.hpp" // all the commands are in cmd.hpp


// split string by newlines into a vector
std::vector<std::string> split_line(std::string s){ 
	std::string tmp;
	std::stringstream ss(s);
	std::vector<std::string> vwords;
	while (getline(ss,tmp,' ')){
		vwords.push_back(tmp);
	}
	return vwords;
}	
// read input from cin then split it
std::vector<std::string> read_cin(){
	std::string c;
	std::getline(std::cin,c);
	std::vector<std::string> sc = split_line(c);
	return sc;
}

// main function + executes one run of reading input + output

int igsh_main(){
	typedef int igsh_func(std::vector<std::string>); // the function type 
	std::cout << ">>"; // prompt
	std::vector<std::string> cmd = read_cin(); // read from cin + split 

	std::string call = cmd[0]; // get the first value in cmd which is the function we are calling
	
	std::vector<std::string> args = std::vector<std::string>(cmd.begin() + 1, cmd.end()); // a slice like cmd[1:] so we can get the arguments

	int pos = std::distance(func_names, std::find(func_names, func_names + 3, call)); // get the index of the function (call) inside func_names (cmd.hpp)
	
	igsh_func* f = (igsh_func*)func[pos]; // create the function from the memory address stored inside func (cmd.hpp)
	
	f(args); // call the function that we made
	
	return 0;
}
