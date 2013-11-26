#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

typedef long long ll;

int main(){
  int n,m,p;
  cin >> n >> m >> p;
  vector<int> a(n);
  for(int i=0;i<n;++i)
    cin >> a[i];
  vector<int> b(m);
  for(int i=0;i<m;++i)
    cin >> b[i];

  vector<ll> res;

  for(int i=0;i<p;++i){
    ll mm=m;
    if(i+(mm-1)*p>=n) continue;
    multiset<int> bb, aa;
    for(int x:b)
      bb.insert(x);
    for(int j=0;j<mm;++j){
      cerr << n << ' ' << i+j*p << endl;
      cerr << a[i+j*p] << endl;
      
      auto it=bb.find(a[i+j*p]);
      if(it!=end(bb))
      	bb.erase(it);
      else
      aa.insert(a[i+j*p]);
    }
    if(bb.empty())
      res.push_back(i);
    
    ++mm;
    while(i+(mm-1)*p<n){
      auto it=aa.find(a[i+(mm-1-m)*p]);
      if(it!=end(aa))
	aa.erase(it);
      else
	bb.insert(a[i+(mm-1-m)*p]);

      it = bb.find(a[i+(mm-1)*p]);
      if(it!=end(bb))
	bb.erase(it);
      else
	aa.insert(a[i+(mm-1)*p]);
      
      if(bb.empty())
	res.push_back(i+(mm-m)*p);
    
      ++mm;
    }

  }

  sort(begin(res), end(res));

  cout << res.size() << '\n';
  for(int i=0;i<int(res.size());++i)
    cout << res[i]+1 << ((i==int(res.size())-1)?'\n':' ');
}
