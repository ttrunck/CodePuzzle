#include <iostream>
#include <cmath>

using namespace std;

int const N=1000;

int main(){
  int nb_max_sol=0, res;
  for(int p=1;p<=N;++p){
    int nb_sol=0;
      for(int a=1;a<p;++a)
	for(int b=a;a+b<p;++b){
	  int c=p-a-b;
	  if(a*a+b*b==c*c) nb_sol++;
	}
    
      if(nb_max_sol<nb_sol){
	res=p;
	nb_max_sol=nb_sol;
      }
  }

  cout << res << '\n';

}
