#include<iostream>
#include<string>
#include<queue>
#include<utility>

using namespace std;

int arr[10009];

queue<pair<int,int> > l; 
queue<pair<int,int> > r; 

int main(){
  int cas;
  cin >> cas;
  while(cas--){
    int n,t,m;
    cin >> n >> t >> m;

    int curr=0;
    string where="left";
    int chargement=0;

    for(int i=0;i<m;++i){
      string s;
      int a;
      cin >> a >> s;
      if(s=="left")
	l.push(make_pair(a,i));
      else
	r.push(make_pair(a,i));
    }

    while(!l.empty() || !r.empty()){
      //   cout << curr << ' ' << where << endl;
      if(where=="left"){
	  while(!l.empty() && l.front().first <=curr && chargement<n){
	    arr[l.front().second]=curr+t;
	    chargement++;
	    l.pop();
	  }
	  if(chargement!=0 || (!r.empty() && r.front().first<=curr)){
	    curr+=t;
	    chargement=0;
	    where="right";
	  }
	  else
	    curr++;
      }
      else{
	  while(!r.empty() && r.front().first <=curr && chargement<n){
	    arr[r.front().second]=curr+t;
	    chargement++;
	    r.pop();
	  }
	  if(chargement!=0 || (!l.empty() && l.front().first<=curr)){
	    curr+=t;
	    chargement=0;
	    where="left";
	  }
	  else
	    curr++;
      }

    }

    for(int i=0;i<m;++i)
      cout << arr[i] << endl;
    if(cas!=0)
      cout << endl;
  }
}
