#include<iostream>
#include<vector>
#include<string>

using namespace std;

string mot;
vector<vector<int> > t;
string best;
int val;

int c(char ch){
  switch(ch){
  case 'A':
    return 1;
  case 'C':
    return 2;
  case 'G':
    return 3;
  case 'T':
    return 4;
  }
}

char ci(int n){
  switch(n){
  case 1:
    return 'A';
  case 2:
    return 'C';
  case 3:
    return 'G';
  case 4:
    return 'T';
  }
}

void add(int a, int b, int start){
  if(start==t.size())
    t.push_back(vector<int>(5,0));
  t[start][0]++;
  if(a>=b) return;
  if(t[start][c(mot[a])]==0){
    t[start][c(mot[a])]=t.size();
    add(a+1,b,t.size());
  }
  else
    add(a+1,b,t[start][c(mot[a])]);
}

void dfs(int start, const string & curr){
  if(curr.size()>best.size()){
    best=curr;
    val=t[start][0];
  }
  for(int i=1;i<5;++i)
    if(t[start][i]!=0)
      if(t[t[start][i]][0]>1){
	dfs(t[start][i], curr+ci(i));
    }
}

int main(){
  int T;
  cin >> T;
  while(T--){
    cin >> mot;
    t.clear();
    best="";
    val=0;
    for(int i=0;i<mot.size();++i)
      add(i, mot.size(), 0);

    dfs(0,"");
    
    if(val>1)
      cout << best << ' ' << val << endl;
    else
      cout << "No repetitions found!" << endl;
  }
}
