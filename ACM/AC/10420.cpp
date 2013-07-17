#include<iostream>
#include<string>
#include<map>
#include<fstream>

using namespace std;

int main(){
  //  ifstream cin("in");
  int n;
  map< string, int > m;
  cin >> n;
  for(int i=0;i<n;++i){
    string country;
    cin >> country;
    m[country]++;
    getline(cin, country);
  }

   for (map<string,int>::iterator it=m.begin() ; it != m.end(); it++ )
    cout << (*it).first << ' ' << (*it).second << endl;

}
