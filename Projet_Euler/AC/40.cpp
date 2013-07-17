#include <iostream>
#include <string>
#include <sstream>

using namespace std;



string s;
int main(){
  int i=0;
  while(s.size()<1000001){
    ostringstream oss;
    oss << i;
    s.append(oss.str());
    i++;
  }
  cout << (s[1]-'0')*(s[10]-'0')*(s[100]-'0')*(s[1000]-'0')* (s[10000]-'0')*(s[100000]-'0')*(s[1000000]-'0')<< '\n';
}
