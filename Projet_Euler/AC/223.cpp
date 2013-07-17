#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ent;

const ent N=2500000;

void divisor(ent a, vector<ent> & t){
  vector<ent> t1;
  for(ent d=1;d*d<=a-1;++d)
    if((a-1)%d==0){
      t1.push_back(d);
      t1.push_back((a-1)/d);
    }
  vector<ent> t2;
  for(ent d=1;d*d<=a+1;++d)
    if((a+1)%d==0){
      t2.push_back(d);
      t2.push_back((a+1)/d);
    }

  for(int i=0;i<int(t1.size());++i)
    for(int j=0;j<int(t2.size());++j)
      if(t1[i]*t2[j]<=a)
	t.push_back(t1[i]*t2[j]);

  sort(t.begin(), t.end());
  t.resize(unique(t.begin(), t.end())-t.begin());
}

int main(){
  ent res=(N-1)/2;
  for(ent a=2;a<=N/3;++a){
    vector<ent> div;
    divisor(a,div);
    for(auto d=div.begin();d!=div.end();++d){
      ent f1=(a-1)*(a+1)/ *d;
      ent f2= *d;
      if((f1+f2)%2!=0)
	continue;
      ent b=(f1-f2)/2, c=(f1+f2)/2;
      if(a<=b && a+b+c<=N){
	//cerr << a << ' ' << b << ' ' << c << endl;
	++res;
      }
    }
  }
  cout << res << endl;
}
