#include<iostream>
#include<vector>
#include<sstream>
#include<string>

using namespace std;

int main(){

  int nbcase;
  cin >> nbcase;
  bool first = true;
  while(nbcase--){
    if(!first)
      cout << '\n';
    first = false;
    int w,n;
    cin >> w >> n;
    cin.ignore();
    vector<vector<bool> > t(w, vector<bool>(n,true));
    for(int i=0;i<w;++i){
      string s;
      getline(cin, s);
      stringstream ss(s);
      int ww,nn;
      ss >> ww;
      while(ss >> nn)
	t[ww-1][nn-1]=false;
    }

    vector<vector<int> > tt(w, vector<int>(n, 0));
    tt[0][0] = 1;
    for(int i=1;i<w;++i){
      if(t[i][0])
	tt[i][0] = tt[i-1][0];
    }

    for(int i=1;i<n;++i)
      if(t[0][i])
	tt[0][i] = tt[0][i-1];

    for(int i=1;i<w;++i)
      for(int j=1;j<n;++j)
	if(t[i][j])
	  tt[i][j] = tt[i-1][j] + tt[i][j-1];

    /*
    for(int i=0;i<w;++i){
      for(int j=0;j<n;++j)
	cerr << tt[i][j] << ' ';
      cerr << '\n';
    }
    */

      cout << tt[w-1][n-1] << '\n';
  }
}
