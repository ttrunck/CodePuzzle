#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

typedef long long ent;

class Big_int{
public:
  Big_int(int x=0):t(1,x){}

   void afficher(ostream &flux) const{
    flux << t[int(t.size())-1];
    for(int i=int(t.size())-2;i>=0;--i)
      flux << setfill('0') << setw(4) << t[i];
  }

  Big_int& operator+=(Big_int n){
    t.resize(max(t.size(), n.t.size()));
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
  vector<ent> t;
  static const int N=10000;
  
  void canonize(){
    int s(t.size());
    for(int i=0;i<s-1;++i){
      t[i+1]+=t[i]/N;
      t[i]%=N;
    }
    if(t[s-1]>=N){
      t.push_back(t[s-1]/N);
      t[s-1]%=N;
    }
  }

};


ostream &operator<<(ostream &flux, const Big_int & n){
  n.afficher(flux);
  return flux;
}

Big_int operator+(const Big_int & a, const Big_int & b){
  Big_int copie(a);
  copie+=b;
  return copie;
}

Big_int operator*(int a, const Big_int & b){
  Big_int copie(b);
  copie*=a;
  return copie;
}

Big_int operator*(const Big_int & a, int b){
  Big_int copie(a);
  copie*=b;
  return copie;
}

Big_int sum(int n, int a){
  Big_int curr(a);
  Big_int res(0);

  for(int i=1;i<=n;++i){
    res+=i*curr;
    curr*=a;
  }
    return res;
}

int main(){
  int n,a;
  while(cin >> n >> a)
    cout << sum(n,a) << '\n';
}
