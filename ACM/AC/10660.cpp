#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <random>
#include <set>
#include <sstream>
#include <cassert>

using namespace std;

typedef long long ll;

int dist(int x1,int x2, int x3, int x4, int x5, const vector<vector<int> >& t){
	int res = 0;
	for(int i=0;i<5;++i)
		for(int j=0;j<5;++j){
			int d = abs(i-x1/5)+abs(j-x1%5);
			d = min(d, abs(i-x2/5)+abs(j-x2%5));
			d = min(d, abs(i-x3/5)+abs(j-x3%5));
			d = min(d, abs(i-x4/5)+abs(j-x4%5));
			d = min(d, abs(i-x5/5)+abs(j-x5%5));
			res += d*t[i][j];
		}
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int nb;
	cin >> nb;
	while(nb--){
		int n;
		cin >> n;
		vector<vector<int>> t(5, vector<int>(5, 0));
		for(int i=0;i<n;++i){
			int x, y, v;
			cin >> x >> y >> v;
			t[x][y] = v;
		}

		int mini = dist(0,1,2,3,4,t);
		int x1=0,x2=1,x3=2,x4=3,x5=4;
		for(int i1=0;i1<25;++i1)
			for(int i2=i1+1;i2<25;++i2)
				for(int i3=i2+1;i3<25;++i3)
					for(int i4=i3+1;i4<25;++i4)
						for(int i5=i4+1;i5<25;++i5){
							int tmp = dist(i1,i2,i3,i4,i5,t);
							if(tmp<mini){
								mini = tmp;
								x1 = i1;
								x2 = i2;
								x3 = i3;
								x4 = i4;
								x5 = i5; 
							}
						}
	cout << x1 << ' ' << x2 << ' ' << x3 << ' ' << x4 << ' ' << x5 << '\n'; 

	}
}