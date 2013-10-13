#include<iostream>
#include<vector>

using namespace std;

int main(){
  int n,l,r,ql,qr;
  cin >> n >> l >> r >> ql >> qr;
  vector<int> t(n);
  for(int i=0;i<n;++i)
    cin >> t[i];

  int tot=0;
  for(int x:t)
    tot+=x;

  int g=0;
  int diff=-n;
  
  int res= g*l + (tot-g)*r;
  if(diff>0)
    res+=ql*(diff-1);
  else if(diff<0)
    res+=qr*(-diff-1);
  
  for(int i=1;i<=n;++i){
    g+=t[i-1];
    diff+=2;
    
    int tmp=g*l + (tot-g)*r;
    if(diff>0)
      tmp+=ql*(diff-1);
    else if(diff<0)
      tmp+=qr*(-diff-1);

    res= min(res, tmp);
  }

  cout << res << '\n';
}
