#include<iostream>
#include<vector>

using namespace std;

int main(){
  string s;
  cin >> s;
  

  string ss;
  ss=s.substr(0,2);
  int i1=0,i2=1,i3=2;
  while(i3<int(s.size())){
    if(s[i3]==s[i2] && s[i3]==s[i1])
      ++i3;
    else{
      ss.push_back(s[i3]);
      i1=i2;
      i2=i3;
      ++i3;
    }
  }
  
  s=ss;
  ss.clear();
  ss=s.substr(0,3);
  i1=0,i2=1,i3=2;
  int i4=3;
  while(i4<int(s.size())){
    if(s[i4]==s[i3] && s[i2]==s[i1])
      ++i4;
    else{
      ss.push_back(s[i4]);
      i1=i2;
      i2=i3;
      i3=i4;
      ++i4;
    }
  }

  cout << ss << '\n';
}
