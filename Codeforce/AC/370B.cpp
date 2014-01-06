#include<iostream>
#include<vector>
#include<set>

using namespace std;

bool inclu(const set<int>& s, const set<int>& t){
  for(int x:s)
    if(t.find(x)==end(t))
      return false;
  return true;
}

int main(){
  int n;
  cin >> n;
  vector<set<int> > t(n);
  for(int i=0;i<n;++i){
    int m;
    cin >> m;
    for(int j=0;j<m;++j){
      int tmp;
      cin >> tmp;
      t[i].insert(tmp);
    }
  }

  for(int i=0;i<n;++i){
    bool ok=true;
    for(int j=0;j<n;++j){
      if(i==j) continue;
      if(inclu(t[j], t[i])){
	ok=false;
	break;
      }
    }
    if(ok)
      cout << "YES\n";
    else
      cout << "NO\n";
  }

}
