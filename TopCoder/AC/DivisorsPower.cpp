#include<sstream>
#include<string>
#include<vector>
#include<iostream>
#include <cmath>

using namespace std;

typedef long long ll;

ll d(ll n){
	ll res = 0;
	ll i;
	for(i=1;i*i<n;++i)
		if(n%i==0) res+= 2;
	if(i*i == n) ++res;
	return res;
}

ll mpow(ll x, ll n) {
	ll y = 1;
	while (n != 0) {
		if ((n & 1) == 1)
			y = (y * x);
		x = (x * x);
		n = n >> 1;
	}
	return y;
}

 class DivisorsPower
        { 
        public: 
        long long findArgument(long long n) 
            { 
            	for(double i=20;i>=2;--i){
            		ll target = pow(n, 1/i);
            		for(ll candidate = max(0LL, target-5);candidate<=target+5;++candidate){
            		if(mpow(candidate, i) == n && d(candidate) == i)
            			return candidate;
            		}
            	}
            	return -1;
            } 
        
 
        }; 



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
