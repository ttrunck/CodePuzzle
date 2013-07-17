//This code is bad, we could do this in O(n)

#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

typedef pair<int, int> pi;

int dist(int s, int p, const vector<vector<pi> >& t){
  int res=0;
  for(int i=0;i<int(t[s].size());++i){
    if(p==t[s][i].first) continue;
    res=max(res, t[s][i].second+dist(t[s][i].first, s, t));
  }

  return res;
}

int main(){
  vector<vector<pi> > t(10000);
  string s;
  while(getline(cin, s)){
    //cerr << s << '\n';
    if(s!=""){
      stringstream ss(s);
      int a,b,k;
      ss >> a >>b >> k;
      t[a-1].push_back(pi(b-1, k));
      t[b-1].push_back(pi(a-1, k));
    }
    else{
      int maxi=0;
      for(int i=0;i<10000;++i)
	maxi=max(maxi, dist(i, i, t));
      cout << maxi << '\n';
      t.clear();
      t.resize(10000);
    }
  }

  int maxi=0;
      for(int i=0;i<10000;++i)
	maxi=max(maxi, dist(i, i, t));
      cout << maxi << '\n';

}
