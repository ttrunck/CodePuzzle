#include<iostream>
#include<cmath>

using namespace std;

const int N=3009;
int t[N];
int d[N];

int main(){
  int n;
  while(cin >> n){
    bool res=true;
    for(int i=0;i<n;++i)
      d[i]=0;

    for(int i=0;i<n;++i)
      cin >> t[i];

    for(int i=0;i<n-1;++i)
      d[int(abs(t[i+1]-t[i]))]++;

    for(int i=1;i<n && res;++i)
      res=res&&(d[i]==1);

    if(res)
      cout << "Jolly" << endl;
    else
      cout << "Not jolly" << endl;
  }
}
