#include<iostream>
#include<vector>
#include<set>

using namespace std;

struct triple{
  int a,b;
  double p;
  triple(double pp=0, int aa=0, int bb=0):a(aa),b(bb), p(pp){};
};

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector<triple> t(n);
    for(int i=0;i<n;++i){
      cin >> t[i].p >> t[i].a >> t[i].b;
      t[i].p/=100;
    }
    if(n>16) cout << "0\n";
    else{
      double res=0;
      for(int i=0;i<1<<n;++i){
	set<int> s; 
	int tmp=i;
	for(int j=0;j<n;++j){
	  if(tmp%2==0)
	    s.insert(t[j].a);
	  else
	    s.insert(t[j].b);
	  tmp/=2;
	}

	if(int(s.size())!=n)
	  continue;
	tmp=i;
	double proba=1;
	for(int j=0;j<n;++j){
	  if(tmp%2==0)
	    proba*=t[j].p;
	  else
	    proba*=(1-t[j].p);
	  tmp/=2;
	}
	res+=proba;
      }
      cout << res << '\n';
    }
  }
}
