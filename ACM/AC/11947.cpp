#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <iomanip>

using namespace std;

vector<int> month{31,28,31,30,31,30,31,31,30,31,30,31};

vector<string> zo{"capricorn", "aquarius", "pisces", "aries", "taurus", "gemini",
					"cancer", "leo", "virgo", "libra", "scorpio",
					"sagittarius"};

vector<int> dend{20,19,20,20,21,21,22,21,23,23,22,22,20};
vector<int> mend{1,2,3,4,5,6,7,8,9,10,11,12};

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
	
	int n;
	cin >> n;
	for(int icase=1;icase<=n;++icase){
		string s;
		cin >> s;
		int m = (s[0]-'0')*10 + s[1]-'0';
		int d = (s[2]-'0')*10 + s[3]-'0';
		int y = (s[4]-'0')*1000 + (s[5]-'0')*100 + (s[6]-'0')*10 + (s[7]-'0');
		addDay(40*7,d,m,y);

		int zodiac=0;
		for(int i=0;i<12;++i)
			if(m<mend[i] || (m==mend[i] && d<=dend[i])){
				zodiac = i;
				break;
			}
		cout << icase << ' ';
		cout << setfill('0') << setw(2) << m;
		cout << '/';
		cout << setfill('0') << setw(2) << d;
		cout << '/' << y << ' ' << zo[zodiac] << '\n';
	}
}