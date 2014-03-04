#include<iostream>
#include<utility>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

inline bool align(const pair<double, double> & a, const pair<double, double> & b, const pair<double, double> & c){
  return (abs((b.first-a.first)*(c.second-a.second)-(b.second-a.second)*(c.first-a.first))<1e-8);
}

int main(){
  int T;
  cin >> T;
  for(int icase= 1;icase<=T;++icase){
    int N;
    cin >> N;
    vector<pair<double, double> > t(N);
    for(int i=0;i<N;++i)
      cin >> t[i].first >> t[i].second;

    sort(t.begin(), t.end());
    t.resize(unique(t.begin(), t.end())-t.begin());
    N=t.size();

    cout << "Data set #" << icase << " contains ";
    if(N==1)
      cout << "a single gnu.\n";
      else{
	int res=2;
	for(int i=0;i<N;++i)
	  for(int j=i+1;j<N;++j){
	    int tmp=2;
	    for(int k=j+1;k<N;++k)
	      if(align(t[i], t[j], t[k])) tmp++;
	    res=max(res, tmp);
	  }
	cout << N << " gnus, out of which a maximum of " << res << " are aligned.\n";
      }
  }
}

