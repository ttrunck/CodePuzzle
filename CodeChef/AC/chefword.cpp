#include <algorithm>
#include <array>
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
typedef array<array<double, 26>, 26> matrix;

matrix mult(const matrix& a, const matrix& b){
	matrix res;
	for(int i=0;i<26;++i)
		for(int j=0;j<26;++j)
			res[i][j] = 0;

	for(int i=0;i<26;++i)
		for(int j=0;j<26;++j)
			for(int k=0;k<26;++k)
				res[i][j] += a[i][k] * b[k][j];

	return res;
}

matrix pow(const matrix& m, int k){
	if(k==1)
		return m;
	matrix tmp = pow(m, k/2);
	tmp = mult(tmp, tmp);
	if(k%2==1)
		tmp = mult(m, tmp);
	return tmp;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		string s;
		cin >> s;
		matrix mat;
		for(int i=0;i<26;++i)
			for(int j=0;j<26;++j)
				cin >> mat[i][j];

		mat = pow(mat, k);

		double res = 0;
		set<string> st;
		for(int i=0;i<n;++i){
			string tmp;
			cin >> tmp;
			if(tmp.size() == s.size())
				st.insert(tmp);
		}

		for(const string& tmp:st){
			double proba = 1.;
			for(int j=0;j<int(s.size());++j)
				proba *= mat[s[j]-'a'][tmp[j]-'a'];
			res += proba;
		}
		cout << res << '\n';
	}
}