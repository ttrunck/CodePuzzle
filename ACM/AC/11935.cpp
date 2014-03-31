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

struct triple{
	int k, val;
	char ev;
	triple(int a=0, char b=' ', int c=0){
		k=a;
		ev=b;
		val=c;
	}
};

bool parse(vector<triple>& t, const string& s){
	istringstream ss(s);
	int a,c;
	char b;
	string tmp;
	ss >> a >> tmp;
	if(tmp == "Fuel"){
		b = 'f';
		ss >> tmp >> c;
		t.push_back(triple(a,b,c));
		return true;
	}
	else if(tmp == "Goal"){
		b = 'e';
		t.push_back(triple(a,b));
		return false;
	}
	else if(tmp == "Leak"){
		b = 'l';
		t.push_back(triple(a,b));
		return true;
	}
	else if(tmp == "Gas"){
		b = 'g';
		t.push_back(triple(a,b));
		return true;
	}
	else{
		assert(tmp == "Mechanic");
		b = 'm';
		t.push_back(triple(a,b));
		return true;
	}
}

bool compute(const vector<triple>& t, double x){
	double tank = x;
	int fuite = 0;
	double conso = 0;
	int pos = 0;

	for(const triple& tt : t){
		tank -= (tt.k - pos) * (conso/100 + fuite);
		pos = tt.k;
		if(tank < 0)
			return false;
		if(tt.ev == 'f'){
			conso = tt.val;
		}
		else if(tt.ev == 'l'){
			++fuite;
		}
		else if(tt.ev == 'm'){
			fuite = 0;
		}
		else if(tt.ev == 'g'){
			tank = x;
		}
		else{
			assert(tt.ev == 'e');
			return true;
		}
	}
	assert(false);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s;
	while(getline(cin, s)){
		vector<triple> t;
		parse(t, s);
		while(getline(cin, s) && parse(t, s));
		if(t.size()==1) break;

		double lo=0, hi=1000000000;
		const double eps = 1e-4;
		while(hi-lo>eps){
			double x = (hi+lo)/2;
			if(compute(t, x))
				hi=x;
			else
				lo=x;
		}
		cout << fixed << setprecision(3) << lo << '\n';
	}


}