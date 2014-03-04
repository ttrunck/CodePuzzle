#include<iostream>
#include<string>
#include<queue>

using namespace std;

queue<int> l; 
queue<int> r; 

int main(){
  int cas;
  cin >> cas;
  while(cas--){
    int t,m;
    cin >> t >> m;
    t*=100;
    int nb_traj=0;
    string where="left";
    int chargement=0;

    for(int i=0;i<m;++i){
      string s;
      int a;
      cin >> a >> s;
      if(s=="left")
	l.push(a);
      else
	r.push(a);
    }

    while(!l.empty() || !r.empty()){
      //   cout << curr << ' ' << where << endl;
      if(where=="left"){
	while(!l.empty() && l.front()+chargement <= t){
	  chargement+=l.front();
	  l.pop();
	}
	if(chargement!=0 || !r.empty()){
	    nb_traj++;
	    chargement=0;
	    where="right";
	  }
      }
      else{
	  while(!r.empty() && r.front()+chargement<=t){
	    chargement+=r.front();
	    r.pop();
	  }
	  if(chargement!=0 || !l.empty()){
	    nb_traj++;
	    chargement=0;
	    where="left";
	  }
      }

    }

    cout << nb_traj << endl;
  }
}
