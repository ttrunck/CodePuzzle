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

int dist(int n){
	int res = 0;
	while(n!=1){
		n/=2;
		res++;
	}
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin >> T;
	while(T--){
		int a, b;
		cin >> a >> b;

		int da = dist(a), db = dist(b);

		int res = 0;
		while(da!=db){
			res++;
			if(da>db){
				--da;
				a/=2;
			}
			else{
				--db;
				b/=2;
			}
		}

		while(a!=b){
			res += 2;
			a/=2;
			b/=2;
		}

		cout << res << '\n';
	}
}