#include <iostream>

using namespace std;

bool leap(int y){
  return (y%400==0 || (y%100!=0 && y%4==0));
}

int nb_jour(int m, int y){
  if(m==0) return 31;
  if(m==1) return leap(y)?29:28;
  if(m==2) return 31;
  if(m==3) return 30;
  if(m==4) return 31;
  if(m==5) return 30;
  if(m==6) return 31;
  if(m==7) return 31;
  if(m==8) return 30;
  if(m==9) return 31;
  if(m==10) return 30;
  if(m==11) return 31;
  return -1;
}

int main(){
  int day=0, m=0, y=1900, d=0;
  int res=0;
  while(m!=11 || y!=2000){
    day= (day+1)%7;
    d++;
    if(d==nb_jour(m,y)){
      d=0;
      m++;
      if(m==12){
	m=0;
	y++;
      }
      cout << day << ' ' << d << ' ' << m << ' ' << y << '\n';
    }
    if(d==0 && day==6 && y>1900) ++res;
  }

  cout << res << '\n';
}
