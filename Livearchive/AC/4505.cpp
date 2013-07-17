#include<iostream>
#include<string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int N;
  bool first=true;
  while(cin >> N && N){
    if(!first)
      cout << '\n';
    first=false;
    int p1=0, p2=0;
    for(int i=0;i<N;++i){
      string s;
      int m;
      cin >> s >> m;
      if(s[0]=='D'){
	p2+=m;
	cout << "DROP 2 " << m << '\n';
      }
      else{
	if(p1>=m){
	  p1-=m;
	  cout << "TAKE 1 " << m << '\n';
	}
	else{
	  if(p1!=0)
	    cout << "TAKE 1 " << p1 << '\n';
	  m-=p1;
	  p1=p2;
	  cout << "MOVE 2->1 " << p2 << '\n';
	  p2=0;
	  p1-=m;
	  cout << "TAKE 1 " << m << '\n';
	}
      }
    }
  }
}
