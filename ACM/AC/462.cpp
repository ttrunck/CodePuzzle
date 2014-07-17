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

bool stopped(const vector<string>& t, char c, int count){
	for(auto& s:t){
		if(s[1]!=c) continue;
		if(s[0] == 'A')
			return true;
		else if(s[0] == 'K' && count>1)
			return true;
		else if(s[0] == 'Q' && count>2)
			return true;
	}

	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	while(getline(cin, s)){
		istringstream ss(s);
		vector<string> t(13);
		for(int i=0;i<13;++i)
			ss >> t[i];
		int score=0, trump=0;		
		map<char, int> count;
		count['S'] = 0;
		count['H'] = 0;
		count['D'] = 0;
		count['C'] = 0;
		for(auto& c:t)
			count[c[1]]++;

		for(auto& s:t)
			if(s[0]=='A'){
				trump += 4;
			}
			else if(s[0]=='K'){
				trump += 3;
				if(count[s[1]]<=1)
					--trump;
			}
			else if(s[0]=='Q'){
				trump += 2;
				if(count[s[1]]<=2)
					--trump;
			}
			else if(s[0]=='J'){
				trump += 1;
				if(count[s[1]]<=3)
					--trump;				
			}

		score = trump;
		for(auto& p:count){
			if(p.second==2)
				++score;
			else if(p.second<=1)
				score += 2;
		}

		//cerr << trump << ' ' << score << endl;

		char top='S';
		int mini = count['S'];
		if(count['H']>mini){
			mini = count['H'];
			top = 'H';
		}
		if(count['D']>mini){
			mini = count['D'];
			top = 'D';
		}
		if(count['C']>mini){
			mini = count['C'];
			top = 'C';
		}
		bool stop = stopped(t, 'S', count['S']) && stopped(t, 'H', count['H']) && stopped(t, 'D', count['D']) && stopped(t, 'C', count['C']);
	
		if(trump>=16 && stop)
			cout << "BID NO-TRUMP\n";
		else if(score >= 14)
			cout << "BID " << top << '\n';
		else
			cout << "PASS\n";
	}
}