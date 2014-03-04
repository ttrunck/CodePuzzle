/*
#include <stdio.h>

long long ans[10000001];
char comp[10000001];
int primes[700000];

int main() {
	ans[0] = ans[1] = 1;
	int l = 0;
	for (int i=2; i<=10000000; i++) {
		ans[i] = ans[i-1];
		if (!comp[i]) {
			primes[l++] = i;
			if (i < 4000)
				for (int j=i*i; j<=10000000; j+=i)
					comp[j] = 1;
		}
		else
			ans[i] = (ans[i] * i) % 1000000007;
	}
	int n;
	while(scanf("%d", &n) == 1 && n) {
		long long res = ans[n];
		for (int i=0; i<l && primes[i] <= n/2; ++i) {
			int cnt = 0;
			int tn = n;
			do {
				tn /= primes[i];
				cnt += tn;
			}while(tn >= primes[i]);
			if (cnt % 2 == 0)
				res = (res * primes[i]) % 1000000007;
		}
		printf("%lld\n", res);
	}
	return 0;
}

 */

#include<iostream>
#include<vector>

using namespace std;

typedef long long ent;

const int MOD=1000000007;
const int N=9999992;
const int size=664579;

inline ent pow (ent a, int e) {
  ent p;
  for (p = 1; e > 0; e = e / 2) {
    if (e % 2 != 0)
      p = (p * a) % MOD;
    a = (a * a) % MOD;
  }
  return p;
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

  vector<bool> prime(N);
  for(int i=0;i<N;++i)
    prime[i]=(i%2!=0);
  prime[2]=true;
  prime[1]=false;
  for(int i=3;i<N;++i)
    if(prime[i])
      for(int j=i+i;j<N;j+=i)
	prime[j]=false;
  vector<int> prem(size);
  int curr=0;
  for(int i=0;i<N;++i)
    if(prime[i])
      prem[curr++]=i;


  int n;
  while(cin >> n && n!=0){
    ent res=1;
    for(int i=0;i<size && 2*prem[i]<=n;++i){
      int curr=0;
      ent p=prem[i];
      while(n/p!=0){
	curr+=n/p;
	p*=prem[i];
      }
      //  if(prem[i]<10)
	cout << prem[i] << ' ' << curr << endl;
      if(curr%2==1) curr--;
      res=(res*pow(prem[i],curr))%MOD;
    }
    cout << res << '\n';
  }
}
