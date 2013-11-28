#include<iostream>
#include<vector>

using namespace std;

bool check(vector<int> t, vector<vector<int> >& op){
  for(auto& o:op){
    if(o[0]==1)
      for(int i=o[1];i<=o[2];++i)
	t[i]+=o[3];
    else{
      int maxi=t[o[1]];
      for(int i=o[1];i<=o[2];++i)
	maxi=max(maxi, t[i]);
      if(maxi!=o[3])
	return false;
    }
  }
  return true;
}

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> res(n+1, 1e9);
  vector<int> diff(n+1, 0);
  vector<vector<int> > op(m, vector<int>(4));

  for(int i=0;i<m;++i){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    op[i][0]=a;
    op[i][1]=b;
    op[i][2]=c;
    op[i][3]=d;
    if(a==1)
      for(int i=b;i<=c;++i)
	diff[i]-=d;
    
    else
      for(int i=b;i<=c;++i)
	res[i]=min(res[i], d+diff[i]);
   
  }

  if(check(res, op)){
    cout << "YES\n";
    for(int i=1;i<=n;++i)
      cout << res[i] << ' ';
    cout << '\n';
  }
  else
    cout << "NO\n";
}
