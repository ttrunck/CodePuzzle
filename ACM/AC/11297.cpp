#include<iostream>
#include<vector>
#include<limits>
#include<cstdio>

using namespace std;

void initializemin(int node, int b, int e, vector<int> & M, const vector<int> & A){
  if (b == e)
    M[node] = b;
  else
    {
      initializemin(2 * node, b, (b + e) / 2, M, A);
      initializemin(2 * node + 1, (b + e) / 2 + 1, e, M, A);
      if (A[M[2 * node]] <= A[M[2 * node + 1]])
	M[node] = M[2 * node];
      else
	M[node] = M[2 * node + 1]; 
    }
}

int querymin(int node, int b, int e, vector<int> & M, const vector<int> & A, int i, int j){
  int p1, p2;
  if (i > e || j < b)
    return -1;
  if (b >= i && e <= j)
    return M[node];
  p1 = querymin(2 * node, b, (b + e) / 2, M, A, i, j);
  p2 = querymin(2 * node + 1, (b + e) / 2 + 1, e, M, A, i, j);
  if (p1 == -1)
    return p2;
  if (p2 == -1)
    return p1;
  if (A[p1] <= A[p2])
    return p1;
  return p2;
}

void initializemax(int node, int b, int e, vector<int> & M, const vector<int> & A){
  if (b == e)
    M[node] = b;
  else
    {
      initializemax(2 * node, b, (b + e) / 2, M, A);
      initializemax(2 * node + 1, (b + e) / 2 + 1, e, M, A);
      if (A[M[2 * node]] >= A[M[2 * node + 1]])
	M[node] = M[2 * node];
      else
	M[node] = M[2 * node + 1]; 
    }
}

int querymax(int node, int b, int e, vector<int> & M, const vector<int> & A, int i, int j){
  int p1, p2;
  if (i > e || j < b)
    return -1;
  if (b >= i && e <= j)
    return M[node];
  p1 = querymax(2 * node, b, (b + e) / 2, M, A, i, j);
  p2 = querymax(2 * node + 1, (b + e) / 2 + 1, e, M, A, i, j);
  if (p1 == -1)
    return p2;
  if (p2 == -1)
    return p1;
  if (A[p1] >= A[p2])
    return p1;
  return p2;
}

void modifmax(int node, int b, int e, vector<int> & M, const vector<int> & A, int pos){
  if (b == e)
    M[node] = b;
  else
    {
      if(pos<=(b+e)/2)
	modifmax(2 * node, b, (b + e) / 2, M, A, pos);
      else
	modifmax(2 * node + 1, (b + e) / 2 + 1, e, M, A, pos);
      if (A[M[2 * node]] >= A[M[2 * node + 1]])
	M[node] = M[2 * node];
      else
	M[node] = M[2 * node + 1]; 
    }
}

void modifmin(int node, int b, int e, vector<int> & M, const vector<int> & A, int pos){
  if (b == e)
    M[node] = b;
  else
    {
      if(pos<=(b+e)/2)
	modifmin(2 * node, b, (b + e) / 2, M, A, pos);
      else
	modifmin(2 * node + 1, (b + e) / 2 + 1, e, M, A, pos);
      if (A[M[2 * node]] <= A[M[2 * node + 1]])
	M[node] = M[2 * node];
      else
	M[node] = M[2 * node + 1]; 
    }
}


int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<int> > A (n, vector<int>(m,0) );
  vector<vector<int> > Mmin (n, vector<int>(4*m,-1));
  vector<vector<int> > Mmax (n, vector<int>(4*m,-1));
  for(int i=0;i<n;++i)
    for(int j=0;j<m;++j)     
      cin >> A[i][j];

  for(int i=0;i<n;++i){
    initializemin(1,0,m-1,Mmin[i],A[i]);
    initializemax(1,0,m-1,Mmax[i],A[i]);
  }

  int quer;
  cin >> quer;
  cin.ignore();
  for(int q=0;q<quer;++q){
    char c;
    scanf("%c",&c);
    if(c=='c'){
      int x,y,v;
      scanf(" %d %d %d\n",&x,&y,&v);
      x--;y--;
      A[x][y]=v;
      //faire un fast modif
      modifmin(1,0,m-1,Mmin[x],A[x],y);
      modifmax(1,0,m-1,Mmax[x],A[x],y);
    }
    else if(c=='q'){
      int x1,y1,x2,y2;
      scanf(" %d %d %d %d\n",&x1,&y1,&x2,&y2);
      x1--;y1--;x2--;y2--;
      int resmin=numeric_limits<int>::max();
      int resmax=numeric_limits<int>::min();
      for(int i=x1;i<=x2;++i){
	resmin=min(resmin, A[i][querymin(1,0,m-1,Mmin[i],A[i],y1,y2)]);
	resmax=max(resmax, A[i][querymax(1,0,m-1,Mmax[i],A[i],y1,y2)]);
      }
      printf("%d %d\n", resmax, resmin);
    }
  }
}
