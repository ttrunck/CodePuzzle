#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
  int T;
  cin >> T;
  for(int icase=1;icase<=T;++icase){
    cout << "Case " << icase << ": ";
    int N, D;
    cin >> N >> D;
    vector<int> t;
    t.push_back(0);
    t.push_back(0);
    t.push_back(D);
    t.push_back(D);
    for(int i=0;i<N;++i){
      char c;
      int tmp;
      cin  >> c;
      if(c=='B'){
	cin >> c >> tmp;
	t.push_back(tmp);
	t.push_back(tmp);
      }
      else{
	cin >> c >> tmp;
	t.push_back(tmp);
      }
    }

    sort(t.begin(), t.end()); 
    int res=0;
    for(int i=2;i<int(t.size());i+=2)
      res=max(res, t[i]-t[i-2]);
    for(int i=3;i<int(t.size());i+=2)
      res=max(res, t[i]-t[i-2]);
    cout << res << '\n';
  }
}
