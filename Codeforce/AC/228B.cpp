#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int na,ma,nb,mb;

int b(int x, int y, const vector<vector<int> > & tb){
  if(x<0 || y<0 || x>=nb || y>=mb) return 0;
     else return tb[x][y];
}

int calc(int x, int y, const vector<vector<int> > & ta, const vector<vector<int> > & tb){
  int res=0;
  for(int i=0;i<na;++i)
    for(int j=0;j<ma;++j)
      res+=ta[i][j]*b(i+x,j+y,tb);

  return res;
}

int main(){
 
  cin >> na >> ma;
  vector<vector<int> > ta(na, vector<int>(ma));
  for(int i=0;i<na;++i)
    for(int j=0;j<ma;++j){
      char tmp;
      cin >> tmp;
      if(tmp=='0') ta[i][j]=0;
      else ta[i][j]=1;
    }

  cin >> nb >> mb;
  vector<vector<int> > tb(nb, vector<int>(mb));  
  for(int i=0;i<nb;++i)
    for(int j=0;j<mb;++j){
      char tmp;
      cin >> tmp;
      if(tmp=='0') tb[i][j]=0;
      else tb[i][j]=1;
    }

  int maxi=0;
  int resx,resy;

  for(int x=-na;x<=nb;++x)
    for(int y=-ma;y<=mb;++y){
      int tmp=calc(x,y,ta,tb);
      if(tmp>maxi){
	maxi=tmp;
	resx=x;
	resy=y;
      }
    }

  cout << resx << ' ' << resy << '\n';

}
