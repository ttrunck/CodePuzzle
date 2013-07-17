#include<iostream>
#include<string>

using namespace std;

int main(){
  string s1,s2;
  cin >> s1 >> s2;
  int res=0;
  for(int i=0;i<int(s1.size());++i)
    if(s1[i]!=s2[i])
      res++;
  cout << res << endl;
  
}
