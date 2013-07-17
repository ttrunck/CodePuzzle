#include<iostream>
#include<vector>

using namespace std;

typedef long long ent;

ent const N=1000000007;

ent pow(ent x, ent n) {
	ent y = 1;
	while (n != 0) {
		if ((n & 1) == 1)
			y = (y * x) % N;
		x = (x * x) % N;
		n = n >> 1;
	}
	return y;
}

int main(){
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  for(int icase=1;icase<=T;++icase){
    cout << "Case " << icase << ": ";
    ent res=1;
    int c;
    cin >> c;
    vector<int> p(c);
    vector<int> m(c);
    for(int i=0;i<c;++i)
      cin >> p[i] >> m[i];

    vector<ent> powpow(c);
    for(int i=0;i<c;++i)
      powpow[i]=pow(p[i],m[i]);

    for(int i=0;i<c;++i)
      res=(res*powpow[i])%N;

    vector<ent> sumpow(c);
    for(int i=0;i<c;++i){
      ent pp=1;
      for(int j=0;j<m[i];++j){
	sumpow[i]=(sumpow[i]+pp)%N;
	pp=(pp*p[i])%N;
      }
    }
 
    for(int i=0;i<(1<<c);++i){
      int tmp=i;
      ent curr=1;
      //Qi
      for(int i=0;i<c;++i){
	if(tmp%2==0)
	  curr=((((m[i]+1)*curr)%N)*powpow[i])%N;
	else
	  curr=(curr*sumpow[i])%N;
	tmp/=2;
      }
      res=(res+curr)%N;
    }
    cout << res << '\n';
  }
}
