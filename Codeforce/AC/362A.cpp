#include<iostream>
#include<string>
#include<vector>

using namespace std;

inline int abs(int a){
  return (a>0?a:-a);
}

const vector<int> dx{2,2,-2,-2};
const vector<int> dy{2,-2,2,-2};

void aux(vector<vector<int> >& t, int x, int y, int cmp){
  t[x][y]=cmp;
  
  for(int i=0;i<4;++i){
    int nx=x+dx[i];
    int ny=y+dy[i];
    if(nx>=0 && nx<8 && ny>=0 && ny<8 && t[nx][ny]==-1)
      aux(t, nx, ny, (cmp+1)%2);
  }
}

int main(){
  int T;
  cin >> T;
  while(T-->0){
    vector<string> t(8);
    int x1=-1, y1=-1, x2=-1, y2=-1;
    for(int i=0;i<8;++i){
      string s;
      cin >> s;
      t[i]=s;
      for(int j=0;j<8;++j)
	if(s[j]=='K'){
	  if(x1==-1){
	    x1=i;
	    y1=j;
	  }
	  else{
	    x2=i;
	    y2=j;
	  }
	}
    }

    vector<vector<int> > t1(8, vector<int>(8,-1));
    vector<vector<int> > t2(8, vector<int>(8,-1));
    
    aux(t1, x1, y1, 0);
    aux(t2, x2, y2, 0);

    /*
    for(int i=0;i<8;++i){
      for(int j=0;j<8;++j)
	cerr << t1[i][j];
      cerr << endl;
    }

    for(int i=0;i<8;++i){
      for(int j=0;j<8;++j)
	cerr << t2[i][j];
      cerr << endl;
    }
    */

    bool res=false;
    for(int i=0;i<8;++i)
      for(int j=0;j<8;++j)
	if(t1[i][j]!=-1 && t2[i][j]!=-1 && t[i][j]!='#' && (t1[i][j]+t2[i][j])%2==0)
	  res=true;

      if(res)
	cout << "YES\n";
      else
	cout << "NO\n";
  }
}
