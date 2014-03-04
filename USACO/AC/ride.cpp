/*
ID: blabla41
PROG: ride
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
  ofstream fout ("ride.out");
  ifstream fin ("ride.in");

  string comet, people;
  int res_comet, res_people;
  fin >> comet;
    res_comet=res_people=1;
  for(int i=0;i<comet.size();++i)
    res_comet= (res_comet*(comet[i]-'A'+1)) % 47;
  fin >> people;
  for(int i=0;i<people.size();++i)
    res_people= (res_people*(people[i]-'A'+1)) % 47;

  (res_people==res_comet) ? fout << "GO\n" : fout << "STAY\n";
}
