#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int const N=40;

int tar[N];

struct edge{
  int ext1, ext2, weight;
  edge(int e1, int e2, int w): ext1(e1),ext2(e2),weight(w){};
};

vector<edge> edges;

bool inf(edge a, edge b){
  return (a.weight< b.weight);
}

int find(int e){
  int p=tar[e];
  if(p<0) return e;
  else{
    int root=find(p);
    tar[e]=root;
    return root;
  }
}

void fusion(int a, int b){
  tar[find(b)]=find(a);
}

int main(){
  int poid_tot=0;
  for(int i=0;i<N;++i)
    for(int j=0;j<N;++j){
      int tmp;
      cin >> tmp;
      if(tmp!=-1 && i<j){
	edges.push_back(edge(i,j,tmp));
	poid_tot+=tmp;
      }
    }

  for(int i=0;i<N;++i)
    tar[i]=-1;

  sort(edges.begin(), edges.end(), inf);

  vector<edge>::iterator it=edges.begin();
  int c=0;
  int res=0;
  while(c<N-1){
    if(find(it->ext1)!=find(it->ext2)){
      res+=it->weight;
      fusion(it->ext1, it->ext2);
      ++c;
    }
    ++it;
  }

  cout << poid_tot-res << endl;
}
