#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

int main(){
  int nbcase;
  cin >> nbcase;
  while(nbcase--){
    int l,b,n;
    cin >> l >> b >> n;
    vector<bool> t(n);
    for(int i=0;i<n;++i){
      char a;
      cin >> a;
      t[i]=(a=='1');
    }

    int pf=l-1, pb=0, head=b-1;
    ll dist=0;
    while(pf!=n-1){

      int curr=pf+1;
      int npf=pf;
      while(curr<=head){
	if(t[curr]){
	  npf=curr;
	}
	curr++;
      }
      if(npf==pf){
	dist=-1;
	break;
      }

      int planche=0;
      for(int i=pf;i<npf;++i)
	if(t[i])
	  planche++;
      
      pf=npf;

      while(planche--){
	++pb;
	while(!t[pb]) ++pb;
      }
      int nhead = min(n-1,pb+b-1);
      dist+=l+nhead-head;
      
      head=nhead;
      
    }

    if(dist<0)
      cout << "IMPOSSIBLE\n";
    else
      cout << dist << '\n';

  }
}
