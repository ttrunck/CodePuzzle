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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> t(n);
	for(int i=0;i<n;++i)
		cin >> t[i];
	int w=0;
	for(int x:t)
		w+=x;
	int maxi=0, mini=0;
	int curr = 0;
	for(int i=0;i<n;++i){
		curr = curr + (i%2?-t[i]:t[i]);
		maxi=max(maxi, curr);
		mini=min(mini, curr);
	}
	vector<string> res(maxi-mini, string(w, ' '));

	int currx = 0;
	int curry = -mini;
	for(int i=0;i<n;++i)
		if(i%2==0){
			for(int j=0;j<t[i];++j){
				res[curry][currx] = '/';
				++currx;
				++curry;
			}
			if(t[i]!=0) --curry;
		}
		else{
			for(int j=0;j<t[i];++j){
				res[curry][currx] = '\\';
				++currx;
				--curry;
			}
			if(t[i]!=0) ++curry;
		}

	for(int i=res.size()-1;i>=0;--i)
		cout << res[i] << '\n';
}