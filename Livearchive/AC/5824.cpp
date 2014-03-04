#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int n, m, pos, var;

int compute(const string & s, const vector<int> & t){
  if(s[pos]=='('){
    pos++;
    int a=compute(s,t);
    char op=s[pos];
    pos++;
    int b=compute(s,t);
    pos++;
    if(op=='+') return a+b;
    else if(op=='-') return a-b;
    else return a*b;
  }
  else{
    var++;
    pos++;
    return t[var-1];
  }
}

int main(){
  while(cin >> n && n>0){
    vector<int> t(n);
    for(int i=0;i<n;++i)
      cin >> t[i];
    cin >> m;
    sort(t.begin(), t.end());
    string s;
    cin >> s;
    bool res=false;
    do{
      pos=0;
      var=0;
      res=res||compute(s,t)==m;
    }while(next_permutation(t.begin(), t.end()) && !res);
    if(res) cout << "YES\n";
    else cout << "NO\n";
  }
}
