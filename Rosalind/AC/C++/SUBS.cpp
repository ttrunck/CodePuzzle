#include<iostream>
#include<string>

using namespace std;

int main(){
  string s,t;
  cin >> s >> t;
  int pos=0;
  while(true){
    pos=s.find(t,pos);
    if(pos==-1) break;
    cout << pos+1 << ' ';
    pos++;
  }
  cout << endl;
}
