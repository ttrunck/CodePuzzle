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

void print(int n, int a, int b, const string& s, int page){
	bool ba = (a>0 && a<=n), bb = (b>0 && b<=n);
	if(s!="back " || ba || bb){
		cout << "Sheet " << page+1 << ", " << s << ": ";
		if(ba)
			cout << a;
		else
			cout << "Blank";

		 cout << ", ";
		 if(bb)
		 	cout << b;
		 else
		 	cout << "Blank";
		 cout << '\n';
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	while(cin >> n && n){
		cout << "Printing order for " << n << " pages:\n";
		for(int i=0;i<(n+3)/4;++i){
			print(n, (n+3)/4*4-2*i, i*2+1, "front", i);
			print(n, i*2+2, (n+3)/4*4-2*i-1, "back ", i);
		}
	}
}