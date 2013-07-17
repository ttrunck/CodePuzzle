#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<sstream>

using namespace std;

vector<string> input;
vector<string> palin;
vector<string> compa;

bool ok(string s, string n){
  if(s.size()!=n.size()) return false;
  for(int i=0;i<s.size();++i)
    for(int j=i+1;j<s.size();++j)
      if(s[i]==s[j] && n[i]!=n[j]) return false;
  return true;
}

vector<string> square(string s){
  vector<string> res;
  int taille=1;
  for(int i=0;i<s.size();++i)
    taille*=10;
  for(int i=0;i*i<taille;++i)
    if(i*i>=taille/10){
      ostringstream out;
      out << i*i;
      string tmp=out.str();
      if(ok(tmp,s) && ok(s,tmp)) 
	res.push_back(tmp);
    }
  return res;
}

bool is_square(int n){
  int tmp=sqrt(n);
  // cout << n << ' ' << (tmp*tmp==n) << '\n';
  return tmp*tmp==n;
}

bool compatible(string s, string n, string c){
  int cal=0;
  for(int i=0;i<c.size();++i){
    int j=0;
    while(s[j]!=c[i])++j;
    if(i==0 && n[j]=='0') return false;
    cal=10*cal+n[j]-'0';
  }
  //  if(is_square(cal))
  //  cout << s << '\n' << n << '\n' << c << '\n' << cal << '\n';
  return is_square(cal);
}

string value(string s){
  string res="";
  vector<string> compat=square(s);
  for(int i=0;i<palin.size();++i){
    if(palin[i]==s) continue;
    string ss=s;
    string pal=palin[i];
    sort(ss.begin(),ss.end());
    sort(pal.begin(),pal.end());
    if(ss!=pal) continue;
    string candidat=palin[i];
    for(int j=0;j<compat.size();++j){
      string n=compat[j];
      if(compatible(s,n,candidat)) res=n;
    }
  }
  return res;
}

bool mem(int n, string s){
  sort(s.begin(),s.end());
  for(int i=0;i<compa.size();++i){
    if(i==n) continue;
    if(s==compa[i]) return true;
  }
  return false;
}

void init_palin(){
  for(int i=0;i<input.size();++i)
    if(mem(i,input[i])) palin.push_back(input[i]);
}

int convert(string s){
  int res=0;
  for(int i=0;i<s.size();++i)
    res=res*10+s[i]-'0';
  return res;
}

int main(){
  string tmp;
  while(cin >> tmp){
    //    if(tmp.size()!=8) continue;
    string copie=tmp;
    input.push_back(tmp);
    sort(copie.begin(),copie.end());
    compa.push_back(copie);
  }

  init_palin();
  /* 
  for(int i=0;i<palin.size();++i)
    cout << palin[i] << '\n';
  cout << palin.size() << '\n';
  */
  int res=0;
  for(int i=0;i<palin.size();++i){
    int tmp=convert(value(palin[i]));
      if(tmp>res) res=tmp;
  }
  cout << res << '\n';
}
