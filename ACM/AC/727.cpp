#include<iostream>
#include<stack>
#include<cctype>
#include<string>
#include<cstdio>
#include<cstdlib>

using namespace std;

int prio(char c){
  if(c=='+') return 1;
  else if(c=='-') return 1;
  else if(c=='*') return 2;
  else if(c=='/') return 2;
  else if(c=='(') return 0;
  cerr << "Houston we have a problem with " << c << endl;
  return -1;
}

string convert(const string & s){
  string res;
  stack<char> p;
  for(int i=0;i<s.size();++i){
    if(isdigit(s[i]))
      res.push_back(s[i]);
    else if(s[i]=='(')
      p.push('(');
    else if(s[i]==')'){
      while(p.top()!='('){
	res.push_back(p.top());
	p.pop();
      }
      p.pop();
    }
    else{
      while(!p.empty() && prio(p.top())>=prio(s[i])){
	res.push_back(p.top());
	p.pop();
      }
      p.push(s[i]);
    }
  }
  while(!p.empty()){
    res.push_back(p.top());
    p.pop();
  }

  return res;
}

int main(){
  int cas;
  cin >> cas;
  cin.ignore();
  cin.ignore();
  for(int icas=0;icas<cas;++icas){
    string s;
    char c=getchar();
    while (c!='\n' && c!= EOF){
      s.push_back(c);
      c=getchar();
      c=getchar();
    }

    if(icas>0)
      cout << endl;
    cout << convert(s) << endl;

  }
}
