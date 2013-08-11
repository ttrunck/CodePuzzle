#include<iostream>
#include<vector>
#include<ctime>

using namespace std;

typedef long long ll;

const vector<int> prime{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
const int A=prime.size();

inline int powMod(ll x, int n, int m) {
	ll y = 1;
	while (n != 0) {
		if ((n & 1) == 1)
			y = (y * x) % m;
		x = (x * x) % m;
		n = n >> 1;
	}
	return y;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  clock_t ti;
  ti = clock();

  int N;
  cin >> N;
  vector<vector<int> > t(N+1, vector<int>(A));
  for(int i=1;i<=N;++i){
    int tmp;
    cin >> tmp;
    t[i]=t[i-1];
    while(tmp!=1){
      for(int j=0;j<A;++j)
	while(tmp%prime[j]==0){
	  tmp/=prime[j];
	  t[i][j]++;
	}
    }
  }

  ti = clock() - ti;
  cerr << double(ti)/CLOCKS_PER_SEC << endl;

  int Q;
  cin >> Q;
  for(int i=0;i<Q;++i){
    int L,R,M;
    cin >> L >> R >> M;
    if(M==1)
      cout << "0\n";
    else{
      ll res=1;
      for(int i=0;i<A;++i)
	res = (res*powMod(prime[i],t[R][i]-t[L-1][i],M))%M;
      cout << res << '\n';
    }
  }

  ti = clock() - ti;
  cerr << double(ti)/CLOCKS_PER_SEC << endl;
}
