#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int L,H;
  string T;
  cin >> L >> H;
  cin.ignore();
  getline(cin,T);
  vector<string> m(H);
  
  for(int i=0;i<H;++i)
    getline(cin, m[i]);
  
  transform(begin(T), end(T), begin(T), ::toupper); 

  for(int i=0;i<H;++i){
    for(int j=0;j<int(T.size());++j)
      if(isalpha(T[j]))
	for(int k=0;k<L;++k)
	  cout << m[i][L*int((T[j]-'A'))+k];
      else
	for(int k=0;k<L;++k)
	  cout << m[i][L*int('Z'-'A'+1)+k];
    cout << '\n';
  }
}
