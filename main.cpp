#include <iostream>
#include <string>
#include <vector>
#include <sstream>

std::string output;
std::string* vecToArr(const std::vector<std::string>& v){
  std::string* arr = new std::string[v.size()];
  for(size_t i = 0;i < v.size();i++){
    arr[i] = v[i];
  }
  return arr;
}
std::vector<std::string> tokenize(std::string line){
  std::stringstream ss(line);
  std::string word;
  std::vector<std::string> tokens;
  while(ss >> word){
    tokens.push_back(word);
  }
  return tokens;
} 
void convert(std::string line){
  
}

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
