#include<iostream>
#include<vector>

using namespace std;

typedef pair<double, double> pf;

bool inter(const pf & a, const pf & b, const pf & c, const pf & d){
  double den=(b.first-a.first)*(d.second-c.second)-(b.second-a.second)*(d.first-c.first);
  double num1=(a.second-c.second)*(d.first-c.first)-(a.first-c.first)*(d.second-c.second);
  double num2=(a.second-c.second)*(b.first-a.first)-(a.first-c.first)*(b.second-a.second);

  if(den==0)
    return (num1==0);

  double r=num1/den, s=num2/den;
  return (0<=r && r<=1 && 0<=s && s<=1);
}

int main(){
  ios::sync_with_stdio(false);
  int n;
  while(cin >> n && n){
    vector<pair<pf, pf> > t(n);
    for(int i=0;i<n;++i){
      pf a,b;
      cin >> a.first >> a.second >> b.first >> b.second;
      t[i]=make_pair(a,b);
    }
    bool first=true;
    cout << "Top sticks: ";
    for(int i=0;i<n;++i){
      bool ok=true;
      for(int j=i+1;j<n;++j)
	if(inter(t[i].first, t[i].second, t[j].first, t[j].second)){
	  ok=false;
	  break;
      }
      if(ok){
	if(!first) cout << ", ";
	first=false;
	cout << i+1;
      }
    }

    cout << ".\n";
  }
}
