#include<iostream>
#include<vector>

using namespace std;

int r,c;

template<typename T> void print(const vector<T>& t){
  for(auto p:t){
    for(auto x:p)
      cerr << x << ' ';
    cerr << endl;
  }
}

int main(){
  int N=501;
  vector<int> nbprime(N);
  vector<bool> prime(N,true);
  prime[0]=false;
  prime[1]=false;
  for(int i=2;i<N;++i)
    if(prime[i])
      for(int j=i+i;j<N;j+=i)
	prime[j]=false;

  for(int i=1;i<N;++i)
    nbprime[i]=nbprime[i-1]+(prime[i]?1:0);

  int t;
  cin >> t;
  while(t--){

    cin >> r >> c;
    vector<vector<char> > t(r, vector<char>(c));
    for(int i=0;i<r;++i)
      for(int j=0;j<c;++j)
	cin >> t[i][j];

    vector<vector<int> > l(r, vector<int>(c));
    vector<vector<int> > ri(r, vector<int>(c));
    vector<vector<int> > top(r, vector<int>(c));
    vector<vector<int> > b(r, vector<int>(c));
    
    for(int i=0;i<r;++i)
      for(int j=0;j<c;++j)
	if(t[i][j]=='#')
	  l[i][j] = ri[i][j] = top[i][j] = b[i][j] = -1;
	

    for(int i=0;i<r;++i)
      for(int j=1;j<c;++j)
	if(t[i][j]=='^')
	  l[i][j]=l[i][j-1]+1;


    for(int i=0;i<r;++i)
      for(int j=c-2;j>=0;--j)
	if(t[i][j]=='^')
	  ri[i][j]=ri[i][j+1]+1;


    for(int i=1;i<r;++i)
      for(int j=0;j<c;++j)
	if(t[i][j]=='^')
	  top[i][j]=top[i-1][j]+1;


    for(int i=r-2;i>=0;--i)
      for(int j=0;j<c;++j)
	if(t[i][j]=='^')
	  b[i][j]=b[i+1][j]+1;

    int res=0;
    for(int i=2;i<r-2;++i)
      for(int j=2;j<c-2;++j)
	if(t[i][j]=='^'){
	  res+=nbprime[min(min(l[i][j], ri[i][j]),min(top[i][j], b[i][j]))];
	}

    cout << res << '\n';
  }
}
