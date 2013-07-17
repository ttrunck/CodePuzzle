#include<iostream>
#include<vector>

using namespace std;

int main(){
  int nbcase;
  cin >> nbcase;
  for(int icase=1;icase<=nbcase;++icase){
    cout << "Case #" << icase << ": ";
    int N;
    cin >> N;
    vector<pair<int, int> > t(N);
    for(int i=0;i<N;++i)
      cin >> t[i].first >> t[i].second;

    int res=0;
    for(int i=0;i<N;++i)
      for(int j=i+1;j<N;++j)
	if((t[i].first-t[j].first)*(t[i].second-t[j].second)<0)
	  res++;
    cout << res << '\n';
  }
}
