#include<iostream>
#include<vector>
#include<set>

using namespace std;

bool ok(int k, int p, const vector<int>& t){

  int bset = (1 << k) - 1;
  while (bset < (1<<p)) {
    set<int> s;
    for(int x:t)
      s.insert(x&bset);
    if(s.size()==t.size())
      return true;

    // Gosper's hack:
    int c = bset & -bset;
    int r = bset + c;
    bset = (((r^bset) >> 2) / c) | r;
  }
  return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while(T--){
    int p, n;
    cin >> p >> n;
    vector<int> t(n);
    for(int i=0;i<n;++i)
      for(int j=0;j<p;++j){
	int b;
	cin >> b;
	t[i]|=b<<j;
    }

    for(int k=1;k<=p;++k)
      if(ok(k,p,t)){
	cout << k << '\n';
	break;
      }
  }
}
