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
#include <stack>

using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int set;
	cin >> set;
	while(set--){
		int n, s, q;
		cin >> n >> s >> q;
		int curr = 0;
		stack<int> st;
		vector<queue<int>> t(n);
		int to_carry = 0;

		for(int i=0;i<n;++i){
			int nb;
			cin >> nb;
			to_carry += nb;
			for(int j=0;j<nb;++j){
				int tmp;
				cin >> tmp;
				t[i].push(tmp-1);
			}
		}

		int res = 0;
		while(true){
			
			while(!st.empty()){
				if(st.top() == curr){
					res += 1;
					--to_carry;
					st.pop();
				}
				else if(int(t[curr].size())<q){
					t[curr].push(st.top());
					res += 1;
					st.pop();
				}
				else
					break;
			}
			while(!t[curr].empty() && int(st.size())<s){
				st.push(t[curr].front());
				t[curr].pop();
				res += 1;
			}

			if(to_carry == 0) break;
			curr = (curr+1)%n;
			res += 2;
		}
		cout << res << '\n';
	}
}