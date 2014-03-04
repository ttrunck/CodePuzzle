#include<iostream>
#include<vector>
#include<limits>

using namespace std;

int gcd(int a, int b){
  return (b==0)?a:gcd(b,a%b);
}

int lcm(int a, int b){
  return a/gcd(a,b)*b;
}

int lcm(int a, int b, int c, int d){
  return lcm(a,lcm(b, lcm(c, d)));
}

const int MAXI=numeric_limits<int>::max();

void aux(const vector<int> & t, int m){
  int resmin=-MAXI, resmax=MAXI;

  int s(t.size());
  for(int i=0;i<s;++i)
    for(int j=i+1;j<s;++j)
      for(int k=j+1;k<s;++k)
	for(int l=k+1;l<s;++l){
	  int b=lcm(t[i],t[j],t[k],t[l]);
	  resmin=max(resmin, (m/b)*b);
	  resmax=min(resmax, ((m/b)+((m%b==0)?0:1))*b);
	}

  cout << resmin << ' ' << resmax << '\n';
}

int main(){
  int n,m;
  while(cin >> n >> m && (n||m)){
    vector<int> t(n);
    for(int i=0;i<n;++i)
      cin >> t[i];
    for(int i=0;i<m;++i){
      int tmp;
      cin >> tmp;
      aux(t, tmp);
    }
  }
}
