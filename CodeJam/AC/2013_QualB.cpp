#include<iostream>
#include<vector>

using namespace std;

bool check(const vector<vector<int> > & t, const vector<vector<int> > & res){
  for(int i=0;i<int(t.size());++i)
    for(int j=0;j<int(t[i].size());++j)
      if(t[i][j]!=res[i][j])
	return false;
  return true;
}

int main(){
  int T;
  cin >> T;
  for(int icase=1;icase<=T;++icase){
    cout << "Case #" << icase << ": ";
    int N,M;
    cin >> N >> M;
    vector<vector<int> > t(N, vector<int>(M));
    for(int i=0;i<N;++i)
      for(int j=0;j<M;++j)
	cin >> t[i][j];

    vector<vector<int> > res(N, vector<int>(M, 100));

    for(int i=0;i<N;++i){
      int maxi=t[i][0];
      for(int j=0;j<M;++j)
	maxi=max(maxi, t[i][j]);
      for(int j=0;j<M;++j)
	res[i][j]=min(res[i][j], maxi);
    }

    for(int j=0;j<M;++j){
      int maxi=t[0][j];
      for(int i=0;i<N;++i)
	maxi=max(maxi, t[i][j]);
      for(int i=0;i<N;++i)
	res[i][j]=min(res[i][j], maxi);
    }


    if(check(t, res))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
