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
	
	int pont, trou, plate;
	cin >> pont >> trou >> plate;
cerr << pont << endl;
	int s, x;
	while(cin >> s >> x) {
		if(x==pont-1){
			cout << "JUMP\n";
			continue;
		}
		else if(x>=(pont+trou) || s>trou+1){
			cout << "SLOW\n";
			continue;
		}
		else if(s<=trou){
			cout << "SPEED\n";
			continue;
		}
		else{
			cout << "WAIT\n";
			continue;
		}
	}
}