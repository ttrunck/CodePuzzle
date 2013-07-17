#include<iostream>
#include<vector>
#include<iomanip>

typedef unsigned long long ent;

using namespace std;

const int N=1001;

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

ostream &operator<<(ostream &flux, const Big_int & n){
  n.afficher(flux);
  return flux;
}

int main(){
  vector<Big_int> t(N);
  t[0]=1;
  t[1]=2;
  for(int i=2;i<N;++i)
    t[i]=t[i-1]+t[i-2];

  cerr << t[1000] << endl;

  int n;
  while(cin >> n)
    cout << t[n] << '\n';

} 
