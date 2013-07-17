#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <queue>

using namespace std;

const int inf=100000000;
const int vidage=20000000;
int n;

double magic=1;

struct pos{
  double x,y,z;
};

vector< pos > tab;

double risk[70000];
bool visited[70000];
double vidage_queue[70000];

double R;

int nb_point;

double dist_fun(int aa, int bb){
  pos a= tab[aa];
  pos b= tab[bb];
  double lata=M_PI/2 - acos(a.z/R); //dans -pi/2;pi/2
  double longa=atan2(a.x, a.y); //dans -pi;pi
   double latb=M_PI/2 - acos(b.z/R);
  double longb=atan2(b.x, b.y);
  return (acos(cos(lata)*cos(latb)*cos(longb-longa)+sin(lata)*sin(latb)))/M_PI;
}

double risk_fun(int aa, int bb){
  double tmp= dist_fun(aa, bb);
  return tmp*tmp;
}

struct vert{
  int num;
  double dist;
  vert(int n, double d): num(n), dist(d) {};
};

struct comp{
  bool operator()(vert & v1, vert &v2){
    return (v1.dist>v2.dist);
  };
};

void relacher(int u, int v, double w){
  double d2= risk[u]+w;
  if ((risk[v]<0)||(risk[v]>d2)){
    risk[v]=d2;
  }
}

double dijkstra(int start, int dest){
  priority_queue<vert, vector<vert>, comp> q;
  int u;
  for(int i=0;i<nb_point;++i){
    risk[i]=-1;
    visited[i]=false;
  }
  
  risk[start]=0;
  q.push(vert(start,0));
  while(!q.empty()){
    //cout << "taille queue=" << q.size() << '\n';
    
    if(q.size()>vidage){
      cout << "taille queue=" << q.size() << '\n';
      for(int i=0;i<70000;++i)
	vidage_queue[i]=inf;
      int taille= q.size();
      for(int i=0;i<taille;++i){
	int tmp= q.top().num;
	vidage_queue[tmp]= min(vidage_queue[tmp], q.top().dist);
	q.pop();
      }
      for(int i=0;i<70000;++i)
	if(vidage_queue[i]<inf)
	  q.push(vert(i,vidage_queue[i]));

cout << "taille queue=" << q.size() << '\n';
    }

u=q.top().num;
    if (u==dest) return q.top().dist;
    q.pop();
    if(!visited[u]){
      for(int v=0;v<nb_point;++v){
	  double risk_tmp= risk_fun(u,v);
	  if (risk_tmp<=magic){
	    relacher(u,v, risk_tmp);
	  if(!visited[v]) q.push(vert(v, risk[v]));
	}
	}
    }
    visited[u]=true;
  }
  return -1;
}


int main(){
  double res=0;
  R=1;
  for(n=1;n<=15;++n){
    R= pow(2,n)-1;
    tab.clear();
  for(int i=0;i<=R;++i)
    for(int j=0;j<=R;++j){
      int k= sqrt(R*R-i*i-j*j);
	if (i*i+j*j+k*k==R*R){
	  pos tmp;
	  tmp.x=i; tmp.y=j;tmp.z=k;
	  tab.push_back(tmp);
	   if(k!=0){
	  k=-k;
	  tmp.x=i; tmp.y=j;tmp.z=k;
	  tab.push_back(tmp);
	  }
	  
	}
    }
  nb_point=tab.size();
  if (n>=10)
    magic= 0.003;
  if (n>=12)
    magic= 0.0003;

  cout << "nb_point: " << nb_point << '\n';
  cout << "magic: " << magic << '\n';

  double tmp= dijkstra(0,1);
  

  cout << "R=" << R << ' ' << setprecision(11) << tmp << '\n';
  res+= tmp;
  }
  cout << "res:" << setprecision(11) << res << '\n';
  }
