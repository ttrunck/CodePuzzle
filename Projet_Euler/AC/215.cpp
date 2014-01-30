#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

template<typename T>
void pv(const vector<T>& t){
  for(const T& x:t)
    cerr << x << ' ';
  cerr << endl;
}

bool comp(const vector<int>& t1, const vector<int>& t2){
  int i=1, j=1;
  int c1=t1[0], c2=t2[0];
  while(i<int(t1.size()) && j<int(t2.size())){
    if(c1==c2) return false;
    if(c1<c2){
      c1+=t1[i];
      ++i;
    }
    else{
      c2+=t2[j];
      ++j;
    }
  }
  return true;
}

int main(){
  vector<vector<int> > line;
  int n2=16, n3=0;
  do{
    vector<int> t;
    for(int i=0;i<n2;++i)
      t.push_back(2);
    for(int i=0;i<n3;++i)
      t.push_back(3);
    do{
      vector<int> tmp(t);
      line.push_back(tmp);
    }while(next_permutation(begin(t), end(t)));
  n2-=3;
  n3+=2;
  }while(n2>=0);

  vector<vector<int> > next(line.size());
  for(int i=0;i<int(line.size());++i)
    for(int j=i+1;j<int(line.size());++j)
      if(comp(line[i], line[j])){
	next[i].push_back(j);
	next[j].push_back(i);
      }

  /*
  for(int i=0;i<int(line.size());++i){
    pv(line[i]);
  for(int x:next[i])
    pv(line[x]);
  cerr << "=======\n";
  }
  */

  vector<vector<ll> > nb(10, vector<ll>(line.size()));

  for(int i=0;i<int(line.size());++i)
    nb[0][i]=1;

  for(int i=1;i<10;++i)
    for(int j=0;j<int(line.size());++j)
      for(int k=0;k<int(next[j].size());++k)
	nb[i][j] += nb[i-1][next[j][k]];

  //for(int i=0;i<5;++i)
  //  pv(nb[i]);

  ll res=0;
  for(int i=0;i<int(line.size());++i)
    res+=nb[9][i];

  cout << res << '\n';
}
