#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

vector<string> solution;

bool ok(const string & s){
  //on a juste à vérifier les diagonales
  for(int i=0;i<7;++i)
    for(int j=i+1;j<8;++j){
      if(j-i==abs(s[i]-s[j])) return false;
    }
  return true;
}

void init(){
  string s="12345678";
  do{
    if(ok(s))
      solution.push_back(s);
  }while(next_permutation(s.begin(), s.end()));
}

int main(){
  init();
  //  sort(solution.begin(), solution.end());

  int cas;
  cin >> cas;
  bool first=true;
  while(cas--){
    int a,b;
    cin >> b >> a;
    
    if(first)
      first=false;
    else
      cout << endl;
    cout << "SOLN       COLUMN" << endl;
    cout << " #      1 2 3 4 5 6 7 8" << endl << endl;

    int compt=1;
    for(int i=0;i<int(solution.size());++i)
      if(solution[i][a-1]-'0'==b){
	if(compt<10) cout << ' ';
	cout << compt++ << "     ";
	for(int j=0;j<8;++j)
	  cout << ' ' << solution[i][j];
	cout << endl;
      }

  }
}
