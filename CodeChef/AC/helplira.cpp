#include<iostream>

using namespace std;

int main(){
  int n;
  cin >> n;
  int maxi=0, mini=1000000000, imaxi=-1, imini=-1;
  for(int i=1;i<=n;++i){
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    
    int tmp=abs((x2-x1)*(y3-y1)-(y2-y1)*(x3-x1));

    //cerr << tmp << endl;

    if(tmp<=mini){
      imini=i;
      mini=tmp;
    }
    if(tmp>=maxi){
      imaxi=i;
      maxi=tmp;
    }
  }

  cout << imini << ' ' << imaxi << endl;
}
