#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

 map<char, int> last_pos;

typedef long long ll;

ll wait(const string& s){
  last_pos.clear();
   for(int i=0;i<int(s.size());++i)
    last_pos[s[i]]=i;
  ll res=0;
  for(int i=0;i<int(s.size());++i)
    res+=last_pos[s[i]]-i;
  return 5*res;
}

bool mysort(char a, char b){
  return last_pos[a]<last_pos[b];
}

int main(){
  int nbcase;
  cin >> nbcase;
  while(nbcase--){
    int taille;
    cin >> taille;
    string s;
    cin >> s;
    
    ll dep = wait(s);
    sort(s.begin(), s.end(), mysort);
    ll fin = wait(s);
    cout << dep-fin << '\n';
  }
}
