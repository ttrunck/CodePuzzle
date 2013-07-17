#include<iostream>
#include<vector>

using namespace std;

typedef pair<int, int> pi;

inline bool inter(const pi & a, const pi & b){
  // cerr << a.first << ' ' << a.second << ' ' << b.first << ' ' << b.second << '\n';
  return min(a.second,b.second)-max(a.first, b.first)>=1;
}

int main(){
  ios_base::sync_with_stdio(false);
  int N,M;
  while(cin >> N >> M && (N!=0 || M!=0)){
    vector<pi> call(N);
    for(int i=0;i<N;++i){
      int start, duration, t1, t2;
      cin >> t1 >> t2 >> start >> duration;
      call[i]=(pi(start, start+duration));
    }

    for(int i=0;i<M;++i){
      int start,duration;
      cin >> start >> duration;
      pi check(start, start+duration);
      int res=0;
      for(int j=0;j<N;++j)
	if(inter(check, call[j])) res++;
      cout << res << '\n';
    }
  }
}
