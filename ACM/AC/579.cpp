#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	double h, m;
	char tmp;
	while(cin >> h >> tmp >> m && (h || m)){
		if(h==12) h=0;
		double d1 = (h + m/60)*360/12;
		double d2 = m*360/60;
		double res = min(abs(d1-d2), 360-abs(d1-d2));
		cout << fixed << setprecision(3) << res << '\n';
	}
}