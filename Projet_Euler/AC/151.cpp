#include<iostream>
#include<map>
#include<vector>
#include<iomanip>

using namespace std;

double aux(const vector<int>& t, map<vector<int>, double> mem){
  if(mem.find(t)!=end(mem)) return mem[t];

  double res=0;

  double sum = t[0]+t[1]+t[2]+t[3];

    if(sum==1 && t[3]!=1)
      res++;

  for(int i=0;i<4;++i)
    if(t[i]!=0){
      vector<int> tt{t};
      tt[i]--;
      for(int j=i+1;j<4;++j)
	tt[j]++;
      res+= double(t[i])/sum * aux(tt, mem);
    }


  return mem[t]=res;
}

int main(){
  vector<int> t{1,1,1,1};
  map<vector<int>, double> mem;

  cout << fixed << setprecision(6) << aux(t, mem) << '\n';
}
