#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

typedef long long ll;

vector<int> s(500500);
vector<vector<int>> t(1000, vector<int>(1000));
vector<vector<vector<int>>> tt(1000, vector<vector<int>>(1000, vector<int>(3, 0)));

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	ll tmp = 0;
	for(int k=0;k<500500;++k){
		tmp = (615949*tmp + 797807) % (1<<20);
		s[k] = tmp - (1<<19);
	}

	int res = 0;

	int curr=0;
	for(int i=0;i<1000;++i)
		for(int j=0;j<=i;++j){
			t[i][j]=s[curr++];
			res = min(res, t[i][j]);
		}

	for(int i=0;i<999;++i)
		for(int j=0;j<=i;++j){
			tt[i][j][0] = t[i][j] + t[i+1][j] +t[i+1][j+1]; 
			res = min(res, tt[i][j][0]);
		}

	for(int i=0;i<998;++i)
		for(int j=0;j<=i;++j){
			tt[i][j][1] = t[i][j] + tt[i+1][j][0] +tt[i+1][j+1][0] - t[i+2][j+1]; 
			res = min(res, tt[i][j][1]);
		}


	for(int k=3;k<1000;++k){
		for(int i=0;i<1000-k;++i)
			for(int j=0;j<=i;++j){
				tt[i][j][(k-1)%3] = t[i][j] + tt[i+1][j][(k-2)%3] +tt[i+1][j+1][(k-2)%3] - tt[i+2][j+1][(k-3)%3]; 
				res = min(res, tt[i][j][(k-1)%3]);
			}
	}
	
	cout << res << '\n';
}