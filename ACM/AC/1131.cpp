#include<iostream>
using namespace std;

int t[1000009];
int res;

int find(int a){
  if(t[a]==a) return a;
  int tmp=find(t[a]);
  t[a]=tmp;
  return tmp;
}

int main(){
  int R,P;
  bool p=true;
  while(cin >> P >> R){
    for(int i=0;i<=P;++i)
      t[i]=i;
    res=0;
    
    for(int i=0;i<R;++i){
      int a, b;
      cin >> a >> b;
      if(find(a)==find(b)){
	res++;
	//cout << a << ' ' << b << endl;
      }
      else
	t[find(a)]=find(b);
    }
      if(!p)
	cout << endl;
      p=false;
      cout << res << endl;
  }
}
