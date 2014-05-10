#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

vector<int> month{31,28,31,30,31,30,31,31,30,31,30,31};

bool isLeap(int y){
	if(y%400 == 0) return true;
	if(y%100 == 0) return false;
	if(y%4 == 0) return true;
	return false;
}

void addDay(int n, int& d, int& m, int& y){
	n +=d-1;
	for(int i=0;i<m-1;++i){
		if(i==1 && isLeap(y))
			++n;
		n += month[i];
	}
	d = 1;
	m = 1;
	while(n>= 365+(isLeap(y)?1:0)){
		n -= 365+((isLeap(y))?1:0);
		++y;
	}
	while(n>=month[m-1] + ((m==2 && isLeap(y))?1:0)){
		n -= month[m-1] + ((m==2 && isLeap(y))?1:0);
		++m;
	}
	d += n;

}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, d, m , y;
	while(cin >> n >> d >> m >> y && (n||d||m||y)){
		addDay(n,d,m,y);
		cout << d << ' ' << m << ' ' << y << '\n';
	}
}