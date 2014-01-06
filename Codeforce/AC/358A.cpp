#include<iostream>
#include<vector>

using namespace std;

bool inter(int a, int b, int c, int d){
  int e=min(a,b), f=max(a,b), g=min(c,d), h=max(c,d);
  return (e<g && g<f && f<h) || (g<e && e<h && h<f);
}

int main(){
  int n;
  cin >> n;
  vector<int> t(n);
  for(int i=0;i<n;++i)
    cin >> t[i];

  for(int i=0;i<n-1;++i)
    for(int j=i+1;j<n-1;++j)
      if(inter(t[i], t[i+1], t[j], t[j+1])){
	cout << "yes\n";
	return 0;
      }
    
  cout << "no\n";
}
