#include<iostream>
#include<vector>

using namespace std;

bool same(const vector<int>& t, const vector<int>& tt, int nb){
  for(int i=0;i<int(t.size());++i){
    if(t[i]<tt[i]) return false;
    if((t[i]-tt[i])%2!=0) return false;
    nb-=(t[i]-tt[i])/2;
  }

  return nb==0;
}

int main(){
  int nbcase;
  cin >> nbcase;
  while(nbcase--){
    int n;
    cin >> n;
    vector<int> t(n), tt(n);
    for(int i=0;i<n;++i)
      cin >> t[i];
    for(int i=0;i<n;++i)
      cin >> tt[i];

    int power=n-2;
    int sumt=0, sumtt=0;
    for(int x:t)
      sumt+=x;
    for(int x:tt)
      sumtt+=x;

    if(n==1){
      if(t[0]<tt[0])
	cout << -1 << '\n';
      else
	cout << abs(t[0]-tt[0]) << '\n';
    }

    else if(n==2){
      if(sumt!=sumtt)
	cout << -1 << '\n';
      else
	cout << abs(t[0]-tt[0]) << '\n';
    }
    
    else{
      int nbbottle=((sumtt-sumt)%power==0)?(sumtt-sumt)/power:-1;
      if(nbbottle<0)
	cout << -1 << '\n';
      else{
	  for(int i=0;i<n;++i)
	    t[i]+=nbbottle;
	  if(same(t, tt, nbbottle))
	  cout << nbbottle << '\n';
	else
	  cout << -1 << '\n';
      }
    }
  }
}
