#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cassert>

using namespace std;

typedef long long ll;

const ll MODf = 10000000000000000ll;

const int N = 5000;
vector<bool> prime(N*N, true);
vector<int> t;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	prime[0]=prime[1]=false;
	for(int i=2;i<N*N;++i)
		if(prime[i])
			for(int j=i+i;j<N*N;j+=i)
				prime[j]=false;

	for(ll i=0;i<=N;++i)
		if(prime[i])
			t.push_back(i);

	int sup = 0;
	for(int x:t)
		sup += x;
	vector<ll> mem(sup+1, 0);

	mem[0] = 1;
	for(int x:t)
		for(int j=sup;j>=x;--j)
			mem[j] = (mem[j] + mem[j-x])%MODf;

	ll res=0;
	for(int i=0;i<sup+1;++i)
		if(prime[i])
			res = (res + mem[i])%MODf;

	cout << res << '\n';

}