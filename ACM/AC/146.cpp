#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string const S="#";

int main(){
  string s;
  cin >> s;
  while(s!=S){
    if(next_permutation(s.begin(),s.end()))
      cout << s << endl;
    else
      cout << "No Successor" << endl;
    cin >> s;
  }
}
