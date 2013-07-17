#include<iostream>
#include<vector>

using namespace std;

void rotate(vector<vector<char> > & t, int N){
  vector<vector<char> > tmp(N, vector<char>(N,'.'));
  for(int i=0;i<N;++i){
    int curr=N-1;
    for(int j=N-1;j>=0;--j)
      if(t[i][j]!='.')
	tmp[curr--][N-i-1]=t[i][j];
  }
  t=tmp;
}

bool winaux(const vector<vector<char> > & t, char c, int k, int x, int y, int dx, int dy){
  for(int i=0;i<k;++i)
    if(t[x+i*dx][y+i*dy]!=c)
      return false;
  return true;
}

bool win(const vector<vector<char> > & t, int N, int k, char c){
  for(int i=0;i<=N-k;++i)
    for(int j=0;j<N;++j)
      if(winaux(t, c, k, i, j, 1, 0))
	return true;
  
  for(int i=0;i<N;++i)
    for(int j=0;j<=N-k;++j)
      if(winaux(t, c, k, i, j, 0, 1))
	return true;
  
  for(int i=0;i<=N-k;++i)
    for(int j=0;j<=N-k;++j)
      if(winaux(t, c, k, i, j, 1, 1))
	return true;

for(int i=0;i<=N-k;++i)
    for(int j=k-1;j<N;++j)
      if(winaux(t, c, k, i, j, 1, -1))
	return true;
  
  return false;
}

int main(){
  int nbcase;
  cin >> nbcase;
  for(int icase=1;icase<=nbcase;++icase){
    cout << "Case #" << icase << ": ";
    int N, k;
    cin >> N >> k;
    vector<vector<char> > t(N, vector<char>(N));
    for(int i=0;i<N;++i)
      for(int j=0;j<N;++j)
	cin >> t[i][j];

    /*
    for(int i=0;i<N;++i){
      for(int j=0;j<N;++j)
	cerr << t[i][j];
      cerr << endl;
    }
    */
    rotate(t, N);
    /*
    cerr << "Et la rotation\n";

 for(int i=0;i<N;++i){
      for(int j=0;j<N;++j)
	cerr << t[i][j];
      cerr << endl;
    }
    */
    bool b=win(t, N, k, 'B');
    bool r=win(t, N, k, 'R');
    if(b&&r)
      cout << "Both\n";
    else if(b&&!r)
      cout << "Blue\n";
    else if(!b&&r)
      cout << "Red\n";
    else
      cout << "Neither\n";

  }
}
