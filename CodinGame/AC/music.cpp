#include<iostream>
#include<vector>

using namespace std;

typedef pair<int, int> pi;

int w, h;
int firstLine, widthBlack, widthNext;
vector<vector<bool> > t;
vector<vector<bool> > visited;

vector<pi> dir{pi{1,0}, pi{-1,0}, pi{0,1}, pi{0,-1}, pi{1,1}, pi{1,-1}, pi{-1, 1}, pi{-1,-1}};
vector<char> note{'G', 'F', 'E', 'D', 'C', 'B', 'A', 'G', 'F', 'E', 'D', 'C'};

void readStraight(vector<bool>& t){
  char c;
  int n;
  int curr=0;
  while(cin >> c >> n)
    while(n--)
      t[curr++]=(c=='B');
}

void findLine(){
  for(int j=0;j<w;++j)
    for(int i=0;i<h;++i)
      if(t[i][j]){
	firstLine=i;
	widthBlack=i;
	while(t[widthBlack][j]) ++widthBlack;
	widthNext=widthBlack;
	while(!t[widthNext][j]) ++widthNext;
	
	widthBlack = widthBlack-firstLine;
	widthNext = widthNext-firstLine;	
	return;
      }
}

bool isUsefull(int x, int y){
  //return true iff t[x][y] is not a line.
  if(!t[x][y])
    return false;
  
  for(int i=0;i<6;++i)
    if(x>=firstLine+i*widthNext && x<firstLine+i*widthNext+widthBlack)
      return false;

  return true;
}

void dfs(int i, int j, pi& p1, pi& p2){
  if(j<p1.second){
    p1.first=i;
    p1.second=j;
  }
  if(j>p2.second){
    p2.first=i;
    p2.second=j;
  }

  visited[i][j]=true;
  for(const auto& d: dir)
    if(!visited[i+d.first][j+d.second] && isUsefull(i+d.first, j+d.second))
      dfs(i+d.first, j+d.second, p1, p2);
}

int main(){
  cin >> w >> h;
  vector<bool> t_straight(w * h);
  readStraight(t_straight);
  
  t.resize(h);
  for(int i=0;i<h;++i)
    t[i].resize(w);

  visited.resize(h);
  for(int i=0;i<h;++i)
    visited[i].resize(w);
  for(int i=0;i<h;++i)
    for(int j=0;j<w;++j)
      visited[i][j]=false;
      
  for(int i=0;i<h;++i)
    for(int j=0;j<w;++j)
      t[i][j]=t_straight[i*w+j];

  findLine();

  //for(int i=0;i<h;++i){
  //  for(int j=0;j<w;++j)
  //    cerr << (isUsefull(i,j)?'#':(t[i][j]?'x':' '));
  //  cerr << '\n';
  //}

  bool first=true;

  for(int j=0;j<w;++j)
    for(int i=0;i<h;++i)
      if(isUsefull(i,j)){
	pi start{w,w};
	pi final{-1,-1};
	dfs(i,j,start, final);

	bool isBlack = t[(start.first+final.first)/2][(start.second+final.second)/2];

	char value='Z';
	for(int i=-1;i<12;++i)
	  if(start.first<firstLine+i*widthNext/2){
	    value=note[i+1];
	    break;
	  }

	if(!first)
	  cout << ' ';
	first=false;
	cout << value << (isBlack?'Q':'H');

	j=final.second;
	break;
      }
  cout << '\n';
}
