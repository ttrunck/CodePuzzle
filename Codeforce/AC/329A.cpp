#include<iostream>
#include<vector>

using namespace std;

bool okl(int n, const vector<vector<bool> >& t, int i){
  for(int j=0;j<n;++j)
    if(t[i][j])
      return true;
  return false;
}

bool okligne(int n, const vector<vector<bool> >& t){
  for(int i=0;i<n;++i)
    if(!okl(n,t,i))
      return false;
  return true;
}

bool okc(int n, const vector<vector<bool> >& t, int j){
  for(int i=0;i<n;++i)
    if(t[i][j])
      return true;
  return false;
}

bool okcol(int n, const vector<vector<bool> >& t){
  for(int j=0;j<n;++j)
    if(!okc(n,t,j))
      return false;
  return true;
}

int main(){
  int n;
  cin >> n;
  vector<vector<bool> > t(n, vector<bool>(n));
  for(int i=0;i<n;++i)
    for(int j=0;j<n;++j){
      char tmp;
      cin >> tmp;
      t[i][j]=(tmp=='.');
    }

  if(okligne(n,t)){
    for(int i=0;i<n;++i){
      int j=0;
      while(!t[i][j]) ++j;
      cout << i+1 << ' ' << j+1 << '\n';
    }
  }
  else if(okcol(n,t)){
    for(int j=0;j<n;++j){
      int i=0;
      while(!t[i][j]) ++i;
      cout << i+1 << ' ' << j+1 << '\n';
    }
  }
  else
    cout << -1 << '\n';
}
