#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;

class ABBADiv1 {
	public:
	string canObtain(string initial, string target) {
		if(initial == target)
			return "Possible";
		int nbB = 0;
		for(char c : initial)
			if(c=='B')
				--nbB;
		for(char c : target)
			if(c=='B')
				++nbB;
		if(nbB % 2 == 1)
			reverse(begin(initial), end(initial));

		if(nbB == 0) {
			if(target.substr(0,initial.size()) == initial)
				return "Possible";
			else
				return "Impossible";
		}
		if(target[0]!='B')
			return "Impossible";

		int currB = 0;
		for(int i=0;i<int(target.size());++i) {
			if(target[i] == 'B')
				++currB;
			if(currB == (nbB+1)/2) {
				size_t f = target.find(initial, i+1);
				if(f == string::npos)
					return "Impossible";
				for(size_t j=i+1;j<f;++j)
					if(target[j]=='B')
						return "Impossible";
				return "Possible";
			}

		}
		return "Impossible";
	}
	

};