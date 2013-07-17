#include<iostream>
#include<algorithm>

using namespace std;

int tab[]={0,1,2,3,4,5,6,7,8,9};

int main(){
  for(int i=0;i<999999;++i)
    next_permutation(tab,tab+10);

  for(int i=0;i<10;++i)
    cout << tab[i];
  cout << '\n';
  
}
