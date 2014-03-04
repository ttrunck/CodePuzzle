#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string>

using namespace std;

typedef long long ll;

const ll INF=1000000ll*1000000ll;

ll compute(ll a, ll b, ll nba){
	ll nbb = nba+1;
	ll res = 0;

	res += nba-1 + (a-nba+1)*(a-nba+1);

	res -= (b%nbb) * (b/nbb+1)*(b/nbb+1);
	res -= (nbb-(b%nbb)) * (b/nbb)*(b/nbb);
	
	return res;
}

void print(int a, int b, int nba){
	int nbb = nba+1;

	for(int i=0;i<b/nbb;++i)
		cout << 'x';
	b -= b/nbb;
	nbb--;
	if(a){
	for(int i=0;i<a-nba+1;++i)
		cout << 'o';
	a -= a-nba+1;
	}
	while(nbb){
		for(int i=0;i<b/nbb;++i)
			cout << 'x';
		b -= b/nbb;
		nbb--;		
		if(a){
			cout << 'o';
			a -= 1;
		}
	}
cout << '\n';
}

int main(){
	int a, b;
	cin >> a >> b;

	ll maxi=-INF;
	int nba=0;
	for(int i=(a?1:0);i<=a;++i)
		if(compute(a,b,i)>maxi){
			maxi=compute(a,b,i);
			nba=i;
		}


		cout << maxi << '\n';
		cerr << nba << '\n';
		print(a,b,nba);

}