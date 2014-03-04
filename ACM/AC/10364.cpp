#include<iostream>
#include<vector>

using namespace std;

int nn, sumsum;

bool aux(int n, int sum, int etat, const vector<int> & t, vector<vector<bool> > & mem){
  if(etat==4) return true;
  if(sum<0) return false;
  if(n==-1 && sum!=0) return false; 
  if(sum==0) return aux(nn-1, sumsum, etat+1, t, mem);
  
  bool pos=true;
  for(int i=0;i<etat;++i)
    pos=pos&&!mem[n][i];

  bool res=aux(n-1, sum, etat, t, mem);
  if(pos){
    mem[n][etat]=true;
    res=res||aux(n-1,sum-t[n],etat,t,mem);
    mem[n][etat]=false;
  }
  return res;
}

int main(){

  int cas;
  cin >> cas;
  while(cas--){
    int n;
    cin >> n;
    vector<int> t(n);
    int sum=0;
    for(int i=0;i<n;++i){
      cin >> t[i];
      sum+=t[i];
    }
    
    if(sum%4!=0)
      cout << "no" << endl;
    else{
      vector<vector<bool> > mem(n+1, vector<bool>(4,false));
      nn=n;
      sumsum=sum/4;
      if(aux(n-1, sum/4, 0, t, mem))
	cout << "yes" << endl;
      else
	cout << "no" << endl;
    }
  }
}
