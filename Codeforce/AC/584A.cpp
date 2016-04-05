#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

int main() {
  int n, t;
  cin >> n >> t;
  if(n == 1 && t == 10)
    cout << -1 << '\n';
  else if(n == 1)
    cout << t << '\n';
  else {
    string res = "1";
    int mod = 1;
    while(res.size() != n) {
      res += '0';
      mod = (10*mod)%t;
    }
    res[n-1] = (t - mod)%t + '0';
    cout << res << '\n';
  }
}
