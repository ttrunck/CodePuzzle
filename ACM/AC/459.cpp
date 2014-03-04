#include<iostream>
#include<string>
#include<cstdio>

using namespace std;

int con, disc;
int t[100];
bool compt[100];

int find(int a){
  if(t[a]==a) return a;
  int tmp=find(t[a]);
  t[a]=tmp;
  return tmp;
}

void add(int a, int b){
    t[find(a)]=find(b);
  return;
}

int main(){
  string line;
  int cas, n;

  getline(cin, line);
  sscanf(line.c_str(), "%d", &cas);
  getline(cin, line);
  for (int iCase = 1; iCase <= cas; iCase++) {
    getline(cin, line);
    char paf;
    sscanf(line.c_str(), "%c", &paf);
    n=paf-'A'+1;
    for(int i=0;i<n;++i)
      t[i]=i;

    string line;
    while (getline(cin, line) && !line.empty()) {
      char a, b;
      sscanf(line.c_str(), "%c%c", &a, &b);
      add(a-'A', b-'A');
    }
    if(iCase!=1)
      printf("\n");
    for(int i=0;i<100;++i)
      compt[i]=false;
    for(int i=0;i<n;++i)
      compt[find(i)]=true;
    int res=0;
    for(int i=0;i<n;++i)
      if(compt[i]) res++;
    printf("%d\n", res);

  }
}
