#include<iostream>
#include<vector>
#include<utility>
#include<cmath>
#include<string>
#include<bitset>
#include<iomanip>
#include<limits>

using namespace std;

inline double dist(const pair<int, int> & a, const pair<int, int> & b){
  return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}

vector<double> mem;
int N;

double aux(const vector<pair<int, int> > & t, const int mask){
  if(mask==0) return 0;
  if(mem[mask]!=-1) return mem[mask];
  bitset<16> tab(mask);
  //  cerr << mask << ' ' << tab << endl;
  double res=numeric_limits<double>::max();
  for(int i=0;i<16;++i)
    if(tab[i])
      for(int j=i+1;j<16;++j)
	if(tab[j]){
	  tab[i]=false;
	  tab[j]=false;
	  //	  cerr << aux(t, int(tab.to_ulong())) << endl;
	  //cerr << "dist " << dist(t[i], t[j]) << endl;
	  res=min(res, dist(t[i], t[j])+aux(t, int(tab.to_ulong())));
	  tab[i]=true;
	  tab[j]=true;
	}
 return mem[mask]=res;
}

int main(){
  int cas=1;
  string stmp;
  while(cin >> N && N!=0){
    mem=vector<double>(2<<(2*N),-1);
    vector<pair<int, int> > t(2*N);
    for(int i=0;i<2*N;++i)
      cin >> stmp >> t[i].first >> t[i].second;


    cout << "Case " << cas++ << ": " << setprecision(2) << fixed << aux(t, (1<<(2*N))-1) << endl;
  }
}
