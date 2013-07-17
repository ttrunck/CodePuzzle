#include<iostream>
#include<vector>

using namespace std;

void pv(vector<bool> & t){
  for(int i=1;i<int(t.size());++i)
    cout << t[i] << ' ';
  cout << endl;
}

bool aux(int n, int m){
  vector<bool> curr(n+1,false);
  curr[1]=true;
  bool conti=true;
  int jump=1;

  while(conti){
    conti=false;
    jump+=2;
    vector<bool> newt(n+1,false);
    if(curr[m]) return true;
    for(int i=1;i<=n;++i)
      if(curr[i]){
	if(i+jump<=n){
	  newt[i+jump]=true;
	  conti=true;
	}
	if(i-jump>=0){
	  newt[i-jump]=true;
	  conti=true;
	}
      }
    curr=newt;
  }

  return false;
}

int main(){
  int n, m;
  cin >> n >> m;
  while(n!=0 || m!=0){
    if(n>50 || aux(n,m))
      cout << "Let me try!"<< endl;
    else
      cout << "Don't make fun of me!" << endl;
    cin >> n >> m;
  }
}
