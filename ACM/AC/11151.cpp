#include<iostream>
#include<string>
#include<cmath>

using namespace std;

string s;
int m[1001][1001];

int calcul(int d, int f){
  if(m[d][f]!=-1) return m[d][f];
  if(d>f) return 0;
  if(d==f) return 1;
  int res=0;
  if(s[d]==s[f])
    res=max(res, calcul(d+1,f-1)+2);
  res=max(res,calcul(d+1,f));
  res=max(res,calcul(d,f-1));
  m[d][f]=res;
  return res;
}

int main(){
  int cas;
  cin >> cas;
  cin.ignore();
  while(cas--){
    getline(cin, s);
    for(int i=0;i<s.size();++i)
      for(int j=0;j<s.size();++j)
	m[i][j]=-1;
    int res=calcul(0,s.size()-1);
    cout << res << endl;
  }
}
