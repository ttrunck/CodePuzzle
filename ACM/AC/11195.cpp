#include<iostream>
#include<string>
#include<vector>

using namespace std;

void backtrack(int s, int n, const vector<int>& t, int& res, int dispo, int usedl, int usedr){
  if(s==n){
    ++res;
    return;
  }

  usedl<<=1;
  usedr>>=1;

  int set=dispo&t[s];
  while(set){
    int tmp=set&(set-1);
    int pos=set-tmp;
    set=tmp;
    if(!(pos&(usedr|usedl)))
      backtrack(s+1,n,t,res,dispo^pos, usedl|pos, usedr|pos);
  }
}

int main(){
  int icase=1;
  int n;
  while(cin >> n && n){
    cout << "Case " << icase++ << ": ";
    vector<int> t(n);
    cin.ignore();
    for(int i=0;i<n;++i){
      string s;
      getline(cin,s);
      for(int j=0;j<n;++j)
	if(s[j]=='.')
	  t[i]|=1<<j;
    }

    int res=0;
    backtrack(0, n, t, res, (1<<n)-1, 0, 0);
    cout << res << '\n';

  }
}
