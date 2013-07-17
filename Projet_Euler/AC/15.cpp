#include <iostream>

using namespace std;

long long mem[25][25];

long long count(int i, int j){
  if(i==0 || j==0) return 1;
  if(mem[i][j]!=-1) return mem[i][j];
  else{
    mem[i][j]=count(i,j-1)+count(i-1,j);
    return mem[i][j];
  }
}

int main(){
  for(int i=0;i<25;i++)
    for(int j=0;j<25;++j)
      mem[i][j]=-1;


  cout << count(20,20) << '\n';

}
