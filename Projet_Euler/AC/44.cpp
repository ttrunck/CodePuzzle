#include<iostream>

using namespace std;

typedef long long ent;

int const N=50000000;
bool pentagonal[N];

inline ent p(ent n){
  return (n*(3*n-1))/2;
}

int main(){
  for(int i=0;i<N;++i)
    pentagonal[i]=false;
  for(int i=1;p(i)<N;++i)
    pentagonal[p(i)]=true;

  for(int i=1;p(i)<N;++i)
    for(int j=i+1;p(j)+p(i)<N;++j)
     if(pentagonal[p(i)+p(j)] && pentagonal[p(j)-p(i)])
	cout << p(j) << ' ' << p(i) << ' ' << p(j)-p(i) << '\n';
}
