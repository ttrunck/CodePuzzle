#include<iostream>
#include<vector>
#include<iomanip>
#include<sstream>
#include<string>

using namespace std;

typedef long long ent;

class Big_int{
public:
  
  Big_int(int x=0):t(1,x){};

  void afficher(ostream &flux) const{
    flux << t[int(t.size())-1];
    for(int i=int(t.size())-2;i>=0;--i)
      flux << setfill('0') << setw(6) << t[i];
  }

  Big_int& operator+=(const Big_int & n){
    t.resize(max(int(t.size()), int(n.t.size())));
    for(int i=0;i<int(n.t.size());++i)
      t[i]+=n.t[i];
    canonize();
    return *this;
  }

  Big_int& operator*=(int n){
    for(int i=0;i<int(t.size());++i)
      t[i]*=n;
    canonize();
    return *this;
  }

private:
  vector<int> t;
  static const ent N=1000000;

  void canonize(){
    int size=int(t.size());
    for(int i=0;i<size-1;++i)
      if(t[i]>=N){
	t[i+1]+=t[i]/N;
	t[i]%=N;
      }
    if(t[size-1]>=N){     
      t.push_back(t[size-1]/N);
      t[size-1]%=N;
	}
  }

};

Big_int operator+(const Big_int & a, const Big_int & b){
  Big_int copie(a);
  copie+=b;
  return copie;
}

Big_int operator*(const Big_int & a, int b){
  Big_int copie(a);
  copie*=b;
  return copie;
}


ostream &operator<<(ostream &flux, const Big_int & n){
  n.afficher(flux);
  return flux;
}

Big_int aux(int n){
  Big_int res(1);
  for(int i=n+2;i<=2*n;++i)
    res*=i;
  return res;
}

int main(){
  int n;
  while(cin >> n && n){
    cout << aux(n) << '\n';
  }
}
