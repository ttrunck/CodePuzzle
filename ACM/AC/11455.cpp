#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ent;

int main(){
  int n;
  cin >> n;
  while(n--){
    vector<ent> t(4);
    for(int i=0;i<4;++i)
      cin >> t[i];
    sort(t.begin(), t.end());
    if(t[0]==t[3]) cout << "square\n";
    else if(t[0]==t[1] && t[2]==t[3]) cout << "rectangle\n";
    else if(t[0]+t[1]+t[2]>t[3]) cout << "quadrangle\n";
    else cout << "banana\n";
  }
}
