#include<iostream>
#include<string>

using namespace std;

bool aux(string & a, string & b){
  int a1=0,b1=0;
  while(a1<a.size()){
    if(b1>=b.size()) return false;
    if(a[a1]==b[b1]){
      a1++;
      b1++;
    }
    else
      b1++;
  }
  return true;
}

int main(){
  string a,b;
  while(cin >> a >> b)
    if(aux(a,b))
      cout << "Yes" << endl;
    else
      cout << "No" << endl;

}
