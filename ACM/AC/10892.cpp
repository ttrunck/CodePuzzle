#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

typedef long long ent;

ent gcd(ent a, ent b){
  return (b==0)?a:gcd(b,a%b);
}

ent lcm(ent a, ent b){
  return (a*b)/gcd(a,b);
}

ostream& operator<<(ostream & flux, const vector<int> & t){
  for(int i=0;i<int(t.size());++i)
    flux << t[i] << ' ';
  return flux;
}

int traite(vector<int> & acc){
  if(acc.empty()) return 1;
  int res=acc.back();
  acc.pop_back();
  for(int i=0;i<int(acc.size());++i)
    res*=acc[i]*2+1;
  res+=traite(acc);
  return res;
}

int aux(int n){
  if(n==1) return 1;
  vector<int> acc;
 
  for(int i=2;n!=1;++i)
    if(n%i==0){
      int compt=0;
      while(n%i==0){
	n/=i;
	compt++;
      }
      acc.push_back(compt);
    }

  return traite(acc);
}

int main(){
  int n;
  while(cin >> n && n)
    cout << n << ' ' << aux(n) << '\n';
}
