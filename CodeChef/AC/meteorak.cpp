#include<iostream>
#include<cassert>

using namespace std;

typedef pair<int, int> pi;

int mem[1009][1009];
int top[1009][1009];
bool bad[1009][1009];
pi st[1009];
int sp=-1;

int n, m, k, q, x1, x2, x, y;

int main(){

  scanf("%d %d %d", &n, &m, &k);

  for(int i=0;i<n;++i)
    for(int j=0;j<m;++j){
      assert(!bad[i][j]);
      assert(mem[i][j]==0);
    }

  for(int i=0;i<k;++i){
    scanf("%d %d", &x, &y);
    bad[x-1][y-1]=true;
  }

  for(int i=0;i<m;++i)
    top[0][i]=bad[0][i]?0:1;
  for(int i=1;i<n;++i)
    for(int j=0;j<m;++j)
      top[i][j]=bad[i][j]?0:(1+top[i-1][j]);

  for(int up=0;up<n;++up){
    assert(sp==-1);
    for(int i=0;i<m;++i){
      int currLeft=-1;
      while(sp>=0 && st[sp].first>top[up][i]){
	currLeft=st[sp].second;
	mem[up-st[sp].first+1][up]=max(mem[up-st[sp].first+1][up],
				       (i-st[sp].second));
	--sp;
      }
      if(sp<0 || st[sp].first<top[up][i]){
	++sp;
	st[sp]=pi{top[up][i], (currLeft!=-1)?currLeft:i};
      }
    }
    while(sp>=0){
	mem[up-st[sp].first+1][up]=max(mem[up-st[sp].first+1][up],
				       (m-st[sp].second));
	--sp;
    }
    for(int down=1;down<=up;++down)
      mem[down][up]=max(mem[down][up], mem[down-1][up]);
  }

  for(int down=0;down<n;++down)
    for(int up=down;up<n;++up)
      mem[down][up] = mem[down][up] * (up-down+1);

  for(int span=1;span<n;++span)
    for(int down=0;down+span<n;++down)
      mem[down][down+span]=max(mem[down][down+span], 
			       max(mem[down+1][down+span], mem[down][down+span-1]));
    
  scanf("%d", &q);
  for(int i=0;i<q;++i){
    scanf("%d %d", &x1, &x2);
    printf("%d\n", mem[x1-1][x2-1]);
  }
		 
}
