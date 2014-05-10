#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

int main(){
	int n, m;
	while(cin >> n >> m && (n||m)){
		int res;
		if(min(n, m)==1)
			res = max(n, m);
		else if(min(n, m)==2)
			res = ((max(n, m)/4)*2 + min(max(n, m)%4, 2))*2;
		else
			res = ((n+1)/2)*((m+1)/2) + (n/2)*(m/2);
		printf("%d knights may be placed on a %d row %d column board.\n", res, n, m);
	}
}