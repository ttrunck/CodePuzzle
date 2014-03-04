#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iomanip>

using namespace std;

int main(){
  int c, s, n_case=1;
  while(cin >> c >> s){
    double poid_tot=0;
    vector<int> t(s);
    for(int i=0;i<s;++i){
      cin >> t[i];
      poid_tot+=t[i];
    }
    double poid_av=poid_tot/c;
    sort(t.begin(), t.end());
    
    int mini=0, maxi=s-1;
    double imbalance=0;
    int remain=s;

    cout << "Set #" << n_case++ << endl;
    for(int i=0;i<c;++i){
      cout << ' ' << i << ":";
      if(remain==0){
	imbalance+=poid_av;
	cout << endl;
      }
      else if(remain/2<c-i){
	remain--;
	imbalance+=abs(t[maxi]-poid_av);
	cout << ' ' << t[maxi--] << endl;
      }
      else{
	remain-=2;
	imbalance+=abs(t[maxi]+t[mini]-poid_av);
	cout << ' ' << t[maxi--] << ' ' << t[mini++] << endl;
      }
    }
    cout << "IMBALANCE = " << setprecision(5) << fixed<<  imbalance << endl << endl;

  }
}
