#include<iostream>
#include<string>
#include<cstdio>

using namespace std;

int con, disc;
int t[10000000];

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

void connec(int a, int b){
  if(find(a)==find(b))
    con++;
  else 
    disc++;
  return;
}

int main(){
  string line;
  int cas, n;

  getline(cin, line);
  sscanf(line.c_str(), "%d", &cas);
  getline(cin, line); // Ignore la ligne vide avant la première instance
for (int iCase = 1; iCase <= cas; iCase++) {
    // Lecture du nombre d'ordinateurs
    getline(cin, line);
    sscanf(line.c_str(), "%i", &n);
    
    for(int i=0;i<n;++i)
      t[i]=i;
    con=0;
    disc=0;
    string line;
    while (getline(cin, line) && !line.empty()) {
      char c;  
      int a, b;
      sscanf(line.c_str(), " %c %i %i", &c, &a, &b);

      if(c=='c')
	add(a-1,b-1);
      else
	connec(a-1,b-1);
    }
    if(iCase!=1)
      cout << endl;
    cout << con << ',' << disc << endl;
  }
}
