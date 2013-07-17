#include<iostream>
#include<vector>
#include<set>

using namespace std;

int pere(int m, vector<int> & f){
  if(f[m]==m) return m;
  int tmp=pere(f[m], f);
  f[m]=tmp;
  return tmp;
}

void join(int n, int l, vector<int> & t, vector<int> & f){
  if(t[n]!=0){
    int a=pere(t[n], f);
    int b=pere(l, f);
    f[b]=a;
  }
  
  t[n]=pere(l, f);
}

int main(){
  int n,m;
  cin >> n >> m;
  
  vector<int> t(n,0);
  vector<int> f(m+1);
 for(int i=0;i<m+1;++i)
   f[i]=i;

  for(int i=0;i<n;++i){
    int nb;
    cin >> nb;
    for(int j=0;j<nb;++j){
      int tmp;
      cin >> tmp;
      join(i, tmp, t, f);
    }
  }

  for(int i=0;i<n;++i)
    cerr << t[i] << ' ';
  cerr << endl;

  int res=0;
  set<int> s;
  for(int i=0;i<n;++i){
    if(t[i]!=0)
      s.insert(pere(t[i],f));
    else
      res++;
  }
  if(s.size()==0)
    cout << res << '\n';
  else
    cout << res+s.size()-1 << '\n';

}
