#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ent;

ent aux(ent e, ent r, const vector<ent> & t){
  int n=t.size();
  vector<pair<int, int> > ordre(n);
  for(int i=0;i<n;++i)
   ordre[i]=make_pair(-t[i],i);
  sort(ordre.begin(), ordre.end());

  vector<ent> dispo(n,e);
  vector<ent> requis(n,0);
  ent res=0;
  
  for(int i=0;i<n;++i){
    int curr=ordre[i].second;
    int use=dispo[curr]-requis[curr];
    res+=use*t[curr];
    dispo[curr]-=use;
    requis[curr]+=use;

    for(int k=1;k+curr<n;++k)
      dispo[curr+k]=min(dispo[curr+k], dispo[curr]+k*r);
  
    for(int k=1;curr-k>=0;++k)
      requis[curr-k]=max(requis[curr-k], requis[curr]-k*r);

    /*
    for(int i=0;i<n;++i)
      cerr << dispo[i] << ' ';
    cerr << '\n';
    for(int i=0;i<n;++i)
      cerr << requis[i] << ' ';
    cerr << '\n';
    */
  }
  return res;
}

int main(){
 int nbcase;
  cin >> nbcase;
  for(int icase=1;icase<=nbcase;++icase){
    cout << "Case #" << icase << ": ";
    ent e,r,n;
    cin >> e >> r >> n;
    vector<ent> t(n);
    for(int i=0;i<n;++i)
      cin >> t[i];
    cout << aux(e,r,t) << '\n';
  }
}
