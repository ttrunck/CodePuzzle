#include<iostream>
#include<string>
#include<vector>

using namespace std;

const vector<string> t{
  "O-|-OOOO",
    "O-|O-OOO",
    "O-|OO-OO",
    "O-|OOO-O",
    "O-|OOOO-",
    "-O|-OOOO",
    "-O|O-OOO",
    "-O|OO-OO",
    "-O|OOO-O",
    "-O|OOOO-",
    };

int main(){
  int n;
  cin >> n;
  do{
    cout << t[n%10] << '\n';
    n/=10;
  }while(n);
}
