#include<iostream>
#include<vector>

using namespace std;

void aff(const vector<int>& a, const vector<int>& b){
  int n=a.size();
  int bb=0;
  int pos=0;
  for(int aa=0;aa<n;++aa,++pos){
    while(b[bb]<a[aa]){
      ++bb;
      ++pos;
    }
    //cerr << "\npos: " << pos << endl;
    if(pos<n || 2*(aa+1)<=n)
      cout << '1';
    else
      cout << '0';
  }
}

int main(){
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for(int i=0;i<n;++i)
    cin >> a[i] >> b[i];

  aff(a,b);
  cout << '\n';
  aff(b,a);
  cout << '\n';
}
