#include<iostream>

using namespace std;

int b1, g1, c1, b2, g2, c2, b3, g3, c3;

int main(){
  while(cin >> b1 >> g1 >> c1 >> b2 >> g2 >> c2 >> b3 >> g3 >> c3){
    int res=b2+b3+c1+c3+g1+g2;
    int cas=1;
    
    int tmp=b2+b3+g1+g3+c1+c2;
    if(tmp<res){
      res=tmp;
      cas=2;
    }

    tmp=c2+c3+b1+b3+g1+g2;
    if(tmp<res){
      res=tmp;
      cas=3;
    }

    tmp=c2+c3+g1+g3+b1+b2;
    if(tmp<res){
      res=tmp;
      cas=4;
    }

    tmp=g2+g3+b1+b3+c1+c2;
    if(tmp<res){
      res=tmp;
      cas=5;
    }

    tmp=g2+g3+c1+c3+b1+b2;
    if(tmp<res){
      res=tmp;
      cas=6;
    }
    if(cas==1)
      cout << "BCG " << res << endl;
    else if(cas==2)
      cout << "BGC " << res << endl;
    else if(cas==3)
      cout << "CBG " << res << endl;
    else if(cas==4)
      cout << "CGB " << res << endl;
    else if(cas==5)
      cout << "GBC " << res << endl;
    else if(cas==6)
      cout << "GCB " << res << endl;
  }
}
