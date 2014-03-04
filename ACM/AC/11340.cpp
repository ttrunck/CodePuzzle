#include<iostream>
#include<string>
#include<map>
#include<iomanip>

using namespace std;

int main(){
  int cas;
  string line;
  cin >> cas;
  while(cas--){
    int k;
    cin >> k;
    map<char, int> m;
    for(int i=0;i<k;++i){
      char a;
      int c;
      cin >> a >> c;
      m[a]=c;
    }
    int M;
    cin >> M;
    cin.ignore();
    int res=0;
    for(int i=0;i<M;++i){
      getline(cin, line);
      for(int j=0;j<int(line.size());++j)
	res+=m[line[j]];
    }
    cout << fixed << setprecision(2) << double(res)/100 << '$' << endl;
  }
}
