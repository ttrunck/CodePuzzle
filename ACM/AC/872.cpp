#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

void aux(int s, const vector<vector<int> >& t, vector<vector<int> >& res, vector<bool>& seen, vector<int>& acc ){
  
  for(int i=0;i<int(t[s].size());++i)
    if(!seen[t[s][i]])
      return;
  seen[s]=true;
  acc.push_back(s);
  
  bool fin=true;
  for(int i=0;i<int(seen.size());++i)
    if(!seen[i]){
      fin=false;
      aux(i,t,res,seen,acc);
    }
  
  if(fin)
    res.push_back(acc);
  
  seen[s]=false;
  acc.pop_back();

}

int main(){
  int nb;
  cin >> nb;
  cin.ignore();
  bool first=true;
  string s;
  while(getline(cin, s)){
    getline(cin, s);
    if(!first)
      cout << '\n';
    first=false;
    stringstream ss(s);
    map<char, int> to_ver;
    vector<char> from_ver;
    char c;
    int comp=0;
    while(ss >> c){
      to_ver[c]=comp++;
      from_ver.push_back(c);
    }

    getline(cin, s);
    stringstream sss(s);
    char a,b, tmp;
    vector<vector<int> > t(comp);
    while(sss >> a >> tmp >> b){
      t[to_ver[b]].push_back(to_ver[a]);
    }

    vector<vector<int> > res;
    vector<bool> seen(comp, false);
    vector<int> acc;

    for(int i=0;i<comp;++i)
      aux(i, t, res, seen, acc);
        
    if(!res.empty()){

      vector<string> ress(res.size());
      for(int i=0;i<int(res.size());++i){
	ress[i]+=from_ver[res[i][0]];
	for(int j=1;j<int(res[i].size());++j){
	  ress[i]+=" ";
	  ress[i]+=from_ver[res[i][j]];
	}
      }

    sort(ress.begin(), ress.end());
    
    for(int i=0;i<int(ress.size());++i){
      cout << ress[i] << '\n';
    }

  
    }
    else
      cout << "NO\n";
    
  }
}
