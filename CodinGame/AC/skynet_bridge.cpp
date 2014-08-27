#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cassert>

using namespace std;

typedef long long ll;

bool pos_down(int i, const vector<int>& y){
	return y[i]<3-(int(y.size())-i-1);
}

bool pos_up(int i, const vector<int>& y){
	return y[i]>i;
}

bool crash(int x, int y, int s, const vector<string>& t)
{
	for(int i=1;i<=s;++i)
		if(x+i<int(t[y].size()) && t[y][x+i] == '0')
			return true;
	return false;
}

bool aux(int v, int s, int x, vector<int> y, const vector<string>& t, int d, vector<string>& res)
{
	if(int(y.size())<v || d<0)
		return false;
	if(x>int(t[0].size()))
		return true;

	res.push_back("");

	//speed
	{
	res.back() = "SPEED";
	vector<int> ny;
	for(int i=0;i<int(y.size());++i)
		if(!crash(x,y[i],s+1,t))
			ny.push_back(y[i]);
	if(aux(v, s+1, x+s+1, ny, t, d-1, res))
		return true;
	}

	//slow
	if(s>1) {
		res.back() = "SLOW";
		vector<int> ny;
		for(int i=0;i<int(y.size());++i)
			if(!crash(x,y[i],s-1,t))
				ny.push_back(y[i]);
		if(aux(v, s-1, x+s-1, ny, t, d-1, res))
			return true;
	}

	//jump
	if(s>0) {
		res.back() = "JUMP";
		vector<int> ny;
		for(int i=0;i<int(y.size());++i)
			if(x+s>int(t[0].size()) || t[y[i]][x+s]!='0')
				ny.push_back(y[i]);
		if(aux(v, s, x+s, ny, t, d-1, res))
			return true;
	}

	//up
	if(s>0) {
	res.back() = "UP";
	vector<int> ny;
	for(int i=0;i<int(y.size());++i){
		if(pos_up(i, y)){
			if(!crash(x,y[i],s-1,t) && !crash(x,y[i]-1,s,t))
				ny.push_back(y[i]-1);
		}
		else if(!crash(x,y[i],s,t))
			ny.push_back(y[i]);
	}
	if(aux(v, s, x+s, ny, t, d-1, res))
		return true;
	}

	//down
	if(s>0) {
	res.back() = "DOWN";
	vector<int> ny;
	for(int i=0;i<int(y.size());++i){
		if(pos_down(i, y)){
			if(!crash(x,y[i],s-1,t) && !crash(x,y[i]+1,s,t))
				ny.push_back(y[i]+1);
		}
		else if(!crash(x,y[i],s,t))
			ny.push_back(y[i]);
	}
	if(aux(v, s, x+s, ny, t, d-1, res))
		return true;
	}

	res.pop_back();
	return false;
}

int main()
{
	int m, v;
	cin >> m >> v;
	cin.ignore();
	vector<string> t(4);
	cerr << m << ' ' << v << endl;
	for(int i=0;i<4;++i){
		getline(cin, t[i]);
		cerr << t[i] << endl;
	}
	int s;
	cin >> s;
	cerr << s << endl;
	int x = 0;
	vector<int> y(m);

	for(int i=0;i<m;++i){
		int a,b,c;
		cin >> a >> b >> c;
		y[i] = b;
		cerr << a << ' ' << b << ' ' << c << endl;
	}
	sort(begin(y), end(y));
	vector<string> res;

	assert(aux(v, s, x, y, t, 50, res));

	for(string& s:res)
		cout << s << '\n';
}