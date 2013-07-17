/*
ID: blabla41
PROG: castle
LANG: C++
 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

ofstream fout ("castle.out");
ifstream fin ("castle.in");
  
int tab[51][51];
int piece[51][51];
int N, M;
int piece_curr=0;
int size_curr=0;
vector<int> size;
int size_max=0;
int wall1, wall2;
int size_wall_max=0;
char cote;


void parcours(int a, int b){
  //cout << a << ' ' << b << ' ' << piece_curr << endl;
  piece[a][b]= piece_curr;
  size_curr++;
  if ((tab[a][b])%2==0 && piece[a][b-1]==-1)
    parcours(a,b-1);
  if ((tab[a][b]/4)%2==0 && piece[a][b+1]==-1)
    parcours(a,b+1);
  if ((tab[a][b]/2)%2==0 && piece[a-1][b]==-1)
    parcours(a-1,b);
  if ((tab[a][b]/8)%2==0 && piece[a+1][b]==-1)
    parcours(a+1,b);
}

int main(){
  fin >> M >> N;
  for (int i=0;i<N;++i)
    for(int j=0;j<M;++j){
      fin >> tab[i][j];
      piece[i][j]=-1;
    }

  for(int i=0;i<N;++i){
    for(int j=0;j<M;++j){
      if (piece[i][j]==-1){
	parcours(i,j);
	size.push_back(size_curr);
	size_max= max(size_curr, size_max);
	size_curr=0;
	piece_curr++;
      }
    }
  }


  
  for(int j=0;j<M;++j){
    for(int i=N-1;i>=0;--i){  
      if (j-1>=0 && piece[i][j]!= piece[i][j-1]){
	if (size_wall_max < size[piece[i][j]]+size[piece[i][j-1]]){
	  size_wall_max = size[piece[i][j]]+size[piece[i][j-1]];
	  wall1=i;
	  wall2=j;
	  cote= 'W';
	}
      }
      if (i-1>=0 && piece[i][j]!=piece[i-1][j]){
	if (size_wall_max < size[piece[i][j]]+size[piece[i-1][j]]){
	  size_wall_max = size[piece[i][j]]+size[piece[i-1][j]];
	  wall1=i;
	  wall2=j;
	  cote= 'N';
	}
      }
      if (j+1<M && piece[i][j]!=piece[i][j+1]){
	if (size_wall_max < size[piece[i][j]]+size[piece[i][j+1]]){
	  size_wall_max = size[piece[i][j]]+size[piece[i][j+1]];
	  wall1=i;
	  wall2=j;
	  cote= 'E';
	}
      }
      if (i+1<N && piece[i][j]!=piece[i+1][j]){
	if (size_wall_max < size[piece[i][j]]+size[piece[i+1][j]]){
	  size_wall_max = size[piece[i][j]]+size[piece[i+1][j]];
	  wall1=i;
	  wall2=j;
	  cote= 'S';
	}
      }
      
    }
  }
  
  for(int i=0;i<N;++i){
    for(int j=0;j<M;++j)
      cout << piece[i][j] << ' ';
    cout << endl;
  }



  fout << piece_curr << '\n' << size_max << '\n' << size_wall_max << '\n';
  fout << wall1+1 << ' ' << wall2+1 << ' ' << cote << '\n';
  


}
