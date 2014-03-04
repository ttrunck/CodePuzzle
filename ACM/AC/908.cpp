#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

vector<pair<int, pair<int,int> > > t;
int tab[1000009];

bool mysort(pair<int, pair<int,int> > a, pair<int, pair<int,int> > b){
    return a.first<b.first;
}

    int find(int a){
      if(tab[a]==a) return a;
      int tmp=find(tab[a]);
      tab[a]=tmp;
      return tmp;
    }

    bool fusion(int a, int b){
      int aa=find(a), bb=find(b);
      if(aa==bb) return false;
      tab[aa]=bb;
      return true;
    }

int main(){
  bool first=true;
  int N;
  while(cin >> N){
      t.clear();
      for(int i=0;i<=N;++i)
      tab[i]=i;
    int res1=0;
    for(int i=0;i<N-1;++i){
      int a,b,c;
      cin >> a >> b >> c;
      res1+=c;
    }
    int K;
    cin >> K;
    for(int i=0;i<K;++i){
      int a,b,c;
      cin >> a >> b >> c;
      t.push_back(make_pair(c, make_pair(a,b)));
    }
    int M;
    cin >> M;
    for(int i=0;i<M;++i){
      int a,b,c;
      cin >> a >> b >> c;
      t.push_back(make_pair(c, make_pair(a,b)));
    }

    sort(t.begin(), t.end(), mysort);

    int res2=0;
    int cmp=0;
    for(int i=0;i<t.size();++i){
      if(cmp==N-1) break;
      if(fusion(t[i].second.first, t[i].second.second)){
	res2+=t[i].first;
	cmp++;
      }
    }

    if(!first)
      cout << endl;
    first=false;
    cout << res1 << endl << res2 << endl;
  }
}
