#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <random>
#include <set>
#include <sstream>
#include <cassert>
#include <iomanip>

using namespace std;

typedef long long ll;

const int cinqH = 5*60*60;

bool isgreen(int t, int curr){
	return (curr % (2*t))<(t-5);
}

bool isgreen(const vector<int>& t, int curr){
	for(int x:t)
		if(!isgreen(x, curr))
			return false;
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while(true){
		vector<int> t;
		int n;
		while(cin >> n && n!=0)
			t.push_back(n);
		if(t.empty())
			return 0;
		int curr = 0;
		while(isgreen(t, curr)) ++curr;
		while(curr <= cinqH && !isgreen(t, curr)) ++curr;
	
		if(curr > cinqH)
			cout << "Signals fail to synchronise in 5 hours\n";
		else{
			cout << setfill('0') << setw(2) << curr/(60*60) << ':';
			cout << setfill('0') << setw(2) << (curr/60)%60 << ':';
			cout << setfill('0') << setw(2) << curr%60 << '\n';
		}
	}
}