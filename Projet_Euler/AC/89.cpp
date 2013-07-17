#include<iostream>
#include<string>

using namespace std;

int cconvert(char c){
  if(c=='I') return 1;
  if(c=='V') return 5;
  if(c=='X') return 10;
  if(c=='L') return 50;
  if(c=='C') return 100;
  if(c=='D') return 500;
  if(c=='M') return 1000;
  cout << "Erreur de conversion cconvert\n";
  return -1;
}

int sconvert(string s){
  int res=0;
  for(int i=0;i<s.size()-1;++i){
    if(cconvert(s[i])>=cconvert(s[i+1]))
      res+=cconvert(s[i]);
    else res-=cconvert(s[i]);
  }
  res+=cconvert(s[s.size()-1]);
  return res;
}

string rconvert(int n, string s){
  if(n>=1000){
    s.push_back('M');
    s=rconvert(n-1000,s);
  }
else if(n>=900){
    s.push_back('C');
    s.push_back('M');
    s=rconvert(n-900,s);
  }
else if(n>=500){
    s.push_back('D');
    s=rconvert(n-500,s);
  }
else if(n>=400){
    s.push_back('C');
    s.push_back('D');
    s=rconvert(n-400,s);
  }
else if(n>=100){
    s.push_back('C');
    s=rconvert(n-100,s);
  }
else if(n>=90){
    s.push_back('X');
    s.push_back('C');
    s=rconvert(n-90,s);
  }
else if(n>=50){
    s.push_back('L');
    s=rconvert(n-50,s);
  }
else if(n>=40){
    s.push_back('X');
    s.push_back('L');
    s=rconvert(n-40,s);
  }
else if(n>=10){
    s.push_back('X');
    s=rconvert(n-10,s);
  }
  else if(n>=9){
    s.push_back('I');
    s.push_back('X');
    s=rconvert(n-9,s);
  }
  else if(n>=5){
    s.push_back('V');
    s=rconvert(n-5,s);
  }
  else if(n>=4){
    s.push_back('I');
    s.push_back('V');
    s=rconvert(n-4,s);
  }
  else if(n>=1){
    s.push_back('I');
    s=rconvert(n-1,s);
  }
 return s;
}

int main(){
  int res=0;
  string s;
  while(cin >> s){
    res+=s.size();
    int n=sconvert(s);
    s=rconvert(n, "");
    res-=s.size();
  }
  cout << res << '\n';
}
