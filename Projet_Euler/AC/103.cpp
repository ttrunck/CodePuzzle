#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int const M=2;
int const N=12;

bool check(vector<int> t){
  int cas=1 << t.size();
  int mini[N];
  int maxi[N];
  vector<int> val;
  
  for(int i=0;i<t.size();++i){
    mini[i]=100000;
    maxi[i]=0;
  }

  for(int i=0;i<cas;++i){
    int nn=i;
    int taille=0;
    int tmp=0;
    for(int j=0;j<t.size();++j){
      if(nn%2==1){
	taille++;
	tmp+=t[j];
      }
      nn/=2;
    }
    mini[taille]=min(mini[taille], tmp);
    maxi[taille]=max(maxi[taille], tmp);
    val.push_back(tmp);
  }

  sort(val.begin(), val.end());
  for(int i=0;i<val.size()-1;++i)
    if(val[i]==val[i+1]) return false;
  for(int i=1;i<t.size();++i)
    if(mini[i]<=maxi[i-1]) return false;
  return true;
}

int sum(vector<int> t){
  int res=0;
  for(int i=0;i<t.size();++i)
    res+=t[i];
  return res;
}

void print(vector<int> t){
  for(int i=0;i<t.size();++i)
    cout << t[i];
  cout << endl;
}

int main(){
  vector<int> b;
  b.push_back(20);
  b.push_back(31);
  b.push_back(38);
  b.push_back(39);
  b.push_back(40);
  b.push_back(42);
  b.push_back(45);

  vector<int> t;
  for(int i=0;i<b.size();++i)
    t.push_back(b[i]);

  int best=256;
  
  for(int a1=-M;a1<M;++a1)
  for(int a2=-M;a2<M;++a2)
  for(int a3=-M;a3<M;++a3)
  for(int a4=-M;a4<M;++a4)
  for(int a5=-M;a5<M;++a5)
  for(int a6=-M;a6<M;++a6)
  for(int a7=-M;a7<M;++a7){
    t[1]=b[1]+a1;
    t[2]=b[2]+a2;
    t[3]=b[3]+a3;
    t[4]=b[4]+a4;
    t[5]=b[5]+a5;
    t[6]=b[6]+a6;
    t[7]=b[7]+a7;
      if(sum(t)<best && check(t)){
	print(t);
	best=sum(t);
      }
    }
}
