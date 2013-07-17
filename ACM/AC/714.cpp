#include<iostream>
#include<vector>
#include<cmath>
#include<limits>

typedef long long ent;

using namespace std;

ent aux(int b, int s, const vector<int> & t, vector<vector<ent> > & mem, const vector<ent> & sum){    
  if(mem[b][s]!=-1) return mem[b][s];
  ent res;
  if(s==1){
    res=0;
    for(int i=0;i<=b;++i)
      res+=t[i];
  }
  else{
    res=numeric_limits<ent>::max();
  for(int i=0; i<b;++i){
    ent tmp=0;
    tmp=sum[b]-sum[i];
    /*
    for(int j=i+1;j<=b;++j)
      tmp+=t[j];
    */ 
    res=min(res,max(aux(i,s-1,t,mem,sum),tmp)); 
  }
  }
  mem[b][s]=res;
  return res;
}

int main(){
  int cas;
  cin >> cas;
  while(cas--){
    int b, s;
    cin >> b >> s;
    vector<int> t(b);
    for(int i=0;i<b;++i)
      cin >> t[i];

    vector<vector<ent> > mem(b+1,vector<ent>(s+1,-1));
    vector<ent> sum(b);
    sum[0]=t[0];
    for(int i=1;i<b;++i)
      sum[i]=sum[i-1]+t[i];

    ent val=aux(b-1,s,t,mem,sum);
 
    vector<vector<int> > print(s);

    int ind=b-1;
    for(int src=s-1;src>=0;src--){
      int curr=0;
      while(curr+t[ind]<=val && ind>=src){
	curr+=t[ind];
	print[src].push_back(t[ind]);
	ind--;
      }
    }

    for(int i=0;i<s;++i){
      cout << print[i][int(print[i].size()-1)];
      for(int j=int(print[i].size())-2;j>=0;--j)
	cout << ' ' << print[i][j];
      if(i!=s-1)
	cout << " / ";
    }
    cout << endl;
    
 }
}
