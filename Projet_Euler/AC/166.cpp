#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

const int N=4;
ll res=0;

vector<vector<int> > t(N,vector<int>(N,-1));

bool ok(){
  int somme=-1;

  for(int i=0;i<N;++i){
    int tmp=0;
    bool pass=false;
    for(int j=0;j<N;++j){
      if(t[i][j]<0){
	pass = true;
	break;
      }
      tmp+=t[i][j];
    }

    if(!pass){
      if(somme<0)
	somme=tmp;
      if(somme!=tmp)
	return false;
    }
  }
  for(int i=0;i<N;++i){
    int tmp=0;
    bool pass=false;
    for(int j=0;j<N;++j){
      if(t[j][i]<0){
	pass = true;
	break;
      }
      tmp+=t[j][i];
    }

    if(!pass){
      if(somme<0)
	somme=tmp;
      if(somme!=tmp)
	return false;
    }
  }

  {
    int tmp=0;
    bool pass=false;
    for(int j=0;j<N;++j){
      if(t[j][j]<0){
	pass = true;
	break;
      }
      tmp+=t[j][j];
    }

    if(!pass){
      if(somme<0)
	somme=tmp;
      if(somme!=tmp)
	return false;
    }
  }

  {
    int tmp=0;
    bool pass=false;
    for(int j=0;j<N;++j){
      if(t[N-1-j][j]<0){
	pass = true;
	break;
      }
      tmp+=t[N-1-j][j];
    }

    if(!pass){
      if(somme<0)
	somme=tmp;
      if(somme!=tmp)
	return false;
    }
 }

  return true;
}

void backtrack(){
  int curr=0;
  while(curr<N*N && t[curr%N][curr/N]>=0) ++curr;
  if(curr==N*N){
    ++res;

    /*
    cerr << "\n\n=============\n\n";
    for(int i=0;i<N;++i){
      for(int j=0;j<N;++j)
	cerr << t[i][j] << '\t';
      cerr << '\n';
    }
    */
    return;
  }
  for(int i=0;i<=9;++i){
    t[curr%N][curr/N]=i;
    if(ok())
      backtrack();
  }
  t[curr%N][curr/N]=-1;
}

int main(){
  backtrack();
  cout << res << endl;
}
