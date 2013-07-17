#include<iostream>

using namespace std;

int main(){
  int t;
  cin >> t;
  for(int icase=1;icase<=t;++icase){
    cout << "Case " << icase << ": ";
    int n;
    cin >> n;
    int mini=0;
    for(int i=0;i<n;++i){
      int tmp;
      cin >> tmp;
      mini=max(mini, tmp);
    }
    cout << mini << '\n';
  }
}
