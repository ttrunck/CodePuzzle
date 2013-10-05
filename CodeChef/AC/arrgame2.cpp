#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

  int nbcase;
  cin >> nbcase;
  while(nbcase--){
    int n;
    cin >> n;
    vector<int> A, B;
    int B1=0, B2=0;
    for(int i=0;i<n;++i){
      int tmp;
      cin >> tmp;
      if(tmp>1)
	A.push_back(tmp);
    }
    sort(begin(A), end(A));
    for(int i=0;i<n;++i){
      int tmp;
      cin >> tmp;
      if(tmp>1){
	B.push_back(tmp);
	if(tmp==2)
	  B2++;
      }
      else
	B1++;
    }
    sort(begin(B), end(B));

    double res=0;
   
    for(int x:A){
      int tmp=B1;
      
      tmp+=distance(lower_bound(begin(B), end(B), x+((x!=2)?1:3)), end(B));
      
      if(x==3)
	tmp+=B2;

      res+=double(tmp)/n;
    }


    cout << res << '\n';
  }
}
