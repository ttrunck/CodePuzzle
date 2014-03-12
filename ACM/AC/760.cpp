#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

using namespace std;

typedef long long ll;

struct entry{
  pair<int, int> p;
  int pos;

  bool operator<(const entry & b) const{
    return p<b.p;
  }
};

//calcule le CSA de la chaine s et le stocke dans la matrice p.
//Attention lors de l'appel p doit etre vide.
void concrete_suffix(const string & s, vector<vector<int> > & p){
  int N=s.size();
 
  //premiere ligne, l'ordre n'est pas exact, mais verifie la propriete essentielle
  //que deux chaines egale ont meme position.
  p.push_back(vector<int>(N));
  for(int i = 0; i < N; i++)
    p[0][i] = s[i] - 'a';
  
  //stp est le compteur d'etape, k la taille de la chaine.
  for(int stp = 1, k = 1; k/2 < N; ++stp, k *=2 ){
    p.push_back(vector<int>(N));
    vector<entry> tmp(N);
    for(int i = 0; i < N; i ++){
      tmp[i].p.first = p[stp - 1][i];
      //attention, si on sort du tableau on remplit avec des petits caracteres
      tmp[i].p.second = i + k < N ? p[stp - 1][i + k] : -1;
      tmp[i].pos = i;
    }

    //on utilise un tri en nln(n), on peut ameliorer l'algorithme en utilisant
    //un radix_sort sur p.second puis un radix_sort stable sur p.first
    sort(tmp.begin(), tmp.end());
   
    //on remplit la nouvelle ligne de p, en autorisant les egalites de positions
    p[stp][tmp[0].pos]=0; 
    for(int i = 1; i < N; i ++)
      p[stp][tmp[i].pos]=(tmp[i].p==tmp[i-1].p)?p[stp][tmp[i-1].pos]:i; 
  }
}

//construit le SA dans suf a partir de la chaine s et du CSA p.
//attention construire le SA est peu efficace, il occupe un espace memoire O(n^2)
//en vrai il est plus malin de garder uniquement l'indice de depart du ieme suffixe
//il est ensuite immediat (avec s.substr) de construire le suffixe.
void suffix(const vector<vector<int> > & p, const string & s, vector<int> & suf){
  suf=vector<int>(s.size());
  for(int i=0;i<int(s.size());++i)
  suf[p[p.size()-1][i]]=i;
}

int lcp(int x, int y, const vector<vector<int> > & p, const string & s){
  if(x==y) return s.size()-x;
  //une heuristique pour gagner du temps si les chaines ne commencent pas par la meme lettre.
  if(s[x]!=s[y]) return 0;
  int res=0;
  int k=p.size()-1;
  while(k>=0 && x<int(s.size()) && y<int(s.size())){
    if(p[k][x]==p[k][y]){
      res+= (1<<k);
      x+= (1<<k);
      y+= (1<<k);
    }
    k--;
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s, t;
  bool first = true;
  while(getline(cin, s)){
    getline(cin, t);
    if(!first)
      cout << '\n';
    first = false;
    int ns = s.size();
    s += '.';
    s += t;
    getline(cin, t);
    vector<vector<int>> p;
    concrete_suffix(s, p);
    vector<int> suf;
    suffix(p, s, suf);

    set<string> res;
    int maxi = 1;
    for(int i=0;i<int(suf.size())-1;++i)
      if(min(suf[i], suf[i+1])<ns && max(suf[i], suf[i+1])>ns){
        int tmp = lcp(suf[i], suf[i+1], p, s);
        if(tmp>maxi){
          maxi = tmp;
          res.clear();
        }
        if(tmp == maxi)
          res.insert(s.substr(suf[i], lcp(suf[i], suf[i+1], p, s)));
      }

    if(!res.empty()){
      for(const string& s:res)
        cout << s << '\n';
    }
    else{
      cout << "No common sequence." << '\n';
    }
  }
}