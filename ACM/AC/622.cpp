#include<iostream>
#include<vector>
#include<string>
#include<cassert>

using namespace std;

int expr(const string &, int &);
int factor(const string &, int &, int);
int add(const string &, int &, int);
int term(const string &, int &);


int expr(const string & s, int & pos){
  int res=term(s, pos);
  res=factor(s, pos, res);
  res=add(s, pos, res);
  return res;
}

int factor(const string & s, int & pos, int acc){
  if(s[pos]=='*'){
    pos++;
    acc*=term(s, pos);
    return factor(s, pos, acc);
  }
  else if(s[pos]=='/'){
    pos++;
    acc/=term(s, pos);
    return factor(s, pos, acc);
  }
  else
    return acc;
}

int add(const string & s, int & pos, int acc){
  if(s[pos]=='+'){
    pos++;
    return acc+expr(s, pos);
  }
  else if(s[pos]=='-'){
    pos++;
    return acc-expr(s, pos);
  }
  else
    return acc;
}

int term(const string & s, int & pos){
  if(isdigit(s[pos])){
    int res=0;
    while(isdigit(s[pos])){
      res=10*res+s[pos++]-'0';
    }
    return res;
  }
  else if(s[pos]=='('){
    pos++;
    int res=expr(s, pos);
    assert(s[pos]==')');
    pos++;
    return res;
  }
  throw string("Houston we have a problem!");
}

int main(){
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  cin.ignore();
  for(int i=0;i<n;++i){
    string s;
    int pos=0;
    getline(cin, s);
    try{
      int res=expr(s, pos);
      if(pos==int(s.size()))
	cout << res << '\n';
      else
	cout << "ERROR\n";
    }
    catch ( ... ){
      cout << "ERROR\n";
    }
  }
  
}
