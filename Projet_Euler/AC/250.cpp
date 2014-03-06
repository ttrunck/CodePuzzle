#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cassert>

using namespace std;

typedef long long ll;


const ll MODf = 10000000000000000ll;
const ll MOD = 250;

ll pow(ll a, ll b){
	if(b==0) return 1;
	ll tmp = pow(a, b/2);
	tmp = (tmp*tmp)%MOD;
	if(b%2==0)
		return tmp;
	return (a*tmp)%MOD;
}

vector<ll> t(250250);
vector<vector<ll> > mem(250250, vector<ll>(MOD, 0));

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	for(ll i=0;i<250250;++i)
		t[i] = pow(i+1, i+1);

	mem[0][0] = 1;
	mem[0][t[0]%MOD] = 1;
	for(int i=1;i<250250;++i)
		for(int j=0;j<MOD;++j)
			mem[i][j] = (mem[i-1][j] + mem[i-1][((j-t[i])%MOD+MOD)%MOD])%MODf;

	cout << mem[250249][0]-1 << '\n';

}