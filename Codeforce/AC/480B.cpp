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
typedef pair<int, int> pi;

int n, l, x, y;
set<int> t;

bool check(int x, pi& res, int a=0){
	for(int n : t){
		if(t.find(n-x)!=end(t) && n-x+a>=0 && n-x+a<=l){
			res = pi{n-x, n};
			return true;
		}
		else if(t.find(n+x)!=end(t) && n+a>=0 && n+a<=l){
			res = pi{n, n+x};
			return true;
		}
	}
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> l >> x >> y;

	for(int i=0;i<n;++i){
		int tmp;
		cin >> tmp;
		t.insert(tmp);
	}

	pi px, py, pxy1, pxy2;
	bool bx = check(x, px);
	bool by = check(y, py);
	bool bxy1 = check(x+y, pxy1);

	if(bx && by)
		cout << "0\n";
	else if(bx)
		cout << "1\n" << y << '\n';
	else if(by)
		cout << "1\n" << x << '\n';
	else if(bxy1)
		cout << "1\n" << pxy1.first + x << '\n';
	else if(check(y-x, pxy2, y))
		cout << "1\n" << pxy2.first + y << '\n';
	else if(check(y-x, pxy2, -x))
		cout << "1\n" << pxy2.second - y << '\n';
	else
		cout << "2\n" << x << ' ' << y << '\n';

}