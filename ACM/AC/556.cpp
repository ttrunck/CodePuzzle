#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <random>
#include <set>
#include <sstream>
#include <cassert>
#include <iomanip>

using namespace std;

typedef long long ll;

static const vector<int> dx{1,0,-1,0};
static const vector<int> dy{0,1,0,-1};

struct robot{
	int x, y;
	int dir;
	robot(int a=0, int b=0):x(a), y(b),dir(0){};

	void next(const vector<string>& t){
		int n=t.size();
		int m=t[0].size();

		int nx = x+dx[dir];
		int ny = y+dy[dir];
		if(nx>=0 && ny>=0 && nx<n && ny<m && t[nx][ny]=='0'){
			x=nx;
			y=ny;
			dir = (dir-1+4)%4;
			return;
		}
		nx = x+dx[(dir+1)%4];
		ny = y+dy[(dir+1)%4];
		if(nx>=0 && ny>=0 && nx<n && ny<m && t[nx][ny]=='0'){
			x=nx;
			y=ny;
		}
		else{
			dir = (dir+1)%4;
			this->next(t);
		}
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	while(cin >> n >> m && (n||m)){
		vector<string> t(n);
		for(int i=0;i<n;++i)
			cin >> t[i];
		vector<vector<int>> touch(n, vector<int>(m, 0));

		robot r(n-1, 0);
		do{
			//cerr << r.x << ' ' << r.y << endl;
			++touch[r.x][r.y];
			r.next(t);
		}while(r.x != n-1 || r.y != 0);

		vector<int> res(5, 0);
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				if(touch[i][j]<5 && t[i][j]=='0')
					++res[touch[i][j]];

		for(int x:res)
			cout << setw(3) << setfill(' ') << x;
		cout << '\n';
	}
}