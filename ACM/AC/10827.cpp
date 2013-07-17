#include<iostream>
#include<vector>
#include<limits>
#include<algorithm>

using namespace std;

int N;

void pm(const vector<vector<int> > & t){
  for(int i=0;i<int(t.size());++i){
    for(int j=0;j<int(t[i].size());++j)
      cout << t[i][j] << ' ';
      cout << endl;
      }
}

inline int ss(int a, int b, int c, int d, const vector<vector<int> > & s){
  return s[c][d]-((b>0)?s[c][b-1]:0)-((a>0)?s[a-1][d]:0)+((a>0 && b>0)?s[a-1][b-1]:0);
}

int somme(int a, int b, int c, int d, const vector<vector<int> > & s){
  if(a<=c && b<=d){
    return ss(a,b,c,d,s);
  }
  if(a<=c && b>d){
    return ss(a,b,c,N-1,s)+ss(a,0,c,d,s);
  }
  if(a>c && b<=d){
    return ss(a,b,N-1,d,s)+ss(0,b,c,d,s);
  }
  else{
    return ss(0,0,c,d,s)+ss(a,b,N-1,N-1,s)+ss(0,b,c,N-1,s)+ss(a,0,N-1,d,s);
  }
}

int aux(const vector<vector<int> > & t){
  vector<vector<int> > s(N,vector<int>(N));
  s[0][0]=t[0][0];
  for(int i=1;i<N;++i)
    s[0][i]=s[0][i-1]+t[0][i];
  for(int i=1;i<N;++i)
    s[i][0]=s[i-1][0]+t[i][0];
  
  for(int i=1;i<N;++i)
    for(int j=1;j<N;++j)
      s[i][j]=s[i-1][j]+s[i][j-1]+t[i][j]-s[i-1][j-1];

  /*
  pm(t);
  cout << "matrice des sommes" << endl;
  pm(s);
  */

 int res=numeric_limits<int>::min();
  for(int a=0;a<N;++a)
    for(int b=0;b<N;++b)
      for(int c=0;c<N;++c)
	for(int d=0;d<N;++d)
	  res=max(res, somme(a,b,c,d, s));
  return res;
}

int main(){
  int cas;
  cin >> cas;
  while(cas--){
    cin >> N;
    vector<vector<int> > t(N,vector<int>(N));
    for(int i=0;i<N;++i)
      for(int j=0;j<N;++j)
	cin >> t[i][j];
    cout << aux(t) << endl;

  }
}
