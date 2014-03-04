#include<iostream>
#include<string>
#include <sstream>
#include<vector>

using namespace std;

typedef unsigned long long ent;

const ent N=1e18;

void aux(int n, vector<int> & t){
  int curr=2;
  while(n!=1){
    if(n%curr==0){
      t[curr]++;
      n/=curr;
    }
    else
      curr++;
  }
}

ent diviseur(int n, int k){
  vector<int> t(n+1,0);
  while(n>0){
    aux(n,t);
    n-=k;
  }

  ent res=1;
  for(int i=0;i<int(t.size());++i){
    if(res>N) return N+1;
    res*=t[i]+1;
  }
  return res;
}

int main(){
  int cas;
  cin >> cas;
  cin.ignore();
  for(int icas=1;icas<=cas;++icas){
    cout << "Case " << icas << ": ";
    string line;
    getline(cin, line);
    istringstream buff(line);
    int n;
    buff >> n >> line;
    
    ent res=diviseur(n, line.size());
    if(res>N)
      cout << "Infinity\n";
    else
      cout << res << '\n';
  }
}
