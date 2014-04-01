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

bool mysort(char a, char b){
	return toupper(a) < toupper(b) || (toupper(a)==toupper(b) && a<b);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i=0;i<n;++i){
		string s;
		cin >> s;
		sort(begin(s), end(s), mysort);
		do{
			cout << s << '\n';
		}while(next_permutation(begin(s), end(s), mysort));
	}	
}