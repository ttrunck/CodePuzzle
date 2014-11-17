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
	int n;
	cin >> n;
	while(n--){
		string s;
		cin >> s;
		set<char> st;
		for(char c:s)
			st.insert(c);
		cout << st.size() << '\n';
	}
}