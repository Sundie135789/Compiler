#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <cctype>
#include <array>
//TODO change tokenize function for dynamic syntax and efficieny, then handle logic later.
//TODO: at line 127, add error. because in that case its neither variable name nor a string literal.
class variable{
  public:
    
    int intValue;
    std::string strValue;
    std::string type,name;
    variable(std::string type, int iVal, std::string strVal, std::string name) : strValue(strVal), intValue(iVal), name(name), type(type) {}
};
std::vector keywords = {
  "int",
  "string",
  "print"
};
std::vector<variable> variables;
std::string output = "";
std::string assembly;
int offset = 4, lineNo = 1;
void createInt(std::vector<std::string> tokens, int lineNo){
  if(tokens.size() != 4){
    output += "Error at line " + std::to_string(lineNo) + " : Invalid syntax in INT declaration\n";
    return;
  }
  if(tokens[2] != "="){
    output += "Error at line " + std::to_string(lineNo) + " : Invalid syntax in INT declaration\n";
    return;
  }
  if(tokens[3] == ""){
    output += "Error at line " + std::to_string(lineNo) + " : Invalid value in INT declaration\n";
    return;
  }
  int val;
  try{
  tokens[3].pop_back();
  val = std::stoi(tokens[3]);
  }catch(const std::invalid_argument& e){
    output += "Error at line " + std::to_string(lineNo) + " : Invalid value in INT declaration\n";
    return;
  }catch(const std::out_of_range& e){
    output += "Error at line " + std::to_string(lineNo) + " : Value surpassed limit of 2^32 in INT declaration (See github documentation for details)\n";
    return;
  }
  variable var = variable("int",val,"",tokens[1]);
  variables.push_back(var);
}
const std::string* findKeyword(std::vector<std::string>& vec,std::string& target){
  auto it = std::find(vec.begin(),vec.end(),target);
  if (it != vec.end()) return &(*it);
  else return nullptr;
}
std::vector<std::string> tokenize(std::string line){
 // efficient syntax tokenizer
 // example string: int a = 10;
  std::vector<std::string> tokens;
  std::string curWord;
  for(int i=0; i<line.length();i++){
    if(std::isalpha(line.at(i))){
      curWord += line.at(i);
    if(findKeyword(keywords, curWord) != nullptr){
            
    }
  }
}
  return tokens;
} 
void error(std::string str, int lineNo){
  output += "Error at line " + std::to_string(lineNo) + str;
  return;
}
variable* findVariable(std::string name){
  for(int i =0 ;i<variables.size();i++){
    if(variables.at(i).name == name){
      return &variables.at(i);
    }
  }
  return nullptr;
}

void createString(std::vector<std::string> tokens, int lineNo){
  if(tokens.size() != 4){
    error("Invalid syntax in String declaration\n", lineNo);
    return;
  }
  if(tokens[1].front() != '\"'){
    // if it is not a quotation mark, then try variable name.
    variable* found = findVariable(tokens[2]);
    if(found == nullptr){
      //TODO
    }
  }
}

void interpret(std::string line, int lineNo){
  std::vector<std::string> tokens = tokenize(line);
  if(tokens[tokens.size()-1].back() != ';'){
    output += "Error at line " + std::to_string(lineNo) + " : Expected \';\' at the end of line\n";
    return;
  }
  if(tokens[0] == "int"){
    createInt(tokens, lineNo);
  }if (tokens[1] == "string"){
    createString(tokens, lineNo);
  }
  lineNo++;
}

int main(){
  std::string line;
  while(true){ 
    std::cout << "> ";
    std::getline(std::cin, line);
    if(line == "ret"){
      break;
    }
    interpret(line, lineNo);
  }
  if(output == "") output = "No Output";
  std::cout << "Output: " << output;
  return 0;
}

