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

typedef array<int, 4> tupple;

int hpx, atx, defx, hpy, aty, defy, h, a, d;

bool win(int hp, int att, int def){
	int hpm = hpy;
	while(hpm>0 && hp>0){
		hpm-=att;
		hp-=max(0,def);
	}
	return hp>0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
		
	cin >> hpx >> atx >> defx >> hpy >> aty >> defy >> h >> a >> d;

	int att = atx - defy;
	int def = aty - defx;

	int res = 0;
	if(att <= 0){
		res += -att*a + a;
		att = 1;
	}
	
	set<tupple> q;
	q.insert(tupple{0, 0, 0, 0});
	while(true){
		auto it = begin(q);
		auto t = *it;
		q.erase(it);
		if(win(hpx+t[1], att+t[2], def-t[3])){
			cout << res + t[0] << '\n';
			break;
		}

		q.insert(tupple{t[0]+h, t[1]+1, t[2], t[3]});
		q.insert(tupple{t[0]+a, t[1], t[2]+1, t[3]});
		q.insert(tupple{t[0]+d, t[1], t[2], t[3]+1});

	}

}