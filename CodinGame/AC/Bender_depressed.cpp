#include<iostream>
#include<vector>
#include<string>

using namespace std;

typedef pair<int, int> pi;

vector<string> carte;
vector<pi> teleport;
int l,c;

struct etat{
  int dir=0;
  bool prio=false;
  bool casseur=false;
  int destroy=0;
  etat(int a=-1, bool b=true, bool c=true, int d=0):dir(a), prio(b), casseur(c), destroy(d){};

  bool operator==(const etat& e) const{
    return dir==e.dir && prio==e.prio && casseur==e.casseur && destroy==e.destroy;
  }
};

vector<vector<etat> > state;

struct Bender{
  int x,y;
  int dir=0;
  bool prio=false;
  bool casseur=false;
  int destroy=0;
  bool alive=true;

  vector<pi> D{pi(1,0), pi(0,1), pi(-1,0), pi(0,-1)};

  vector<string> past_dir;

  bool avance(){
    etat et(dir,prio,casseur,destroy);
    if(state[x][y]==et)
      return false;
    state[x][y]=et;

   int nx=x+D[dir].first, ny=y+D[dir].second;
   if(nx<0 || nx>=l || ny<0 || ny>=c || carte[nx][ny]=='#' || (carte[nx][ny]=='X' && !casseur)){
     for(int i=0;i<4;++i){
       int ndir=prio?3-i:i;
       int nx=x+D[ndir].first, ny=y+D[ndir].second;
       if(nx<0 || nx>l || ny<0 || ny>c || carte[nx][ny]=='#')
	 continue;
       if(carte[nx][ny]=='X' && !casseur)
	 continue;
       
       dir=ndir;
       x=nx;
       y=ny;
      break;
     }
   }
   else{
     x=nx;
     y=ny;
   }

   if(dir==0)
     past_dir.push_back("SOUTH");
   else if(dir==1)
     past_dir.push_back("EAST");
   else if(dir==2)
     past_dir.push_back("NORTH");
   else
     past_dir.push_back("WEST");

    if(carte[x][y]=='X'){
      carte[x][y]=' ';
      destroy++;
    }
    else if(carte[x][y]=='$'){
      alive=false;
      return false;
    }
    else if(carte[x][y]=='S')
      dir=0;
    else if(carte[x][y]=='E')
      dir=1;
    else if(carte[x][y]=='N')
      dir=2;
    else if(carte[x][y]=='W')
      dir=3;
    else if(carte[x][y]=='B')
      casseur=!casseur;
    else if(carte[x][y]=='I')
      prio=!prio;
    else if(carte[x][y]=='T'){
      if(x==teleport[0].first && y==teleport[0].second){
	x=teleport[1].first;
	y=teleport[1].second;
      }
      else{
	x=teleport[0].first;
	y=teleport[0].second;
      }
    }
    
    return true;
  }
};


int main(){
  cin >> l >> c;
  cin.ignore();
  
  Bender b;
  state.assign(l,vector<etat>(c));

  for(int i=0;i<l;++i){
    string tmp;
    getline(cin, tmp);
    carte.push_back(tmp);
  }
  
  for(int i=0;i<l;++i)
    for(int j=0;j<c;++j){
      char tmp=carte[i][j];
      if(tmp=='@'){
	b.x=i;
	b.y=j;
	tmp=' ';
      }
      else if(tmp=='T')
	teleport.push_back(pi(i,j));
    }

   while(b.avance());

  if(!b.alive)
    for(auto s:b.past_dir)
      cout << s << '\n';
  else{
    cout << "LOOP\n";
  }

}
