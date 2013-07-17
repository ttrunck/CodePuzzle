#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct constraint{
  int a,b,c;
  constraint(int aa=0, int bb=0, int cc=0):a(aa), b(bb), c(cc){};
};

bool check(const vector<int> & t, const vector<constraint> & c){
  for(int i=0;i<int(c.size());++i){
    if(c[i].c<0){
      if(abs(t[c[i].a]-t[c[i].b])<abs(c[i].c))
	return false;
    }
    else{
      if(abs(t[c[i].a]-t[c[i].b])>c[i].c)
	return false;
    }
  }
 return true;
}

int main(){
  int n, m;
  while(cin >> n >> m && (n||m)){
    vector<int> t(n);
    for(int i=0;i<n;++i)
      t[i]=i;
    vector<constraint> c(m);
    for(int i=0;i<m;++i)
      cin >> c[i].a >> c[i].b >> c[i].c;
    int res=0;
    do{
      if(check(t, c))
	res++;
    }while(next_permutation(t.begin(), t.end()));
    cout << res << '\n';
  }
}
