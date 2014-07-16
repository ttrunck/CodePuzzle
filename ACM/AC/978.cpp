#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <random>
#include <set>
#include <sstream>
#include <cassert>
#include <queue>

using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;
	for(int icase=0;icase<N;++icase){
		if(icase!=0)
			cout << '\n';
		int B, SG, SB;
		cin >> B >> SG >> SB;
		priority_queue<int> qg, qb;
		for(int i=0;i<SG;++i){
			int tmp;
			cin >> tmp;
			qg.push(tmp);
		}
		for(int i=0;i<SB;++i){
			int tmp;
			cin >> tmp;
			qb.push(tmp);
		}

		int winner=-1;
		bool cont = true;
		while(cont){
			vector<int> tg, tb;
			for(int i=0;i<B;++i){
				if(qb.empty() && qg.empty()){
					if(i!=0) continue;
					winner = 0;
					cont = false;
				}
				else if(qb.empty()){
					if(i!=0) continue;
					winner = 1;
					cont = false;
				}
				else if(qg.empty()){
					if(i!=0) continue;
					winner = 2;
					cont = false;
				}
				else{
					int b = qb.top();
					qb.pop();
					int g = qg.top();
					qg.pop();
					if(b>g)
						tb.push_back(b-g);
					else if(g>b)
						tg.push_back(g-b);
				}
			}
			for(int x:tg)
				qg.push(x);
			for(int x:tb)
				qb.push(x);
		}

		if(winner==0)
			cout << "green and blue died\n";
		else if(winner==1){
			cout << "green wins\n";
			while(!qg.empty()){
				cout << qg.top() << '\n';
				qg.pop();
			}
		}
		else{
			cout << "blue wins\n";
			while(!qb.empty()){
				cout << qb.top() << '\n';
				qb.pop();
			}
		}
	}
}