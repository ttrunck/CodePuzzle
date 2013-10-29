#include<iostream>
#include<set>
#include<map>

//angles ATB is 120

using namespace std;

typedef pair<int, int> pi;
typedef long long ll;

const int N=120000;

int gcd(int a, int b){
  return b?gcd(b,a%b):a;
}

int main(){
  map<int, set<int> > s;
  for (int u=1;u*u<=N;u++){
    for (int v=1;v<u;v++){
      if(gcd(u,v)!=1) continue;
      if ((u-v)%3==0) continue;
      int a=2*u*v+v*v;
      int b=u*u-v*v;
      for (int k=1; k*(a+b)<N; k++){
        s[k*a].insert(k*b);
        s[k*b].insert(k*a);
      }
    }
  }

  set<int >sol;
  for(auto x:s){
    int a=x.first;
    for(auto b:x.second)
      for(auto c:x.second)
	if(a+b+c<=N && s[b].find(c)!=end(s[b]))
	  sol.insert(a+b+c);
  }

  int res=0;
  for(int x:sol)
    res+=x;
  cout << res << '\n';
}
