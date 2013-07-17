#include<iostream>
#include<vector>

using namespace std;

int count(int s, const vector<vector<int> >& tt, vector<int>& res){
  if(s==0) return 1;
  if(res[s]!=-1) return res[s];
  
  int r=0;
  for(int i=0;i<int(tt[s].size());++i)
    r+=count(tt[s][i], tt, res);


  return res[s]=r;
}

int main(){
  bool first=true;
  int n;
  while(cin >> n){
    if(!first)
      cout << '\n';
    first=false;
    vector<vector<int> > t(n);
    vector<vector<int> > tt(n);
    vector<int> res(n,-1);
    for(int i=0;i<n;++i){
      int k;
      cin >> k;
      for(int j=0;j<k;++j){
	int tmp;
	cin >> tmp;
	tt[tmp].push_back(i);
	t[i].push_back(tmp);
      }
    }

    int rres=0;
    for(int i=0;i<n;++i)
      if(t[i].size()==0)
	rres+=count(i,tt,res);
    
    cout << rres << '\n';

    /*
    for(int i=0;i<int(res.size());++i)
      cerr << res[i] << ' ';
    cerr << '\n';
    */
  }
}
