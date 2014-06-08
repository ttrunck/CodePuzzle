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
	int n;
	int nb100=0, nb200=0;
	cin >> n;
	for(int i=0;i<n;++i){
		int tmp;
		cin >> tmp;
		if(tmp==100)
			++nb100;
		else
			++nb200;
	}
	if(nb100%2==0 && (nb200%2==0 || nb100>0))
		cout << "YES\n";
	else
		cout << "NO\n";
}