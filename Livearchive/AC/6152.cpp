#include<iostream>
#include<string>

using namespace std;

int count(const string & s){
  int res=0;
  for(int i=0;i<int(s.size());++i)
    if(s[i]=='0'||s[i]=='?')
      res++;
  return res;
}

int main(){
  int cas;
  cin >> cas;
  for(int icase=1;icase<=cas;++icase){
    cout << "Case " << icase << ": ";
    string S,T;
    cin >> S >> T;
    int tcount=count(T), scount=count(S);
    if(tcount>scount || T.size()!=S.size()){
      cout << "-1\n";
      continue;
    }
    int res=0;
    int size=S.size();
    int droit=scount-tcount;
    for(int i=0;i<size;++i)
      if(S[i]=='?' && T[i]=='1' && droit>0){
	S[i]='1';
	droit--;
	res++;
      }
    if(droit==0){
      for(int i=0;i<size;++i)
	if(S[i]=='?'){
	  S[i]='0';
	  res++;
	}
    }
    else{
      for(int i=0;i<size;++i)
	if(S[i]=='?'){
	  S[i]='0';
	  res++;
	}
      for(int i=0;i<size;++i)
	if(S[i]=='0' && T[i]=='1' && droit>0){
	  S[i]='1';
	  droit--;
	  res++;
	}
    }
  
    int tmp=0;
    for(int i=0;i<size;++i)
      if(S[i]!=T[i])
	tmp++;
      
    res+=tmp/2;
    cout << res << '\n';
  }
}
