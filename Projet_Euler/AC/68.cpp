#include<iostream>
#include<algorithm>

using namespace std;

bool comp(int a, int b){
  return a>b;
}

int t[] = {1,2,3,4,5,6,7,8,9,10};

bool check(){
  if(t[0]<t[3] && t[0]<t[5] && t[0]<t[7] && t[0]<t[9]){
  int val1=t[0]+t[1]+t[2];
  int val2=t[3]+t[2]+t[4];
  int val3=t[5]+t[4]+t[6];
  int val4=t[7]+t[6]+t[8];
  int val5=t[9]+t[8]+t[1];
  return ((val1==val2) && (val2==val3) && (val3==val4) && (val4==val5));
  }
  return false;
}

int main(){
  sort (t,t+10,comp);
  do {
    if(check()){
      cout << t[0] << t[1] << t[2] << ';' << t[3] << t[2] << t[4] << ';' << t[5] << t[4] << t[6] << ';' << t[7] << t[6] << t[8] << ';' << t[9] << t[8] << t[1] << '\n';
      break;
    }
  } while ( next_permutation (t,t+10,comp) );
}



