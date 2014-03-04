#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int K,N;

bool ok(vector<int> & t, const vector<string> & inst, const string & s){
  for(int i=0;i<int(t.size());++i)
    if(inst[t[i]]==s) return false;

  int tmp=t.size();
  sort(t.begin(), t.end());
  t.resize(unique(t.begin(), t.end())-t.begin());
  if(tmp!=int(t.size())) return false;
  
  return int(t.size())==K;
}

int main(){
  while(cin >> K >> N && (K!=0 || N!=0)){
    vector<vector<int> > paper(N);
    vector<string> institute(N);
    for(int i=0;i<N;++i){
      cin >> institute[i];
      for(int j=0;j<K;++j){
	int tmp;
	cin >> tmp;
	paper[tmp-1].push_back(i);
      }
    }

    int probleme=0;
    for(int i=0;i<N;++i)
      if(!ok(paper[i], institute, institute[i])) probleme++;

    if(probleme==0)
      cout << "NO PROBLEMS FOUND\n";
    else if(probleme==1)
      cout << "1 PROBLEM FOUND\n";
    else
      cout << probleme << " PROBLEMS FOUND\n";
  }
}
