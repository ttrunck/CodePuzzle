#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

vector<int> fib;
vector<int> t;
string s;

int nfib(int f){
  int i=0;
  while(i<fib.size() && fib[i]!=f)
    i++;
  if(i==fib.size())
    return -1;
  else return i;
}

int nchar(int n){
  int comp=0;
  for(int i=0;i<s.size();++i)
    if(isupper(s[i])){
      if(comp==n) return s[i];
      comp++;
    }
  return 'a';
}

int main(){
  fib.push_back(1);
  fib.push_back(2);
  while(fib[fib.size()-2]+fib[fib.size()-1]>0)
    fib.push_back(fib[fib.size()-2]+fib[fib.size()-1]);

  int cas;
  cin >> cas;
  while(cas--){
    t.clear();
    int n;
    cin >> n;
    int maxi=0;
    for(int i=0;i<n;++i){
      int tmp;
      cin >> tmp;
      maxi=max(maxi, nfib(tmp));
      t.push_back(tmp);
    }
    cin.ignore();
    getline(cin, s);
    
    string res(maxi+1,' ');
    
    //  cout << maxi << ' ' << s << endl;

    for(int i=0;i<n;++i)
      res[nfib(t[i])]=nchar(i);

    cout << res << endl;
  }
}
