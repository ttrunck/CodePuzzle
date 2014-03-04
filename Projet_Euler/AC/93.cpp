#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int t[4];

double f(int a,double b, double c){
  if(a==0) return b+c;
  if(a==1) return b-c;
  if(a==2) return b*c;
  if(c!=0) return b/c;
  return b+c;
}

bool is_int(double n){
  int tmp=n;
  return tmp==n;
}

int aux(){
  vector<int> res;
  sort(t, t+4);
  do{
    for(int i=0;i<4;++i)
      for(int j=0;j<4;++j)
	for(int k=0;k<4;++k){
	  double tmp;
	  tmp=(f(i,f(j,f(k,t[0],t[1]),t[2]),t[3]));
	  if(tmp>0 && is_int(tmp)) res.push_back(tmp);
	  tmp=(f(i,f(j,t[0],f(k,t[1],t[2])),t[3]));
	  if(tmp>0 && is_int(tmp)) res.push_back(tmp);
	  tmp=(f(i,f(j,t[0],t[1]),f(k,t[2],t[3])));
	  if(tmp>0 && is_int(tmp)) res.push_back(tmp);
	  tmp=(f(i,t[0],f(j,f(k,t[1],t[2]),t[3])));
	  if(tmp>0 && is_int(tmp)) res.push_back(tmp);
	  tmp=(f(i,t[0],f(j,t[1],f(k,t[2],t[3]))));
	  if(tmp>0 && is_int(tmp)) res.push_back(tmp);
	}
  }   while(next_permutation(t,t+4));
  sort(res.begin(), res.end());
  res.resize(unique(res.begin(),res.end())-res.begin());
  //for(int i=0;i<res.size();++i)
    //    cout << res[i] << ' ';
  int curr=0;
  for(int i=0;i<res.size();++i)
    if(res[i]==i+1) curr++;
  return curr;
}

int main(){
  int res;
  int maxi=0;
  for(int i=1;i<10;++i)
    for(int j=i+1;j<10;++j)
      for(int k=j+1;k<10;++k)
	for(int l=k+1;l<10;++l){
	  t[0]=i;
	  t[1]=j;
	  t[2]=k;
	  t[3]=l;
	  int tmp=aux();
	  if(tmp>maxi){
	    maxi=tmp;
	    res=l+10*k+100*j+1000*i;
	  }
	}
  cout << res << '\n';
}
