#include<iostream>
#include<vector>

using namespace std;

int main(){
  int n, d;
  cin >> n >> d;
  vector<int> obj(n);
  for(int i=0;i<n;++i)
    cin >> obj[i];

  int sum=0;
  for(int x:obj)
    sum+=x;

  vector<bool> pos(sum+1, false);
  pos[0]=true;
  for(int i=0;i<n;++i)
    for(int j=sum;j>=0;--j)
      if(pos[j])
	pos[j+obj[i]]=true;

  int day=0, res=0;
  bool cont=true;
  while(cont){
    cont=false;
    for(int nres=min(res+d, sum);nres>res;--nres)
      if(pos[nres]){
	cont=true;
	++day;
	res=nres;
	break;
      }
  }
  
  cout << res << ' ' << day << '\n';

}
