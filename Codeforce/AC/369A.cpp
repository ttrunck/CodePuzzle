#include<iostream>

using namespace std;

int main(){
  int n,m,k;
    cin >> n >> m >> k;
  for(int i=0;i<n;++i){
    int tmp;
    cin >> tmp;
    if(tmp==1)
      --m;
    else
      --k;
  }

  if(k<0)
    m+=k;

  cout << max(0,-m) << '\n';

}
