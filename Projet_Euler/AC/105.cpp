#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int const N=13;

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

int main(){
  int res=0;
  for(int i=0;i<100;++i){
  vector<int> t;
  int tmp;
  cin >> tmp;
  while(tmp!=0){
    t.push_back(tmp);
    cin >> tmp;
  }
  if(check(t))
    res+=sum(t);
  }
  cout << res << endl;
}
