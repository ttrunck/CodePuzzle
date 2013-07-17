#include<iostream>
#include<string>
#include<cmath>

using namespace std;

bool is_triangle[300];

int main(){
  for(int i=0;i<300;++i) is_triangle[i]=false;
  for(int i=0;i<20;++i)
    is_triangle[i*(i+1)/2]=true;
  string s;
  int res=0;
  while(cin >> s){
    int w_value=0;
    for(int i=0;i<s.size();++i)
      w_value+=s[i]-'A'+1;
    if(is_triangle[w_value]) res++;
  }
  cout << res << '\n';
}
