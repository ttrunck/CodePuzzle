#include<iostream>
#include<vector>

using namespace std;

vector<int> mem(4100, -1);


vector<bool> inttovec(int n){
  vector<bool> res(12,false);
  for(int i=11;i>=0;--i){
    res[i]=n%2;
    n/=2;
  }
  return res;
}

int vectoint(const vector<bool> & t){
  int res=0;
  for(int i=0;i<12;++i)
    res=res*2+t[i];
  return res;
}

int aux(int n){
  if(mem[n]!=-1) return mem[n];
  int res=0;
  vector<bool> t=inttovec(n);
  for(int i=0;i<12;++i)
    res+=t[i];

  for(int i=0;i<10;++i){
    if(t[i] && t[i+1] && !t[i+2]){
      t[i]=false;
      t[i+1]=false;
      t[i+2]=true;
      res=min(res, aux(vectoint(t)));
      t[i]=true;
      t[i+1]=true;
      t[i+2]=false;
    }
  }

 for(int i=11;i>=2;--i){
    if(t[i] && t[i-1] && !t[i-2]){
      t[i]=false;
      t[i-1]=false;
      t[i-2]=true;
      res=min(res, aux(vectoint(t)));
      t[i]=true;
      t[i-1]=true;
      t[i-2]=false;
    }
  }

  return mem[n]=res;
}

int main(){
  int cas;
  cin >> cas;
  while(cas--){
    int n=0;
    for(int i=0;i<12;++i){
      char tmp;
      cin >> tmp;
      n=n*2+(tmp=='o'?1:0);
    }
    cout << aux(n) << endl;
  }
}
