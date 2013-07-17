#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ent;
typedef pair<ent, ent> pi;

template<typename T>
inline T mabs(T x){
  return (x>0)?x:-x;
}

double area(const vector<pi> & t){
  double res=0;
  for(int i=0;i<int(t.size())-1;++i)
    res+=t[i].first*t[i+1].second-t[i].second*t[i+1].first;
  return mabs(res/2);
}

ent gcd(ent a, ent b){
  if(b==0) return a;
  return gcd(b, a%b);
}

ent boundary(const vector<pi> & t){
  ent res=0;
  for(int i=0;i<int(t.size())-1;++i){
    ent x=t[i+1].first-t[i].first;
    ent y=t[i+1].second-t[i].second;
    x=mabs(x);
    y=mabs(y);
    res+=gcd(x,y);
  }
  return res;
}

int main(){
  int n;
  while(cin >> n && n){
    vector<pi> t(n);
    for(int i=0;i<n;++i)
      cin >> t[i].first >> t[i].second;
    t.push_back(t[0]);
    double A=area(t);
    double P=boundary(t);
    //   cerr << A << ' ' << P << endl;
    cout << ent(A-P/2+1) << '\n';
  }
}
