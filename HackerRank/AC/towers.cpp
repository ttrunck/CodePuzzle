#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

typedef vector<vector<ll>> mat;

const int SIZE = 16;
const int MOD = 1000000007;

void print(const mat& m){
	for(int i=0;i<SIZE;++i){
		for(int j=0;j<SIZE;++j)
			cerr << m[i][j] << ' ';
		cerr << endl;
	}
}

void prod(const mat& a, const mat& b, mat& c){
	for(int i=0;i<SIZE;++i)
		for(int j=0;j<SIZE;++j){
			c[i][j] = 0;
			for(int k=0;k<SIZE;++k)
				c[i][j] += a[i][k] * b[k][j];
			c[i][j] %= MOD;
		}
}

void exp(mat& m, ll n){
	if(n==0){
		for(int i=0;i<SIZE;++i)
			for(int j=0;j<SIZE;++j)
				m[i][j] = 0;
		for(int i=0;i<SIZE;++i)
			m[i][i] = 1;
	}
	else{
		mat tmp1(SIZE, vector<ll>(SIZE,0));
		mat tmp2(SIZE, vector<ll>(SIZE,0));
		for(int i=0;i<SIZE;++i)
			for(int j=0;j<SIZE;++j)
				tmp1[i][j] = m[i][j];
		exp(tmp1, n/2);
		prod(tmp1, tmp1, tmp2);
		
		if(n%2==1){
			for(int i=0;i<SIZE;++i)
				for(int j=0;j<SIZE;++j)
					tmp1[i][j] = m[i][j];
			prod(tmp2, tmp1, m);
		}
		else{
			for(int i=0;i<SIZE;++i)
				for(int j=0;j<SIZE;++j)
					m[i][j] = tmp2[i][j];
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n;
	int k;
	cin >> n >> k;
	mat m(SIZE, vector<ll>(SIZE,0));
	for(int i=0;i<k;++i){
		int tmp;
		cin >> tmp;
		m[0][tmp-1] = 1;
	}
	for(int i=0;i<SIZE-1;++i)
		m[i+1][i] = 1;

	exp(m, n);
	cout << (2*m[0][0])%MOD << '\n';

}