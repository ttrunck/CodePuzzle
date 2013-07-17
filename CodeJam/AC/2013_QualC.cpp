#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<sstream>
#include<gmpxx.h>
#include<algorithm>

using namespace std;

typedef mpz_class ent;

bool palin(const ent & n){
  string s=n.get_str();
  int taille=int(s.size());
  for(int i=0;i<(taille+1)/2;++i)
    if(s[i]!=s[taille-1-i])
      return false;
    return true;
}

void aux(string & s, int taille, int pos, vector<ent> & t, bool used){
  if(2*pos>=taille){
    ent tmp(s);
    ent res=tmp*tmp;
    if(palin(res))
      t.push_back(res);
  }
  else{
    s[pos]='0',s[taille-1-pos]='0';
    aux(s, taille, pos+1, t, used);
    s[pos]='1',s[taille-1-pos]='1';
    aux(s, taille, pos+1, t, used);
    if(!used && pos*2+1==taille){
      s[pos]='2',s[taille-1-pos]='2';
      aux(s, taille, pos+1, t, true);
    }
  }
}

void precompute(vector<ent> & t, int taille){
  t.push_back(1);
  t.push_back(4);
  t.push_back(9);

  for(int i=2;i<=taille;++i){
    string s(i, '0');
    s[0]='1',s[i-1]='1';
    aux(s, i, 1, t, false);
    s[0]='2',s[i-1]='2';
    aux(s, i, 1, t, true);
  }
}

int main(){
  ios::sync_with_stdio(false);
  vector<ent> t;
  precompute(t, 50);
  
  int T;
  cin >> T;
  for(int icase=1;icase<=T;++icase){
    cout << "Case #" << icase << ": ";
    ent A, B;
    cin >> A >> B;
    int res= upper_bound(begin(t), end(t), B)-lower_bound(begin(t), end(t), A);
    cout << res << '\n';
  }
}
