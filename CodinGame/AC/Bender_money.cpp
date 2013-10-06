#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<limits>

using namespace std;

const int NEG_INF=numeric_limits<int>::min();

int aux(const string& start, map<string, vector<string> >& from, map<string, int >& money, map<string, int>& mem){
  if(mem[start]!=0) return mem[start];
  
  int res=(start=="0")?0:NEG_INF;
  for(auto pred:from[start])
    res=max(res, aux(pred, from, money, mem)+money[pred]);

  return mem[start]=res;
}

int main(){
  int n;
  cin >> n;
  map<string, int> mem;
  map<string, vector<string> > from;
  map<string, int > money;
  for(int i=0;i<n;++i){
    string in, out1, out2;
    int found;
    cin >> in >> found >> out1 >> out2;
    from[out1].push_back(in);
    from[out2].push_back(in);
    money[in]=found;
  }
  cout << aux("E", from, money, mem) << '\n';
}
