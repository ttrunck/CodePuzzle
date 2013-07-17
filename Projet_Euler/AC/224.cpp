#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
//#include<omp.h>

using namespace std;

typedef long long ent;

const ent N=750000;

void divisor2(ent a, vector<ent> & t){
  for(ent d=1;d<a+1;++d)
    if((a*a+1)%d==0)
      t.push_back(d);
}

int main(){
  ent res=0;
  ent NN=N/(2+sqrt(2));
#pragma omp parallel for reduction(+:res)
  for(ent a=2;a<=NN;++a){
    vector<ent> div;
    divisor2(a,div);
    for(vector<ent>::iterator d=div.begin();d!=div.end();++d){
      ent f1=(a*a+1)/ *d;
      ent f2= *d;
      if((f1+f2)%2!=0)
	continue;
      ent b=(f1-f2)/2, c=(f1+f2)/2;
      if(a<=b && a+b+c<=N){
	//	cerr << a << ' ' << b << ' ' << c << endl;
	++res;
      }
    }
  }
  cout << res << endl;
}
