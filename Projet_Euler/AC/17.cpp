#include <iostream>

using namespace std;

int const N=1000;

int tab[N+1];

int main(){
  tab[1]=3;
  tab[2]=3;
  tab[3]=5;
  tab[4]=4;
  tab[5]=4;
  tab[6]=3;
  tab[7]=5;
  tab[8]=5;
  tab[9]=4;
  tab[10]=3;
  tab[11]=6;
  tab[12]=6;
  tab[13]=8;
  tab[14]=8;
  tab[15]=7;
  tab[16]=7;
  tab[17]=9;
  tab[18]=8;
  tab[19]=8;
  tab[20]=6;
  tab[30]=6;
  tab[40]=5;
  tab[50]=5;
  tab[60]=5;
  tab[70]=7;
  tab[80]=6;
  tab[90]=6;
  for(int i=1;i<=9;++i){
    tab[20+i]=tab[20]+tab[i];
    tab[30+i]=tab[30]+tab[i];
    tab[40+i]=tab[40]+tab[i];
    tab[50+i]=tab[50]+tab[i];
    tab[60+i]=tab[60]+tab[i];
    tab[70+i]=tab[70]+tab[i];
    tab[80+i]=tab[80]+tab[i];
    tab[90+i]=tab[90]+tab[i];
  }
  for(int i=1;i<10;++i){
    tab[i*100]=tab[i]+7;
    for(int j=1;j<=99;++j)
      tab[i*100+j]=tab[i*100]+3+tab[j];
  }
  tab[1000]=11;


  int res=0;
  for(int i=1;i<=N;++i){
    res+= tab[i];
  }

  cout << res << '\n';
}
