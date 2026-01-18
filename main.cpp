#include <iostream>
#include <string>
#include <vector>
#include <sstream>

std::string output;

int main(){
  std::string line;
  while(true){ 
    std::cout << "> ";
    std::getline(std::cin, line);
    if(line == "run"){
      break;
    }
    convert(line);
  }
    
  std::cout << "Output: " << output;
  return 0;
}
void convert(std::string line){
  //TODO
}
