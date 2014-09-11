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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<string> t(n);
	for(int i=0;i<n;++i)
		cin >> t[i];

	int maxi = 0;
	for(int i=0;i<n;++i)
		for(int j=i+1;j<n;++j){
			int topic = 0;
			for(int k=0;k<m;++k)
				if(t[i][k]=='1' || t[j][k]=='1')
					++topic;
			maxi = max(maxi, topic);
		}

	int nbteam = 0;
	for(int i=0;i<n;++i)
		for(int j=i+1;j<n;++j){
			int topic = 0;
			for(int k=0;k<m;++k)
				if(t[i][k]=='1' || t[j][k]=='1')
					++topic;
			if(topic == maxi)
				++nbteam;
		}

	cout << maxi << '\n';
	cout << nbteam << '\n';

}