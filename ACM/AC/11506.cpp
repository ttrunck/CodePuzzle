#include<iostream>
#include<limits>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;


const int N=109;
int n,s=1,t;
int m,w;

int t_cap[N][N];
int flot[N][N];
vector<int> aug_path;
int pred[N];

bool BFS(){
  aug_path.clear();
  for(int i=0;i<=n;++i)
    pred[i]=-1;
  queue<int> q;
  q.push(s);
  pred[s]=s;

  while(!q.empty()){
    int curr=q.front();
    q.pop();
    if(curr==t)
      break;
    for(int i=1;i<=n;++i)
      if(t_cap[curr][i]>0 && pred[i]==-1){
	pred[i]=curr;
	q.push(i);
      }
  }

  bool res=(pred[t]!=-1);
  if(res){
    int curr=t;
    while(pred[curr]!=curr){
      aug_path.push_back(curr);
      curr=pred[curr];
    }
    aug_path.push_back(s);
  }
 
  /* 
  for(int i=0;i<aug_path.size();++i)
    cerr << aug_path[i] << ' ';
  cerr << endl;
  */
  return res;
}

void ford(){
  while(BFS()){
    int cf=numeric_limits<int>::max();
    for(int i=0;i<int(aug_path.size())-1;++i)
      cf=min(cf, t_cap[aug_path[i+1]][aug_path[i]]);

    for(int i=0;i<int(aug_path.size())-1;++i){
      t_cap[aug_path[i+1]][aug_path[i]]-=cf;
      t_cap[aug_path[i]][aug_path[i+1]]+=cf;
      flot[aug_path[i+1]][aug_path[i]]+=cf;
      flot[aug_path[i]][aug_path[i+1]]-=cf;
    }
  }
}

int main(){
  cin >> m >> w;
  while(m!=0 || w!=0){
    n=2*m;
    t=n;

    for(int i=0;i<=n;++i)
      for(int j=0;j<=n;++j)
	t_cap[i][j]=flot[i][j]=0;

    for(int i=2;i<=m-1;++i){
      int t1,t2;
      cin >> t1 >> t2;
        t_cap[2*t1-1][2*t1]=t2;
    }

    for(int i=0;i<w;++i){
      int t1,t2,t3;
      cin >> t1 >> t2 >> t3;
      t_cap[t1*2][t2*2-1]=t3;
      t_cap[t2*2][t1*2-1]=t3;
    }
    
    t_cap[1][2]=numeric_limits<int>::max();
    t_cap[2][1]=numeric_limits<int>::max();
    t_cap[t][t-1]=numeric_limits<int>::max();
    t_cap[t-1][t]=numeric_limits<int>::max();
    /*
    for(int i=1;i<=t;++i){
      for(int j=1;j<=t;++j)
	cerr << t_cap[i][j] << ' ';
      cerr << endl;
      }
    */  
ford();

    int band=0;
    for(int i=1;i<=n;++i)
      band+=flot[s][i];
    cout << band << endl;
  
    cin >> m >> w;
  }
}
