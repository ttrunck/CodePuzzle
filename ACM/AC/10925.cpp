#include<iostream>
#include<vector>
#include<iomanip>
#include<string>

using namespace std;

typedef long long ent;

class Big_int{
public:
  Big_int(int x=0):t(1,x){}

   void afficher(ostream &flux) const{
     if(t.empty())
       flux << 0;
     else{
       flux << t[int(t.size())-1];
       for(int i=int(t.size())-2;i>=0;--i)
	 flux << setfill('0') << setw(4) << t[i];
     }
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

Big_int& operator/=(int n){
  for(int i=int(t.size())-1;i>0;--i){
    t[i-1]+=(t[i]%n)*N;
    t[i]/=n;
  }
  t[0]/=n;
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
    
    while(!t.empty() && t.back()==0)
      t.pop_back();
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

Big_int operator/(const Big_int & a, int b){
  Big_int copie(a);
  copie/=b;
  return copie;
}

Big_int convert(string s){
  Big_int res;
  for(int i=0;i<int(s.size());++i){
    res*=10;
    res+=s[i]-'0';
  }
  return res;
}

int main(){
  int icase=1;
  int n,f;
  while(cin >> n >> f && (n||f)){
    string s;
    Big_int tot;
    for(int i=0;i<n;++i){
      cin >> s;
      tot+=convert(s);
    }

    cout << "Bill #" << icase++ << " costs " << tot << ": each friend should pay " << tot/f << "\n\n";
  }
}
