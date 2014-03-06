#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

typedef long long ll;

string s="UDDDUdddDDUDDddDdDddDDUDDdUUDd";
const ll N = 1000000000000000ll;

ll aux(ll x){
	for(char c:s){
		if(c=='D') x = 3*x;
		else if(c=='d'){
			if((3*x+1)%2!=0) return -1;
			x = (3*x+1)/2;
		}
		else{
			if((3*x-2)%4!=0) return -1;
			x = (3*x-2)/4;
		}
	}
	return x;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	reverse(begin(s), end(s));
	
	ll x=0;
	while(aux(x)<N) ++x;
	cout << aux(x) << '\n';
	
}