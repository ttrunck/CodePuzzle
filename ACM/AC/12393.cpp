#include<iostream>
#include<vector>

using namespace std;

int main(){
  int n;
  while(cin >> n && n){
    vector<int> t(n);
    for(int i=0;i<n;++i)
      cin >> t[i];

    vector<int> A(n);
    A[0]=t[0];
    for(int i=1;i<n;++i)
      A[i]=A[i-1]+t[i];

    vector<int> B(n);
    B[n-1]=t[n-1];
    for(int i=n-2;i>=0;--i)
      B[i]=B[i+1]+t[i];

    vector<int> C(n);
    C[0]=A[0];
    for(int i=1;i<n;++i)
      C[i]=min(C[i-1], A[i]);

    vector<int> D(n);
    D[n-1]=t[n-1];
    for(int i=n-2;i>=0;--i)
      D[i]=min(t[i], t[i]+D[i+1]);

    int res=0;
    if(D[0]>=0) res++;
    for(int i=1;i<n;++i)
      if(D[i]>=0 && B[i]+C[i-1]>=0) res++;

    cout << res << '\n';
  }
}
