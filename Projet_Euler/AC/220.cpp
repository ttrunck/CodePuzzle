#include<iostream>
#include<vector>

using namespace std;

typedef long long ent;

const ent N=50;
const ent P=1000000000000;

struct dir{
  ent x, y, d;
  dir(ent xx=0, ent yy=0, ent dd=0):x(xx),y(yy),d(dd){};
};
  
vector<ent> apas(N+1);
vector<ent> bpas(N+1);
vector<dir> a(N+1);
vector<dir> b(N+1);

void aux(dir & start, const dir & eff){
  if(start.d==0){
    start.x+=eff.x;
    start.y+=eff.y;
  }
  else if(start.d==1){
    start.x+=eff.y;
    start.y-=eff.x;
  }
  else if(start.d==2){
    start.x-=eff.x;
    start.y-=eff.y;
  }
  else{
    start.x-=eff.y;
    start.y+=eff.x;
 }
  start.d=(start.d+eff.d)%4;
}

const dir R(0,0,1);
const dir F(0,1,0);
const dir L(0,0,3);

void pas(dir & curr, long p, ent l, bool est_dans_a){

  cerr << "curr: " << curr.x << ' ' << curr.y << ' ' << curr.d << endl;
  cerr << "p,l,a: " << p << ' ' << l << ' ' << ((est_dans_a)?'a':'b') << endl;
  cerr << "pas: " << apas[l] << ' ' << bpas[l] << endl;

if(est_dans_a){
    if(apas[l]>p)
      pas(curr, p, l-1, est_dans_a);
    else{
      aux(curr, a[l]);
      p-=apas[l];
      if(p==0) return;
      aux(curr, R);
      if(bpas[l]>p)
	pas(curr, p, l-1, !est_dans_a);
      else{
	aux(curr, b[l]);
	p-=bpas[l];
	if(p==0) return;
	aux(curr, F);
	p--;
	if(p==0) return;
	aux(curr, R);
      }
    }
  }
  else{
    aux(curr, L);
    aux(curr, F);
    p--;
    if(p==0) return;
    if(apas[l]>p)
      pas(curr, p, l-1, !est_dans_a);
    else{
      aux(curr, a[l]);
      p-=apas[l];
      if(p==0) return;
      aux(curr, L);
      if(bpas[l]>p)
	pas(curr, p, l-1, est_dans_a);
      else{
	aux(curr, b[l]);
	p-=bpas[l];
	if(p==0) return;
      }
    }
  }
}

int main(){
  
  for(ent i=1;i<=N;++i){
    apas[i]=apas[i-1]+bpas[i-1]+1;
    bpas[i]=apas[i-1]+bpas[i-1]+1;
    
    dir curr(0,0,0);
    aux(curr, a[i-1]);
    aux(curr, R);
    aux(curr, b[i-1]);
    aux(curr, F);
    aux(curr, R);
    a[i]=curr;

    curr= dir(0,0,0);
    aux(curr, L);
    aux(curr, F);
    aux(curr, a[i-1]);
    aux(curr, L);
    aux(curr, b[i-1]);
    b[i]=curr;
  }

  for(int i=0;i<N;++i)
  cerr << apas[i] << ' ';
  cerr << endl;

  dir curr(0,1,0);
  pas(curr, P-1, N, true);
  
  cout << curr.x << ' ' << curr.y << ' ' << curr.d << endl;
  cout << curr.x << ',' << curr.y << endl;
}
