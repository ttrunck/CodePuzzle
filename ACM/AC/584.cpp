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
	string s;
	while(getline(cin, s) && s!="Game Over") {
		int score = 0;
		istringstream ss(s);
		char c;
		vector<char> t;
		vector<int> sco;
		while(ss >> c){
			t.push_back(c);
			if(isdigit(c))
				sco.push_back(c-'0');
			else if(c=='X')
				sco.push_back(10);
			else
				sco.push_back(10-sco.back());
		}

		for(int i=0, f=0;f<20;++i){
			if(isdigit(t[i])){
				score += sco[i];
				++f;
			}
			else if(t[i]=='X'){
				score += sco[i] + (i+1<int(t.size())?sco[i+1]:0) + (i+2<int(t.size())?sco[i+2]:0);
				f += 2;
			}
			else{
				score += sco[i] + (i+1<int(t.size())?sco[i+1]:0);
				++f;
			}
		}
		cout << score << '\n';
	}
}