#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

typedef long long ent;

bool is_voyel(char c){
  return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}

bool ok(int start, int taille, const string & s){
  for(int i=0;i<taille;++i)
    if(is_voyel(s[start+i])) return false;
  return true;
}

int main(){
  int nbcase;
  cin >> nbcase;
  for(int icase=1;icase<=nbcase;++icase){
    cout << "Case #" << icase << ": ";
    string s;
    ent n;
    cin >> s >> n;
    ent L=s.size();
    ent last=-1;
    ent res=0;
    for(ent i=0;i<L-n+1;++i){
      if(ok(i, n, s)){
	res+=(i-last)*(L-i-n+1);
	last=i;
      }
    }
    cout << res << '\n';
  }
}
