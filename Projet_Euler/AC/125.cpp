#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int const START=10000;
int const N=100000000;

vector<int> p;

string int_to_string(int n){
  stringstream out;
  out << n;
  return out.str();
}

bool palindrome(int n){
  string s=int_to_string(n);
  for(int i=0;i<s.size();++i)
    if(s[i]!=s[s.size()-1-i]) return false;
  return true;
}

int main(){
  for(int s=1;s<START;++s){
    int tmp=s*s;
    for(int t=1;tmp<N;++t){
      tmp+=(s+t)*(s+t);
      if(tmp<N && palindrome(tmp)){
	p.push_back(tmp);
      }
    }
  }
  long long res=0;
  sort(p.begin(), p.end());
  p.resize(unique(p.begin(),p.end())-p.begin());
  for(int i=0;i<p.size();++i)
    res+=p[i];
  cout << res << '\n';
}
