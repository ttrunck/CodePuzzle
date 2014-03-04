#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>

using namespace std;

void aux(double n, vector<vector<double>>& mem){
	for(double n1=0;n1<=n;++n1)
		for(double n2=0;n2<=n;++n2){
			if(n1 == 0 && n2 == 0) continue;
			double res = 1;
			double p1 = (n-n1)/n * (n-n2)/n;

			if(n1!=0 && n2!=n){
				double p2 = n1/n * (n-n2)/n;
				res += p2*(mem[n1-1][n2]);
			}

			if(n1!=n && n2!=0){
				double p3 = (n-n1)/n * n2/n;
				res += p3*(mem[n1][n2-1]);				
			}

			if(n1!=0 && n2!=0){
				double p4 = n1/n * n2/n;
				res += p4*(mem[n1-1][n2-1]);
			}
			mem[n1][n2] = res/(1-p1);
		}
	}

int main(){
	int n, m;
	cin >> n >> m;
	set<int> h, v;
	for(int i=0;i<m;++i){
		int a,b;
		cin >> a >> b;
		h.insert(a);
		v.insert(b);
	}

	int n1 = n-h.size(), n2 = n-v.size();
	vector<vector<double> > mem(n+1, vector<double>(n+1, 0));

	aux(n, mem);

	cout << mem[n1][n2] << '\n';
}