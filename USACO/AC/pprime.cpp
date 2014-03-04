/*
ID: blabla41
PROG: pprime
LANG: C++
 */

/*any odd palindrome except 11 is not prime so I could imrpove that code*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

bool prime(int i){
  if (i==2) return true;
  if (i%2==0) return false;
  int k=3;
  while(k<=sqrt(i)){
    if (i%k==0) return false;
    k+=2;
  }
  return true;
}

int mini, maxi;

int main(){
  ofstream fout ("pprime.out");
  ifstream fin ("pprime.in");
  int palindrome;
  fin >> mini >> maxi;

  int d1,d2,d3,d4;
/* generate one digit palindrome: */
  for (d1 = 1; d1 <= 9; d1++){
    palindrome = d1;
    if (palindrome>=mini && palindrome <=maxi)
      if (prime(palindrome))
	fout << palindrome << '\n';
}

/* generate two digit palindrome: */
  for (d1 = 1; d1 <= 9; d1+=2) {
	palindrome = 10*d1+d1;
	if (palindrome>=mini && palindrome <=maxi)
	  if (prime(palindrome))
	    fout << palindrome << '\n';
}

/* generate three digit palindrome: */
  for (d1 = 1; d1 <= 9; d1+=2)
    for (d2 = 0; d2 <= 9; d2++){
	palindrome = 100*d1 + 10*d2 + d1;
	if (palindrome>=mini && palindrome <=maxi)
	  if (prime(palindrome))
	    fout << palindrome << '\n';
}

/* generate four digit palindrome: */
  for (d1 = 1; d1 <= 9; d1+=2)
    for (d2 = 0; d2 <= 9; d2++){
	palindrome = 1000*d1 + 100*d2 + 10*d2 + d1;
	if (palindrome>=mini && palindrome <=maxi)
	  if (prime(palindrome))
	    fout << palindrome << '\n';
}


/* generate five digit palindrome: */
  for (d1 = 1; d1 <= 9; d1+=2)
    for (d2 = 0; d2 <= 9; d2++)
      for (d3 = 0; d3 <= 9; d3++) {
	palindrome = 10000*d1 + 1000*d2 +100*d3 + 10*d2 + d1;
	if (palindrome>=mini && palindrome <=maxi)
	  if (prime(palindrome))
	    fout << palindrome << '\n';
}

/* generate six digit palindrome: */
  for (d1 = 1; d1 <= 9; d1+=2)
    for (d2 = 0; d2 <= 9; d2++)
      for (d3 = 0; d3 <= 9; d3++) {
	palindrome = 100000*d1 + 10000*d2 +1000*d3 +100*d3 + 10*d2 + d1;
	if (palindrome>=mini && palindrome <=maxi)
	  if (prime(palindrome))
	    fout << palindrome << '\n';
}

/* generate seven digit palindrome: */
  for (d1 = 1; d1 <= 9; d1+=2)
    for (d2 = 0; d2 <= 9; d2++)
      for (d3 = 0; d3 <= 9; d3++) 
	for(d4 = 0; d4<=9; d4++){
	palindrome = 1000000*d1 + 100000*d2 +10000*d3 + 1000*d4 +100*d3 + 10*d2 + d1;
	if (palindrome>=mini && palindrome <=maxi)
	  if (prime(palindrome))
	    fout << palindrome << '\n';
}

/* generate eight digit palindrome: */
  for (d1 = 1; d1 <= 9; d1+=2)
    for (d2 = 0; d2 <= 9; d2++)
      for (d3 = 0; d3 <= 9; d3++) 
	for(d4 = 0; d4<=9; d4++){
	palindrome = 10000000*d1 + 1000000*d2 +100000*d3 + 10000*d4 + 1000*d4 +100*d3 + 10*d2 + d1;
	if (palindrome>=mini && palindrome <=maxi)
	  if (prime(palindrome))
	    fout << palindrome << '\n';
}



}
