#include<iostream>
#include<map>

using namespace std;

int cycle(int z, int i, int m, int l){
  map<int,int> mem;
  int compt=1;
  while(mem.find(l)==mem.end()){
    mem[l]=compt++;
    l=(z*l+i)%m;
  }
  return compt-mem.find(l)->second;
}

int main(){
  int z,i,m,l;
  int icase=1;
  while(cin >> z >> i >> m >> l && (z||i||m||l)){
    cout << "Case " << icase++ << ": " << cycle(z,i,m,l) << '\n';
  }
}
