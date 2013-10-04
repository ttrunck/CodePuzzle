#include<iostream>
#include<vector>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> t(n);
  for(int i=0;i<n;++i)
    cin >> t[i];

  int nb=0;
  for(int i=0;i<n;++i)
    for(int j=1;j<n;++j)
      if(t[j-1]>t[j]){
	nb++;
	swap(t[j-1], t[j]);
      }

  //cerr << nb << '\n';
  if(nb%2==1)
    cout << 1+2*(nb-1) << endl;
  else
    cout << 2*nb << endl;
}
