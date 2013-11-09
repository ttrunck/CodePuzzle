#include<iostream>

using namespace std;

typedef long long ll;

ll mabs(ll a){
  return (a<0)?-a:a;
}

ll gcd(ll a, ll b){
  return b?gcd(b,a%b):a;
}

int main(){
  int nbcase;
  cin >> nbcase;
  while(nbcase--){
    int c;
    int maxa10=0;
    cin >> c;
    int res=0;
    for(int i=0;i<c;++i){
      ll val=0;
      for(int j=0;j<9;++j){
	int tmp;
	cin >> tmp;
	val+=tmp;
      }
      int tmp;
      cin >> tmp;
      maxa10=max(maxa10, tmp);
      val-=tmp;
      
      res=gcd(res, mabs(val));
    }
    if(res>1 && maxa10<res)
      cout << res << '\n';
    else
      cout << "impossible\n";
  }
}
