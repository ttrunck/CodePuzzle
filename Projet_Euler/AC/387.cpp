#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

const ll N = 100000000000000ll;

struct harshad{
	ll val;
	int sum;
	bool strong;

	harshad(int x=0):val(x), sum(x), strong(false){};
};

bool isPrime(ll x){
	if(x==2) return true;
	if(x%2==0) return false;
	for(ll i=3;i*i<=x;i+=2)
		if(x%i==0)
			return false;
	return true;
}

int main() {
	ll res = 0;
	queue<harshad> q;
	for(int i=1;i<=9;++i)
		q.push(harshad(i));

	while(!q.empty()) {
		auto x = q.front();
		q.pop();
		//cerr << x.val << '\n';

		if(x.val >= N)
			continue;

		for(int i=0;i<=9;++i){
			ll val = x.val*10 + i;
			if(x.strong && val<N && isPrime(val))
				res += val;
			if(val%(x.sum+i)==0){
				harshad nn;
				nn.val = val;
				nn.sum = x.sum+i;
				nn.strong = isPrime(nn.val/nn.sum);
				q.push(nn);
			}
		}

	}

	cout << res << '\n';
}