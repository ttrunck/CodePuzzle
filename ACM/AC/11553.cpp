#include<iostream>
#include<algorithm>

using namespace std;

int t[8][8];
int a[8];
int b[8];
int size;

int aux(){
  int res=100000000;
  sort(a,a+8);
  do{
    int curr=0;
    for(int i=0;i<size;++i)
      curr+=t[i][a[i]];
    res=min(res,curr);
  }while(next_permutation(a,a+size));
  return res;
}

int main(){
  for(int i=0;i<8;++i){
    a[i]=i;
    b[i]=i;
  }

  int nbcas;
  cin >> nbcas;
  for(int cas=0;cas<nbcas;++cas){
    cin >> size;
    for(int i=0;i<size;++i)
      for(int j=0;j<size;++j)
	cin >> t[i][j];
    cout << aux() << endl;
  }
}
