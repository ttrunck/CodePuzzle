/*
ID: blabla41
PROG: friday
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int isleap(int ans){
  if (ans%400==0) return 1;
  if (ans%100==0) return 0;
  if (ans%4==0) return 1;
  return 0;
}

//13dec 1899 est un mercredi

int daystart=4;

int dayinndays(int n){
  daystart=(daystart+n)%7;
  return daystart;
}

int main(){
  ofstream fout ("friday.out");
  ifstream fin ("friday.in");

  int N;
  fin >> N;
  int res[7];
  for(int i=0;i<7;++i)
    res[i]=0;

  for(int i=0;i<N;++i){
    res[dayinndays(31)]++;
    res[dayinndays(31)]++;
    res[dayinndays(28+isleap(1900+i))]++;
    res[dayinndays(31)]++;
    res[dayinndays(30)]++;
    res[dayinndays(31)]++;
    res[dayinndays(30)]++;
    res[dayinndays(31)]++;
    res[dayinndays(31)]++;
    res[dayinndays(30)]++;
    res[dayinndays(31)]++;
    res[dayinndays(30)]++;
  }

  for(int i=0;i<6;++i)
    fout << res[i] << ' ';
  fout << res[6] << '\n';
}
