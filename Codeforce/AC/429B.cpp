#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> t(n, vector<int>(m));
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			cin >> t[i][j];
	vector<vector<int>> mem1(n, vector<int>(m,0));
	vector<vector<int>> mem2(n, vector<int>(m,0));
	vector<vector<int>> mem3(n, vector<int>(m,0));
	vector<vector<int>> mem4(n, vector<int>(m,0));

	mem1[0][0] = t[0][0];
	for(int i=1;i<m;++i)
		mem1[0][i] = mem1[0][i-1] + t[0][i];
	for(int i=1;i<n;++i)
		mem1[i][0] = mem1[i-1][0] + t[i][0];
	for(int i=1;i<n;++i)
		for(int j=1;j<m;++j)
			mem1[i][j] = t[i][j] + max(mem1[i-1][j], mem1[i][j-1]);

	mem2[n-1][0] = t[n-1][0];
	for(int i=1;i<m;++i)
		mem2[n-1][i] = mem2[n-1][i-1] + t[n-1][i];
	for(int i=n-2;i>=0;--i)
		mem2[i][0] = mem2[i+1][0] + t[i][0];
	for(int i=n-2;i>=0;--i)
		for(int j=1;j<m;++j)
			mem2[i][j] = t[i][j] + max(mem2[i+1][j], mem2[i][j-1]);

	mem3[n-1][m-1] = t[n-1][m-1];
	for(int i=m-2;i>=0;--i)
		mem3[n-1][i] = mem3[n-1][i+1] + t[n-1][i];
	for(int i=n-2;i>=0;--i)
		mem3[i][m-1] = mem3[i+1][m-1] + t[i][m-1];
	for(int i=n-2;i>=0;--i)
		for(int j=m-2;j>=0;--j)
			mem3[i][j] = t[i][j] + max(mem3[i+1][j], mem3[i][j+1]);

	mem4[0][m-1] = t[0][m-1];
	for(int i=m-2;i>=0;--i)
		mem4[0][i] = mem4[0][i+1] + t[0][i];
	for(int i=1;i<n;++i)
		mem4[i][m-1] = mem4[i-1][m-1] + t[i][m-1];
	for(int i=1;i<n;++i)
		for(int j=m-2;j>=0;--j)
			mem4[i][j] = t[i][j] + max(mem4[i-1][j], mem4[i][j+1]);

	int res = 0;
	for(int i=1;i<n-1;++i)
		for(int j=1;j<m-1;++j){
			int che1 = mem1[i-1][j] + mem2[i][j-1] + mem3[i+1][j] + mem4[i][j+1];
			int che2 = mem1[i][j-1] + mem2[i+1][j] + mem3[i][j+1] + mem4[i-1][j];
			res = max(res, max(che1, che2));
		}
	cout << res << '\n';
}