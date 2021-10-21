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
#include "cmd.hpp"

std::vector<std::string> split_line(std::string s){ 
	std::string tmp;
	std::stringstream ss(s);
	std::vector<std::string> vwords;
	while (getline(ss,tmp,' ')){
		vwords.push_back(tmp);
	}
	return vwords;
}	

std::vector<std::string> read_cin(){
	std::string c;
	std::getline(std::cin,c);
	std::vector<std::string> sc = split_line(c);
	return sc;
}

int igsh_main(){
	typedef int igsh_func(std::vector<std::string>);
	std::cout << ">>";
	std::vector<std::string> cmd = read_cin();

	std::string tocall = cmd[0];
	std::vector<std::string> args = std::vector<std::string>(cmd.begin() + 1, cmd.end());

	int pos = std::distance(func_names, std::find(func_names, func_names + 3, tocall));
	
	igsh* f = (igsh*)func[pos];
	
	f(args);
	
	return 0;
}
