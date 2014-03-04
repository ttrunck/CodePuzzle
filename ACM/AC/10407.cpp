#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

ostream& operator<<(ostream &flux, const vector<int> & t){
  for(int i=0;i<int(t.size());++i)
    flux << t[i] << ' ';
  return flux;
}

int gcd(int a, int b){
  return (b==0)?a:gcd(b,a%b);
}

int gcd(const vector<int> t){
  int res=0;
  for(int i=0;i<int(t.size());++i)
    res=gcd(res,t[i]);
  return res;
}

bool check(const vector<int> t, int n){
  int val=t[0]%n;
  for(int i=0;i<int(t.size());++i)
    if(t[i]%n!=val) return false;
  return true;
}

vector<int> aux(const vector<int> & t){
  vector<int> res(t.size()-1);
  for(int i=1;i<int(t.size());++i)
    res[i-1]=t[i]-t[i-1];
  return res;
}

int main(){
  vector<int> t;
  int tmp;
  while(cin >> tmp && tmp){
    t.push_back(tmp);
    while(cin >> tmp && tmp)
      t.push_back(tmp);
    
    //cout << t << '\n';
    cout << abs(gcd(aux(t))) << '\n';

    t.clear();
  }
}
