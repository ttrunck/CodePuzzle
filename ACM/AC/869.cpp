#include<iostream>
#include<vector>

using namespace std;

bool equi(const vector<vector<bool> >& t1, const vector<vector<bool> >& t2){
  for(int i=0;i<26;++i)
    for(int j=0;j<26;++j)
      if(t1[i][j]!=t2[i][j])
	return false;

  return true;
}

int main(){
  int nbcase;
  cin >> nbcase;
  bool first=true;
  while(nbcase--){
    if(!first)
      cout << '\n';
    first=false;
    vector<vector<bool> > t1(26, vector<bool>(26, false));
    vector<vector<bool> > t2(26, vector<bool>(26, false));
    for(int i=0;i<26;++i)
      t1[i][i]=t2[i][i]=true;

    int n1;
    cin >> n1;
    for(int i=0;i<n1;++i){
      char a,b;
      cin >> a >> b;
      t1[a-'A'][b-'A']=true;
    }
    int n2;
    cin >> n2;
    for(int i=0;i<n2;++i){
      char a,b;
      cin >> a >> b;
      t2[a-'A'][b-'A']=true;
    }

    for(int k=0;k<26;++k)
      for(int i=0;i<26;++i)
	for(int j=0;j<26;++j){
	  if(t1[i][k] && t1[k][j])
	    t1[i][j] = true;
	  if(t2[i][k] && t2[k][j])
	    t2[i][j] = true;
	}

    if(equi(t1, t2))
      cout << "YES\n";
    else
      cout << "NO\n";

  }
}
