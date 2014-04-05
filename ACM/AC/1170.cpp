#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <random>
#include <set>
#include <sstream>
#include <cassert>
#include <queue>
#include <unordered_set>

using namespace std;

typedef long long ll;

typedef pair<int, int> pi;

struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first+v.second*900000;
    }
};

const vector<int> dx{1,-1,0,0};
const vector<int> dy{0,0,1,-1};

struct pos{
	int x,y,m,p,d,xp,yp;
	pos(int a,int b,int c,int dd,int e,int f, int g){
		x=a;
		y=b;
		m=c;
		p=dd;
		d=e;
		xp=f;
		yp=g;
	}
};

bool stuck(int x, int y, int n, int m, int p, const vector<vector<int>>& t){
	for(int i=0;i<4;++i){
		int nx = x+dx[i]*p;
		int ny = y+dy[i]*p;
		if(nx>=0 && nx<n && ny>=0 && ny<m && t[nx][ny]!=0)
			return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int nbcase;
	cin >> nbcase;
	bool first=true;
	while(nbcase--){
		if(!first)
			cout << '\n';
		first=false;
		int n, m;
		cin >> n >> m;
		vector<vector<int>> t(n, vector<int>(m));
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				cin >> t[i][j];

		int xd,yd,xf,yf;
		cin >> xd >> yd >> xf >> yf;
		
		assert(t[xd][yd]==1);

		queue<pos> q;
		q.push(pos(xd,yd,0,1,0,0,-1));
		unordered_set<pi, pair_hash> visit;
		visit.insert(pi(xd*m+yd, -10));
		bool ok=false;
		while(!q.empty()){
			pos curr = q.front();
			q.pop();
			if(curr.x == xf && curr.y == yf){
				ok=true;
				cout << curr.d << '\n';
				break;
			}

			for(int i=0;i<4;++i){
				int nx = curr.x + dx[i]*curr.p;
				int ny = curr.y + dy[i]*curr.p;
				if(nx<0 || nx>=n || ny<0 || ny>=m || t[nx][ny]==0) continue;
				int nm = max(0, curr.m-1);
				int np = (nm?curr.p:1);
				int nd = curr.d + 1;
				int nxp = curr.xp;
				int nyp = curr.yp;
				if(t[nx][ny]>1 && (nx!=curr.xp || ny!=curr.yp || nm==0)){
					nm = t[nx][ny]/10;
					np = t[nx][ny]%10;
					nxp = nx;
					nyp = ny;

					if(stuck(nx, ny, n, m, np, t)){
						pi tmp(curr.x*m+curr.y,-10);
						if(visit.find(tmp)==end(visit)){
							visit.insert(tmp);					
							q.push(pos(curr.x,curr.y,0,1,nd,0,-1));
						}
					}

				}
				pi tmp(nx*m+ny, (nxp*m+nyp)*10+nm);
				if(visit.find(tmp)!=end(visit)) continue;
				visit.insert(tmp);					
				q.push(pos(nx,ny,nm,np,nd,nxp,nyp));
			}
		}
		if(!ok)
			cout << "IMPOSSIBLE\n";
	}
}