#include<iostream>
#include<vector>

using namespace std;

typedef long long ent;

const int N=100000000;

void sieve(vector<bool> &crossed, int limit) {
	crossed.assign(limit / 2, false);
	crossed[0] = true;
	for (int i = 1; 4 * i * i < limit; ++i)
		if (not crossed[i])
			for (int j = 2 * i * (i + 1); 2 * j < limit; j += 2 * i + 1)
				crossed[j] = true;
}

bool isPrime(vector<bool> &crossed, int i) {
	if (i == 2) return true;
	if (i % 2 == 0) return false;
	return not crossed[(i - 1) / 2];
}

ent powMod(ent x, ent n, ent m) {
	ent y = 1;
	while (n != 0) {
		if ((n & 1) == 1)
			y = (y * x) % m;
		x = (x * x) % m;
		n = n >> 1;
	}
	return y;
}

ent invMod(ent x, ent p) { return powMod(x, p - 2, p); }

ent s(ent p){
  ent res=p-1;
  ent tmp=p-1;
  for(int i=1;i<5;++i){
    tmp= (tmp*invMod(p-i, p))%p;
    res=(res+tmp)%p;
  }
  return res;
}

int main(){
  vector<bool> p;
  sieve(p,N);
  ent res=0;
  for(int i=5;i<N;++i)
    if(isPrime(p, i))
      res+=s(i);
  cout << res << endl;
}
