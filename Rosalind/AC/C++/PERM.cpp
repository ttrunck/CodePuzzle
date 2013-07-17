#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int fact(int n){
  return (n==1)?1:n*fact(n-1);
}

int main(){
  int n;
  cin >> n;
  vector<int> t(n);
  for(int i=0;i<n;++i)
    t[i]=i+1;
  cout << fact(n) << '\n';
  do{
    for(int i=0;i<int(t.size())-1;++i)
      cout << t[i] << ' ';
    cout << t[t.size()-1] << endl;
  }while(next_permutation(t.begin(), t.end()));
}
