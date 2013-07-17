/*
  ID: blabla41
  PROG: fracdec
  LANG: C++
*/
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

bool vu[100001];
int c[100001]={0};
int N,D;
char nums[100000];int l=0;
int main()
{
  freopen("fracdec.in","r",stdin);
  freopen("fracdec.out","w",stdout);
  scanf("%d%d",&N,&D);
  int num1=N/D;
  if(num1==0)
    nums[++l]='0';
  else
    while(num1)
      {
	nums[++l]=char(num1%10+(int)'0');
	num1/=10;
      }
  char t;
  for(int a=1;a<=l/2;a++)
    {t=nums[a];nums[a]=nums[l-a+1];nums[l-a+1]=t;}
  nums[++l]='.';
  N%=D;
  if(N==0)
    nums[++l]='0';
  else
    while(N)
      {
	if(!vu[N])
	  {
	    vu[N]=true;
	    c[N]=l+1;
	    N*=10;
	    nums[++l]=char(N/D+(int)'0');
	    N%=D;
	  }
	else
	  break;
      }
  if(c[N])
    {
      int ccount=0;
      for(int a=1;a<=c[N]-1;a++)
	{printf("%c",nums[a]);ccount++;if(ccount%76==0){ccount=0;printf("\n");}}
      printf("(");ccount++;if(ccount%76==0){ccount=0;printf("\n");}
      for(int a=c[N];a<=l;a++)
	{printf("%c",nums[a]);ccount++;if(ccount%76==0){ccount=0;printf("\n");}}
      printf(")");
    }
  else
    {
      int ccount=0;
      for(int a=1;a<=l;a++)
	{printf("%c",nums[a]);ccount++;if(ccount%76==0&&a!=l){ccount=0;printf("\n");}}
    }
  printf("\n");
  return 0;
}
