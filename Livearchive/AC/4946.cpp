#include<iostream>
#include<string>
#include <algorithm>

using namespace std;

int solve(const string& s){
  int n=s.size();
  int res=n-1;
  int change=0;

  for(int i=0;i<n;++i)
    change+=min(s[i]-'A', ('A'-s[i]+26)%26);

  if(change==0)
    return 0;
  
  int noneed=0;
  for(int i=0;i<n;++i){
    if(s[i]=='A' && i!=0)
      noneed++;
    else
      noneed=0;
    res=min(res, i-noneed+n-noneed-1);
  }

  return change+res;
}

int main(){
  int nbcase;
  cin >> nbcase;
  while(nbcase--){
    string s;
    cin >> s;
    int right=solve(s);
    reverse(s.begin()+1, s.end());
    int left=solve(s);
    cout << min(right, left) << '\n';
  }
}
