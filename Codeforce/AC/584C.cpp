#include <iostream>

using namespace std;

char diff(char a, char b) {
  char res = 'a';
  while (res == a || res == b)
    ++res;
  return res;
}

int main() {
  int n, t;
  cin >> n >> t;
  string s1, s2;
  cin >> s1 >> s2;
  int nbDiff = 0;
  for(int i=0;i<n;++i)
    if(s1[i]  != s2[i])
      ++nbDiff;
  if((nbDiff+1)/2 > t)
    cout << -1 << '\n';
  else {
    int nbZero = min(n-nbDiff, n-t);
    int copie1 = n-t - nbZero;
    int copie2 = n-t - nbZero;

    string res = "";
    for(int i=0;i<n;++i) {
      if(s1[i] != s2[i]) {
        if(copie1) {
          copie1--;
          res += s1[i];
        }
        else if(copie2) {
          copie2--;
          res += s2[i];
        }
        else
          res += diff(s1[i], s2[i]);
      }
      else {
        if(nbZero) {
          nbZero--;
          res += s1[i];
        }
        else
          res += diff(s1[i], s2[i]);
      }
    }
    cout << res << '\n';
  }
}
