#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const int MOD = 1000000007;

int powMod(ll x, int n) {
	ll y = 1;
	while (n != 0) {
		if ((n & 1) == 1)
			y = (y * x) % MOD;
		x = (x * x) % MOD;
		n = n >> 1;
	}
	return y;
}

int main() {
  int n;
  cin >> n;
  vector<ll> dp(n+1);
  for(int i=1;i<=n;++i) {
    dp[i] = (dp[i-1]*27) % MOD;
    dp[i] = (dp[i] + powMod(7, i-1) * 20ll)%MOD;
  }
  cout << dp[n] << '\n';
}
