#include<iostream>
#include<vector>
#include<set>

using namespace std;

typedef long long ent;

const int N=10;

set<int> ok;
vector<vector<ent> > mem((1<<(2*N)), vector<ent>(N, -1));

inline int myget(const int & n, const int nb, const int taille=4){
  return (n>>(nb*taille/2))%taille;
}

inline void myset(int & n, const int nb, const int val, const int taille=4){
  n|=val<<(nb*taille/2);
}

bool is_ok(int n){
  int curr=0; 
  for(int i=0;i<N;++i){
    int dir=myget(n,i);
    if(dir==0){
      if(i==0 || myget(curr,i-1,2) || myget(n,i-1)==2)
	return false;
      myset(curr, i-1, 1, 2);
    }
    else if(dir==2){
      if(i==N-1 || myget(curr,i+1,2) || myget(n,i+1)==0)
	return false;
      myset(curr, i+1, 1, 2);
    }
  }
  return true;
}

bool last(int curr_dir){
  for(int i=0;i<N;++i)
    if(myget(curr_dir,i, 4)==3)
      return false;
  return true;
}

bool val(int curr_dir, int prev, int & curr){
  int state=0;
  curr=0;
  for(int i=0;i<N;++i)
    if(myget(prev,i,4)==1 && myget(curr_dir, i, 4)!=1)
      return false;
  for(int i=0;i<N;++i)
    if(myget(prev,i,4)!=1 && myget(curr_dir, i, 4)==1)
      return false;

  for(int i=0;i<N;++i)
    if(myget(prev, i, 4)==2)
      myset(state, i, 1, 2);
  
   for(int i=0;i<N;++i){
    int dir=myget(curr_dir,i);
    if(dir==0){
      if(myget(state,i-1,2))
	return false;
      myset(state, i-1, 1, 2);
    }
    else if(dir==2){
      if(myget(state,i+1,2))
	return false;
      myset(state, i+1, 1, 2);
    }
   }

   for(int i=0;i<N;++i)
     if(myget(curr_dir,i,4)==3 && myget(state, i, 2)==0)
       return false;

   for(int i=0;i<N;++i)
     if(myget(curr_dir, i, 4)==3)
       curr|=2<<(i*2);
     else if(myget(state, i, 2)==0)
       curr|=1<<(i*2);

  return true;
}

ent aux(int prev, int ligne){
  if(mem[prev][ligne]!=-1) return mem[prev][ligne];
 
  int tmp;
  ent res=0;
  if(ligne==0){
    for(auto it=ok.begin();it!=ok.end();++it)
      if(val(*it, prev, tmp) && last(*it))
	res++;
  }
  else{
    for(auto it=ok.begin();it!=ok.end();++it)
      if(val(*it, prev, tmp))
	res+=aux(tmp, ligne-1);
  }
  mem[prev][ligne]=res;
  return res;
}



int main(){
  for(int i=0;i<(1<<(2*N));++i)
    if(is_ok(i))
      ok.insert(i);

  cerr << ok.size() << endl;
  cout << aux(0,N-1) << '\n';

}
