#include <iostream>
using namespace std;

int main() {
  char buff[100];
  int i,res,p;

  while (cin.getline(buff,sizeof(buff))) {
    i = 0;
    while (buff[i]) {
      ++i;
    }
    --i;
    if (buff[0]=='0') return 0;
    res = 0;
    p = 2;
    while (i>=0) {
      res += ((int)buff[i]-'0')*(p-1);
      p *= 2;
      --i;
    }
    cout << res << '\n';
  }
  
  
  return 0;
}
