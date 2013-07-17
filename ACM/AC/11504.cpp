#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i,n) REP(i, 0, n)
#define DBG 0
using namespace std;

int N,low[100000],q[100000],in[100000],id[100000],scnt,cp,cnt;
vector<int>egs[100000],regs[100000],finish;
bool trav[100000];

void DFS(int cur){
    if(trav[cur])return;
    trav[cur]=1;
    rep(i,egs[cur].size())DFS(egs[cur][i]);
    finish.push_back(cur);
}
void DFS2(int a,int b){
    if(trav[a])return;
    trav[a]=1,id[a]=b;
    rep(i,regs[a].size())if(!trav[regs[a][i]])DFS2(regs[a][i],b);
}
void kosaraju(){
    int b;
    memset(trav,0,sizeof(trav));
    rep(i,N)DFS(i);
    memset(trav,0,sizeof(trav));
    rep(i,N){
        b=finish[N-1-i];
        if(!trav[b]){
            if(DBG)printf("find scc %d\n",b);
            DFS2(b,scnt++);
        }
    }
}
void ans(){
    int tot=0,b;
    finish.clear();
    memset(trav,0,sizeof(trav));
    memset(id,-1,sizeof(id));
    memset(in,0,sizeof(in));
    cp=cnt=scnt=0;
    kosaraju();             //find all scc
    rep(i,N)rep(j,egs[i].size()){
        b=egs[i][j];
        if(id[i]!=id[b]){
            in[id[b]]++;
        }
    }
    rep(i,scnt)if(!in[i])tot++;
    printf("%d\n",tot);
}
int main(){
    int a,b,m,n;
    scanf("%d",&n);
    rep(i,n){
        scanf("%d%d",&N,&m);
        rep(i,N)egs[i].clear(),regs[i].clear();
        rep(i,m){
            scanf("%d%d",&a,&b),a--,b--;
            if(a!=b)regs[b].push_back(a),egs[a].push_back(b);
        }
        ans();
    }
}


