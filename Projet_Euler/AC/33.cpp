#include <iostream>

using namespace std;

bool simpl(int i, int j){
  int d1=j/10, d2=j%10;
  int n1=i/10, n2=i%10;
  if(n1!=0 && n1==d1 && n2*j==d2*i) return true;
  if(n1!=0 && n1==d2 && n2*j==d1*i) return true;
  if(n2!=0 && n2==d1 && n1*j==d2*i) return true; 
  if(n2!=0 && n2==d2 && n1*j==d1*i) return true;
  return false;
}

int main(){
  for(int i=10;i<100;++i)
    for(int j=i+1;j<100;++j){
      if(simpl(j,i)) cout << i << ' ' << j << '\n';
    }
  /*La réponse est alors clairement 100*/
}
