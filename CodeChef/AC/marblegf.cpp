#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

ll somme(int x, int y, const vector<ll> & t){
  if(x==0){
    ll res=0;
    while(y>=0){
      res+=t[y];
      y=(y&(y+1))-1;
    }
    return res;
  }
  else
    return somme(0,y,t)-somme(0,x-1,t);
}

void incremente(int x, ll inc, vector<ll> & t) {
  while(x<int(t.size())){
    t[x]+=inc;
    x=x|(x+1);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, Q;
  cin >> N >> Q;
  
  vector<ll> t(N);
  for(int i=0;i<N;++i){
    int tmp;
    cin >> tmp;
    incremente(i, tmp, t);
  }

  for(int i=0;i<Q;++i){
    char c;
    ll a, b;
    cin >> c >> a >> b;

    if(c=='S')
      cout << somme(a,b,t) << '\n';
    else if(c=='G')
      incremente(a,b,t);
    else
      incremente(a,-b,t);
  }

}
