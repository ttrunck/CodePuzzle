#include<iostream>
#include<iomanip>

typedef long long ent;

using namespace std;

int const N=40;
ent p[N];
ent c[N];
ent pp=0;
ent cc=0;

ent pc=0;

int main(){
  for(int i1=1;i1<=4;++i1)
    for(int i2=1;i2<=4;++i2)
      for(int i3=1;i3<=4;++i3)
	for(int i4=1;i4<=4;++i4)
	  for(int i5=1;i5<=4;++i5)
	    for(int i6=1;i6<=4;++i6)
	      for(int i7=1;i7<=4;++i7)
		for(int i8=1;i8<=4;++i8)
		  for(int i9=1;i9<=4;++i9){
		    p[i1+i2+i3+i4+i5+i6+i7+i8+i9]++;
		    pp++;
		  }

  for(int i1=1;i1<=6;++i1)
    for(int i2=1;i2<=6;++i2)
      for(int i3=1;i3<=6;++i3)
	for(int i4=1;i4<=6;++i4)
	  for(int i5=1;i5<=6;++i5)
	    for(int i6=1;i6<=6;++i6){
	      c[i1+i2+i3+i4+i5+i6]++;
	      cc++;
	    }

  for(int i=1;i<N;++i)
    for(int j=1;j<i;++j)
      pc+=p[i]*c[j];
 
  cout << pc << ' ' << pp*cc << '\n';
  cout << setprecision(7) << (double)((double)pc/(double)(pp*cc)) << '\n';
}
