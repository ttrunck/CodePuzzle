#include<iostream>
#include<vector>

using namespace std;

bool fin(const vector<vector<char> > & t){
  for(int i=0;i<4;++i)
    for(int j=0;j<4;++j)
      if(t[i][j]=='.')
	return false;
  return true;
}

bool wonaux(const vector<vector<char> > & t, char X, int x, int y, int a, int b){
  for(int i=0;i<4;++i)
    if(t[x+a*i][y+b*i]!='T' && t[x+a*i][y+b*i]!=X)
       return false;
    return true;
}

bool won(const vector<vector<char> > & t, char x){
  for(int i=0;i<4;++i)
    if(wonaux(t, x, 0, i, 1, 0))
      return true;
  for(int i=0;i<4;++i)
    if(wonaux(t, x, i, 0, 0, 1))
      return true;
  if(wonaux(t, x, 0, 0, 1, 1))
    return true;
  if(wonaux(t, x, 3, 0, -1, 1))
    return true;
  return false;
}

int main(){
  int T;
  cin >> T;
  for(int icase=1;icase<=T;++icase){
    cout << "Case #" << icase << ": ";
    vector<vector<char> > t(4, vector<char>(4));
    for(int i=0;i<4;++i)
      for(int j=0;j<4;++j)
	cin >> t[i][j];
    if(won(t, 'X'))
      cout << "X won\n";
    else if(won(t, 'O'))
      cout << "O won\n";
    else if(fin(t))
      cout << "Draw\n";
    else
      cout << "Game has not completed\n";
  }
}
