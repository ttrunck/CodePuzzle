#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

struct entry {
  int nr[2], p;
};

int cmp(struct entry a, struct entry b){
  return a.nr[0] == b.nr[0] ? (a.nr[1] < b.nr[1] ? 1 : 0) : (a.nr[0] < b.nr[0] ? 1 : 0);
}

void cree_suffix(const string & A, vector<vector<int> > & P){
  int N=A.size();
  vector<entry> L(N);
 
  P.push_back(vector<int>(N));
  for(int i = 0; i < N; i++)
        P[0][i] = A[i] - 'a';
    for(int stp = 1, cnt = 1; cnt >> 1 < N; stp ++, cnt <<= 1){
      P.push_back(vector<int>(N));
      for(int i = 0; i < N; i ++){
	L[i].nr[0] = P[stp - 1][i];
	L[i].nr[1] = i + cnt < N ? P[stp - 1][i + cnt] : -1;
	L[i].p = i;
      }
      sort(L.begin(), L.end(), cmp);
      for(int i = 0; i < N; i ++)
	P[stp][L[i].p] = i > 0 && L[i].nr[0] == L[i - 1].nr[0] && L[i].nr[1] == L[i - 1].nr[1] ?
	  P[stp][L[i - 1].p] : i;
    }
}

int lcp(int x, int y, const vector<vector<int> > & P){
  int N=P[0].size(), stp=P.size();
  int ret = 0;
  if (x == y) return N-x;
  for (int k = stp-1; k>=0 && x<N && y<N; k--)
    if (P[k][x]==P[k][y])
      x+=1<<k, y+=1<<k, ret+=1<<k;
  return ret;
}

int lcp(int x, int y, const string & s){
  int N=s.size();
  int res=0;
  while(x<N && y<N && s[x]!='$' && s[y]!='$' && s[x++]==s[y++])
    res++;
  return res;
}

bool more_half(int n, const vector<int> & chaine){
  int res=0;
  for(int i=0;i<n;++i)
    if(chaine[i]!=0) ++res;
  return 2*res>n;
}

int main(){

  bool first=true;
  int n;
  while(cin >> n && n){
    if(!first)
      cout << '\n';
    first=false;
    vector<int> app;
    string tmp;
    string s;
    for(int i=0;i<n;++i){
      cin >> tmp;
      for(int j=0;j<=int(tmp.size());++j)
	app.push_back(i);
      s+=tmp;
      s+='$';
    }

    vector<vector<int> > t;
    cree_suffix(s, t);
    vector<int> suf(s.size());
    for(int i=0;i<int(suf.size());++i)
      suf[t[t.size()-1][i]]=i;
       
    vector<int> chaine(n,0);
    vector<string> resultat;
    int taillemax=0;
    for(int start=0, end=0;start<int(s.size());++start){
      while(end<int(s.size()) && !more_half(n, chaine)){
	chaine[app[suf[end]]]++;
	end++;
      }
      if(!more_half(n,chaine)) continue;
      int tmp=lcp(suf[start], suf[end-1],s);
      if(tmp>taillemax){
	resultat.clear();
	taillemax=tmp;
      }
      if(tmp>0 && tmp==taillemax)
	resultat.push_back(s.substr(suf[start],tmp));
	
      chaine[app[suf[start]]]--;
    }

    

    sort(resultat.begin(), resultat.end());
    resultat.resize(unique(resultat.begin(), resultat.end())-resultat.begin());

    if(resultat.empty())
      cout << "?\n";
    else{
      for(int i=0;i<int(resultat.size());++i)
	cout << resultat[i] << '\n';
    }
  }
}
