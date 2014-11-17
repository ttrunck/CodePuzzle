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
typedef pair<int, int> pi;

int level(int n){
	int res = -1;
	while(n){
		++res;
		n/=2;
	}
	return res;
}

array<int,2> aux(int x, int y){
	array<int, 2> res = {0,0};
	int lx = level(x);
	int ly = level(y);

	while(lx>ly){
		++res[lx%2];
		x/=2;
		--lx;
	}
	while(ly>lx){
		++res[ly%2];
		y/=2;
		--ly;
	}

	while(x!=y){
		++res[lx%2];
		x/=2;
		--lx;
		++res[ly%2];
		y/=2;
		--ly;
	}

	++res[lx%2];

	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int q;
	cin >> q;
	bool blackRoot = true;
	while(q--){
		char tmp, ask;
		cin >> tmp >> ask;
		if(ask == 'i')
			blackRoot = !blackRoot;
		else{
			int x, y;
			cin >> x >> y;
			array<int,2> res = aux(x,y);
			if((blackRoot && ask=='b') || (!blackRoot && ask=='r'))
				cout << res[0] << '\n';
			else
				cout << res[1] << '\n';
		}
	}
}