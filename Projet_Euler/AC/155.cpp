#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	set<double> s;
	s.insert(60);

	for(int i=0;i<19;++i){
		set<double> ns;
		for(double x:s){
			ns.insert(x+60);
			ns.insert(60*x/(60+x));
		}
		for(double x:ns)
			s.insert(x);
		cout << s.size() << '\n';
	}
	
}