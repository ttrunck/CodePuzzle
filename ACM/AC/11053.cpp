#include<iostream>
#include<map>
#include<utility>

using namespace std;

typedef long long ent;

ent N,a,b;

ent next(ent n){
  return (((a*((n*n)%N))%N)+b)%N;
}

int main(){
 
  while(cin >> N >> a >> b && N){
    map<ent,pair<int, int> > t;
    ent curr=0;
    int time=0;
    while(t[curr].first!=1){
      t[curr]=make_pair(t[curr].first+1,time++);
      curr=next(curr);
    }

    int res=N;
    time=t[curr].second;
    map<ent,pair<int, int> >::iterator it;
    for(it=t.begin(); it!=t.end();++it)
      if(it->second.first==1 && it->second.second>=time)
	res--;

    cout << res << '\n';
  }
}
