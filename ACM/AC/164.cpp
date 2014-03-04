#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<iomanip>



using namespace std;

int aux(const string & s1, const string & s2, int i, int j, vector<vector<int> > & t){
  if(i==int(s1.size())) return s2.size()-j;
  if(j==int(s2.size())) return s1.size()-i;
  if(t[i][j]!=-1) return t[i][j];
  if(s1[i]==s2[j]) return aux(s1, s2, i+1, j+1, t);
  return t[i][j]=1+min(aux(s1, s2, i+1, j+1, t), min(aux(s1, s2, i+1, j, t), aux(s1, s2, i, j+1, t)));
}

int main(){
  string s1, s2;
  while(cin >> s1 >> s2 && s1!="#"){
    vector<vector<int> > t(s1.size(), vector<int>(s2.size(),-1));
    // cerr << aux(s1, s2, 0, 0, t) << endl;
    
    int curr=1;
    int i,j;
    for(i=0, j=0;i<int(s1.size()) && j<int(s2.size());){
      if(s1[i]==s2[j]){
	j++;i++;
	curr++;
      }
      if(i<int(s1.size()) && j<int(s2.size()) && aux(s1,s2,i,j,t)==1+aux(s1,s2,i+1,j+1,t)){
	cout << 'C' << s2[j] << setfill('0') << setw(2) << curr++;
	j++;i++;
      }
      else if(i<int(s1.size()) && aux(s1,s2,i,j,t)==1+aux(s1,s2,i+1,j,t)){
	cout << 'D' << s1[i] << setfill('0') << setw(2) << curr;
	i++;
      }
      else if(j<int(s2.size()) && aux(s1,s2,i,j,t)==1+aux(s1,s2,i,j+1,t)){
	cout << 'I' << s2[j] << setfill('0') << setw(2) << curr++;
	j++;	
      }
    }
    for(;i<int(s1.size());++i)
      cout << 'D' << s1[i] << setfill('0') << setw(2) << curr;
    for(;j<int(s2.size());++j)
      cout << 'I' << s2[j] << setfill('0') << setw(2) << curr++;
    cout << "E\n";
  }
}
