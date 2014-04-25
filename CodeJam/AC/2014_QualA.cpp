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
	
	int nbcase;
	cin >> nbcase;
	for(int icase=1;icase<=nbcase;++icase){
		cout << "Case #" << icase << ": ";

		int n1, n2, t1=0, t2=0;
		cin >> n1;
		for(int i=1;i<=4;++i)
			for(int j=0;j<4;++j){
				int tmp;
				cin >> tmp;
				if(i==n1)
					t1 |= 1<<tmp;
			}
		cin >> n2;
		for(int i=1;i<=4;++i)
			for(int j=0;j<4;++j){
				int tmp;
				cin >> tmp;
				if(i==n2)
					t2 |= 1<<tmp;
			}

		int res = t1 & t2;
		if(res == 0){
			cout << "Volunteer cheated!\n";
			continue;
		}

		bool ok=false;
		for(int i=1;i<=16;++i)
			if(res == (1<<i)){
				cout << i << '\n';
				ok = true;
				break;	
			}

		if(!ok)
			cout << "Bad magician!\n";
	}
}