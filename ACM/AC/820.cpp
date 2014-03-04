#include<iostream>
#include<limits>
#include<vector>
#include<queue>

using namespace std;

const int N=109;
int n,s,t,c;

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
    for(int i=0;i<aug_path.size()-1;++i)
      cf=min(cf, t_cap[aug_path[i+1]][aug_path[i]]);

    for(int i=0;i<aug_path.size()-1;++i){
      t_cap[aug_path[i+1]][aug_path[i]]-=cf;
      t_cap[aug_path[i]][aug_path[i+1]]+=cf;
      flot[aug_path[i+1]][aug_path[i]]+=cf;
      flot[aug_path[i]][aug_path[i+1]]-=cf;
    }
  }
}

int main(){
  int nbnet=1;
  cin >> n;
  while(n!=0){
    cin >> s >> t >> c;
    for(int i=0;i<=n;++i)
      for(int j=0;j<=n;++j)
	t_cap[i][j]=flot[i][j]=0;

    for(int i=0;i<c;++i){
      int t1,t2,t3;
      cin >> t1 >> t2 >> t3;
      t_cap[t1][t2]+=t3;
      t_cap[t2][t1]+=t3;
    }

    ford();

    int band=0;
    for(int i=1;i<=n;++i)
      band+=flot[s][i];
    cout << "Network " << nbnet++ << endl;
    cout << "The bandwidth is " << band << '.' << endl << endl;
  
    cin >> n;
  }
}
