#include<iostream>
#include<string>
#include<vector>

using namespace std;

int t[9][9];
int tt[9][9];

void print(){
  for(int i=0;i<9;++i){
    for(int j=0;j<9;++j)
      cout << t[i][j];
    cout << '\n';
  }
  cout << '\n';
}


void rcomplete(){
  int x,y;
  int fuck=0;
  while(fuck<81 && t[fuck/9][fuck%9]!=0) ++fuck;
  x=fuck/9;
  y=fuck%9;

  if(fuck==81){
    for(int i=0;i<9;++i)
      for(int j=0;j<9;++j)
	tt[i][j]=t[i][j];
      return;
  }
  bool poss[10];
  for(int i=0;i<10;++i)
    poss[i]=true;
  for(int i=0;i<9;++i)
    poss[t[x][i]]=false;
  for(int i=0;i<9;++i)
    poss[t[i][y]]=false;
  for(int i=0;i<9;++i)
    poss[t[(x/3)*3+(i%3)][(y/3)*3+i/3]]=false;
  
  int count=0;
  vector<int> p;
  for(int i=0;i<10;++i)
    if(poss[i]){
      count++;
      p.push_back(i);
    }
  if (count==0)
    return;
  
  int nt[9][9];
  for(int i=0;i<9;++i)
    for(int j=0;j<9;++j)
      nt[i][j]=t[i][j];
  for(int k=0;k<p.size();++k){
    t[x][y]=p[k];
    rcomplete();
    for(int i=0;i<9;++i)
      for(int j=0;j<9;++j)
	t[i][j]=nt[i][j];
  }
  return;
}



int main(){
  int res=0;
  string s;
  char tmp;
  for(int i=0;i<50;++i){
    cin >> s;
    cin >> s;
    for(int i=0;i<9;++i)
      for(int j=0;j<9;++j){
	cin >> tmp;
	t[i][j]= tmp-'0';
      }
    //    print();
    rcomplete();
    res+=tt[0][0]*100+tt[0][1]*10+tt[0][2];
  }
  cout << res << '\n';
}
