#include<cmath>
#include<cstdio>
#include<iostream>

using namespace std;

const int N=1024009;
const int QN=1024;
bool t[N];

struct section {
  int b, e, v, f;
    void flip(){ v = e - b + 1 - v; }
    void cnt(){ for(int i = b, &j = v = 0; i <= e; ++i) j += t[i]; }
} qt[QN];

int n,qn;

void init(){
  for(int i=0;i<=n/qn;++i){
    qt[i].b=i*qn;
    qt[i].e=min((i+1)*qn,n)-1;
    qt[i].f=0;
    qt[i].cnt();
  }
}

int aux(int n){
  switch(n){
  case 0:return 1;
  case 1:return 0;
  case 2:return 3;
  case 3:return 2;
  }
  return -1;
}

void mod(char c, int a, int b){
  for(int i=0;i<=n/qn;++i){
    if((a>qt[i].e) || (qt[i].b > b) ) continue;
    if((a<=qt[i].b) && (qt[i].e<=b)){
       switch(c){
       case 'I':qt[i].flip();qt[i].f=aux(qt[i].f);break;
       case 'F':qt[i].v=qt[i].e-qt[i].b+1;qt[i].f=2;break;
       case 'E':qt[i].v=0;qt[i].f=3;break;
      }
    }
    else{

      switch(qt[i].f){
      case 1:for(int j=qt[i].b;j<=qt[i].e;++j) t[j]=!t[j];break;
      case 2:for(int j=qt[i].b;j<=qt[i].e;++j) t[j]=true;break;
      case 3:for(int j=qt[i].b;j<=qt[i].e;++j) t[j]=false;break;
      }

      qt[i].f=0;

      switch(c){
      case 'I':for(int j=max(a, qt[i].b);j<=min(b, qt[i].e);++j) t[j]=!t[j];break;
      case 'F':for(int j=max(a, qt[i].b);j<=min(b, qt[i].e);++j) t[j]=true;break;
      case 'E':for(int j=max(a, qt[i].b);j<=min(b, qt[i].e);++j) t[j]=false;break;
      }
   
      qt[i].cnt();
    }
  }
}

int query(int a,int b){
  int res=0;
 
  for(int i=0;i<=n/qn;++i){
    if((a>qt[i].e) || (qt[i].b > b) ) continue;
    if((a<=qt[i].b) && (qt[i].e<=b)){
      res+=qt[i].v;
    }
    else{
      switch(qt[i].f){
      case 1:for(int j=qt[i].b;j<=qt[i].e;++j) t[j]=!t[j];break;
      case 2:for(int j=qt[i].b;j<=qt[i].e;++j) t[j]=true;break;
      case 3:for(int j=qt[i].b;j<=qt[i].e;++j) t[j]=false;break;
      }
      qt[i].f=0;
      // qt[i].cnt();
      
      for(int j=max(a,qt[i].b);j<=min(b,qt[i].e);++j)
	res+=t[j];
    }
  }

 return res;
}

int main(){
  int tcn; scanf("%d", &tcn);
  for(int i=0, j; i++ < tcn; ){
    int a, b, reps, queries, qc = 0, specs;
    n=0;
    char cmd, pattern[64];
    for(scanf("%d", &specs); specs--; ){
      scanf("%d %s", &reps, pattern);
      for(j = 0; pattern[j]; ++j) pattern[j] -= '0';
      for(int k = 0; k < reps; ++k)
	for(int l = 0; l < j; ++l)
	  t[n++] = pattern[l];
    }

    qn=sqrt(n);
    init();
    /*  for(int aa=0;aa<n;++aa)
      cerr << t[aa] << ' ';
    cerr << endl;
    */    
printf("Case %d:\n", i);
    for(scanf("%d", &queries); queries--; ){
      scanf(" %c %d %d", &cmd, &a, &b);
      if(cmd == 'S') printf("Q%d: %d\n", ++qc, query(a, b));
      else mod(cmd, a, b);
    }
  }
}
