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
	int n, k, p;
	cin >> n >> k >> p;
	vector<int> t(n);
	for(int i=0;i<n;++i)
		cin >> t[i];

	vector<int> odd, even;
	int nbodd=0, nbeven;
	for(int x:t)
		if(x%2){
			++nbodd;
			odd.push_back(x);
		}
		else
			even.push_back(x);
	nbeven = n-nbodd;

	if(k-p>nbodd || (nbodd-k+p)%2==1 || ((nbodd-k+p)/2+nbeven<p)) {
		cout << "NO\n";
	}
	else{
		cout << "YES\n";
		for(int i=0;i<k-p-1;++i){
			cout << 1 << ' ' << odd.back() << '\n';
			odd.pop_back(); 
		}
		if(p==0){
			cout << odd.size()+even.size();
			for(int x:odd)
				cout << ' ' << x;
			for(int x:even)
				cout << ' ' << x;
			cout << '\n';
		}
		else{
			if(k-p>0){
			cout << 1 << ' ' << odd.back() << '\n';
			odd.pop_back();
			} 
			for(int i=0;i<p-1;++i){
				if(!even.empty()){
					cout << 1 << ' ' << even.back() << '\n';
					even.pop_back();
				}
				else{
					cout << 2 << ' ' << odd.back();
					odd.pop_back();
					cout << ' ' << odd.back();
					odd.pop_back();
					cout << '\n';
				}
			}
			cout << odd.size()+even.size();
			for(int x:odd)
				cout << ' ' << x;
			for(int x:even)
				cout << ' ' << x;
			cout << '\n';
		}
	}
}