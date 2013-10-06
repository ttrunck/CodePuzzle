#include<iostream>
#include<valarray>
#include<vector>

using namespace std;

double comp_diff(valarray<double>& x, const valarray<double>& t){
  x*=(t/x).sum()/t.size();
  valarray<double> tmp = (t-x)*(t-x);
  return abs(((t-x)*(t-x)).sum());
}

int main(){
  int N;
  cin >> N;

  vector<double> nn, tt;
  for(int i=0;i<N;++i){
    double n1, t1;
    cin >> n1 >> t1;
    if(t1>100){
      nn.push_back(n1);
      tt.push_back(t1);
    }
  }

  valarray<double> n(nn.data(), nn.size()), t(tt.data(), tt.size());

  valarray<double> x(1,t.size());

  double mini = comp_diff(x,t);
  string res = "O(1)";
  double tmp;

  //log
  x = log(n);
  tmp = comp_diff(x, t);
  if(tmp<mini){
    mini=tmp;
    res="O(log n)";
  }

  //n
  x = n;
  tmp = comp_diff(x, t);
  if(tmp<mini){
    mini=tmp;
    res="O(n)";
  }

  //nlog
  x = n*log(n);
  tmp = comp_diff(x, t);
  if(tmp<mini){
    mini=tmp;
    res="O(n log n)";
  }

  //n2
  x = pow(n,2.);
  tmp = comp_diff(x, t);
  if(tmp<mini){
    mini=tmp;
    res="O(n^2)";
  }

  //n2 log
  x = pow(n,2.)*log(n);
  tmp = comp_diff(x, t);
  if(tmp<mini){
    mini=tmp;
    res="O(n^2 log n)";
  }

  //n3
  x = pow(n,3.);
  tmp = comp_diff(x, t);
  if(tmp<mini){
    mini=tmp;
    res="O(n^3)";
  }

  //2^n
  x = pow(2.,n);
  tmp = comp_diff(x, t);
  if(tmp<mini){
    mini=tmp;
    res="O(2^n)";
  }

  cout << res << endl;
}
