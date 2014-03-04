#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<utility>

using namespace std;

struct triple{
  int dist;
  string langue;
  char first_letter;
  
  triple(int d, string l, char f):dist(d),langue(l),first_letter(f){}

  bool operator<(const struct triple & t) const{
    return dist>t.dist;
  }
};

struct tt{
  string langue;
  char first_letter;
  int taille;

  tt(string l, char f, int t):langue(l), first_letter(f), taille(t){}
};

int dij(const string & start,const string & fin, map<string, vector<tt> > & m){
  map<pair<string, char>, bool> visited;
  priority_queue<triple> q;
  for(int i='a';i<='z';++i)
    q.push(triple(0,start,i));
  
  while(!q.empty()){
    triple curr= q.top();
    q.pop();
    if(!visited[make_pair(curr.langue, curr.first_letter)])
      visited[make_pair(curr.langue, curr.first_letter)]=true;
    else
      continue;
    //cout << curr.langue << ' ' << curr.first_letter << ' ' << curr.dist << endl;
    if(curr.langue==fin) return curr.dist;
    for(int i=0;i<m[curr.langue].size();++i){
      tt cu=m[curr.langue][i];
      if(cu.first_letter!=curr.first_letter && !visited[make_pair(cu.langue, cu.first_letter)])
	q.push(triple(curr.dist+cu.taille, cu.langue, cu.first_letter));
    }
  }

  return -1;
}

int main(){
  int M;
  cin >> M;
  while(M!=0){
    string start, fin;
    map<string, vector<tt > > m;
    cin >> start >> fin;
    for(int i=0;i<M;++i){
      string a,b,c;
      cin >> a >> b >> c;
      m[a].push_back(tt(b,c[0],c.size()));
      m[b].push_back(tt(a,c[0],c.size()));
    }

    int res=dij(start, fin, m);
    if(res!=-1)
      cout << res << endl;
    else
      cout << "impossivel" << endl;

    cin >> M;
  }
}
