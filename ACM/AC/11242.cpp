#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>

using namespace std;

int main(){
  int f,r;
  cin >> f >> r;
  while(f!=0){
    vector<int> ff(f);
    for(int i=0;i<f;++i)
      cin >> ff[i];
    vector<int> rr(r);
    for(int i=0;i<r;++i)
      cin >> rr[i];
    vector<double> t;
    for(int i=0;i<f;++i)
      for(int j=0;j<r;++j)
	t.push_back(double(rr[j])/double(ff[i]));

    sort(t.begin(), t.end());

    double res=0;
    for(int i=1;i<int(t.size());++i)
      res=max(res, t[i]/t[i-1]);
    cout << setprecision(2) << fixed <<  res << endl;


    cin >> f >> r;
  }
}
