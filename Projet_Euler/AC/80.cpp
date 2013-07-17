#include<iostream>
#include<gmpxx.h>
#include<cmath>


using namespace std;

typedef mpf_class f;

bool is_square(int n){
  int tmp=sqrt(n);
  return tmp*tmp==n;
}

int main(){
  int res=0;
  for(int k=2;k<=100;++k)
    if(!is_square(k)){
      f n=f(k,2000);
      n=sqrt(n);
      for(int i=0;i<100;++i){
	int tmp=n.get_si();
	n=10*(n-tmp);
	res+=tmp;
      }
    }
  cout << res << '\n';

}
