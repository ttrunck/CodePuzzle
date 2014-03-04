#include<iostream>
#include<set>

using namespace std;

int add(int n){
  int res=0;
  while(n!=0){
    res+=(n%10)*(n%10);
    n/=10;
  }
  return res;
}

bool happy(int n){
  set<int> s;
  while(s.find(n)==s.end()){
    if(n==1) return true;
    s.insert(n);
    n=add(n);
  }
  return false;
}

int main(){
  int icase;
  cin >> icase;
  for(int i=1;i<=icase;++i){
    cout << "Case #" << i << ": ";
    int tmp;
    cin >> tmp;
    if(happy(tmp))
      cout << tmp << " is a Happy number.\n";
    else
      cout << tmp << " is an Unhappy number.\n";
  }
}
