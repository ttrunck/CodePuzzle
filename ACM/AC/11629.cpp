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

bool ok(int a, int b, const string& comp){
//	<, >, <=, >= or = 
	if(comp == "<")
		return a<b;
	else if(comp == ">")
		return a>b;
	else if(comp == "<=")
		return a<=b;
	else if(comp == ">=")
		return a>=b;
	else
		return a == b;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int p, g;
	cin >> p >> g;
	map<string, int> party;
	for(int i=0;i<p;++i){
		string tmp;
		int vote1, vote2;
		char trash;
		cin >> tmp >> vote1 >> trash >> vote2;
		party[tmp] = vote1*10 + vote2;
	}

	for(int i=1;i<=g;++i){
		cout << "Guess #" << i << " was ";
		string tmp;
		int curr = 0;
		while(true){
			cin >> tmp;
			curr += party[tmp];
			cin >> tmp;
			if(tmp[0]!='+') break;
		}

		int guess;
		cin >> guess;
		guess *= 10;
		//cerr << curr << ' ' << tmp << ' ' << guess << endl; 
		cout << ((ok(curr, guess, tmp))?"correct":"incorrect") << ".\n";
	}

}