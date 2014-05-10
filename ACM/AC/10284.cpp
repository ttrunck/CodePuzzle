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

void mark(int i, int j, vector<vector<bool>>& t){
	if(i>=0 && j>=0 && i<8 && j<8)
		t[i][j] = false;
}

bool val(int i, int j, const vector<vector<char>>& t){
	return (i>=0 && j>=0 && i<8 && j<8 && t[i][j]==' ');
}

void lmark(int x, int y, int dx, int dy, const vector<vector<char>>& t, vector<vector<bool>>& occ){
	int curr = 1;
	while(val(x+curr*dx, y+curr*dy, t)){
		mark(x+curr*dx, y+curr*dy, occ);
		++curr;
	}
	dx = -dx;
	dy = -dy;
	curr = 1;
	while(val(x+curr*dx, y+curr*dy, t)){
		mark(x+curr*dx, y+curr*dy, occ);
		++curr;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	while(getline(cin, s)){
		vector<vector<bool>> occ(8, vector<bool>(8, true));
		vector<vector<char>> t(8, vector<char>(8, ' '));
		int i=0, j=0;
		for(char c:s){
			if(isdigit(c))
				j+=c-'0';
			else if(c=='/'){
				assert(j==8);
				j=0;
				++i;
			}
			else{
				t[i][j] = tolower(c);
				if(t[i][j] == 'p')
					t[i][j] = c;
				++j;
			}
		}

		for(int i=0;i<8;++i)
			for(int j=0;j<8;++j){
				char c = t[i][j];
				if(c == ' ') continue;
				mark(i,j,occ);
				if(c == 'p'){
					mark(i+1, j+1, occ);
					mark(i+1, j-1, occ);
				}
				else if(c == 'P'){
					mark(i-1, j+1, occ);
					mark(i-1, j-1, occ);
				}
				else if(c == 'r'){
					lmark(i, j, 1, 0, t, occ);
					lmark(i, j, 0, 1, t, occ);
				}
				else if(c == 'n'){
					mark(i+1, j+2, occ);
					mark(i+2, j+1, occ);
					mark(i+2, j-1, occ);
					mark(i+1, j-2, occ);
					mark(i-1, j-2, occ);
					mark(i-2, j-1, occ);
					mark(i-2, j+1, occ);
					mark(i-1, j+2, occ);
				}
				else if(c == 'b'){
					lmark(i, j, 1, 1, t, occ);
					lmark(i, j, 1, -1, t, occ);
				}
				else if(c == 'q'){
					lmark(i, j, 1, 0, t, occ);
					lmark(i, j, 0, 1, t, occ);
					lmark(i, j, 1, 1, t, occ);
					lmark(i, j, 1, -1, t, occ);
				}
				else{
					assert(c=='k');
					mark(i+1, j+1, occ);
					mark(i+1, j-1, occ);
					mark(i-1, j+1, occ);
					mark(i-1, j-1, occ);
					mark(i, j+1, occ);
					mark(i, j-1, occ);
					mark(i+1, j, occ);
					mark(i-1, j, occ);
				}
			}

		// for(int i=0;i<8;++i){
		// 	for(int j=0;j<8;++j)
		// 		cerr << occ[i][j];
		// 	cerr << endl;
		// }

		int res = 0;
		for(int i=0;i<8;++i)
			for(int j=0;j<8;++j)
				if(occ[i][j])
					++res;
		cout << res << '\n';
	}
}