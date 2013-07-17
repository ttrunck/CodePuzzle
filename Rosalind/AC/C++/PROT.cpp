#include<iostream>
#include<string>

using namespace std;

int main(){
  string s;
  cin >> s;
  for(int i=0;i<int(s.size());i+=3){
    const string tmp=s.substr(i,3); 
    if(tmp=="UUU")
      cout << 'F';
    else if(tmp=="UUC")
      cout << 'F';
    else if(tmp=="UUA")
      cout << 'L';
    else if(tmp=="UUG")
      cout << 'L';
    else if(tmp=="UCU")
      cout << 'S';
    else if(tmp=="UCC")
      cout << 'S';
    else if(tmp=="UCA")
      cout << 'S';
    else if(tmp=="UCG")
      cout << 'S';
    else if(tmp=="UAU")
      cout << 'Y';
    else if(tmp=="UAC")
      cout << 'Y';
    else if(tmp=="UAA")
      break;
    else if(tmp=="UAG")
      break;
    else if(tmp=="UGU")
      cout << 'C';
    else if(tmp=="UGC")
      cout << 'C';
    else if(tmp=="UGA")
      break;
    else if(tmp=="UGG")
      cout << 'W';
    else if(tmp=="CUU")
      cout << 'L';
    else if(tmp=="CUC")
      cout << 'L';
    else if(tmp=="CUA")
      cout << 'L';
    else if(tmp=="CUG")
      cout << 'L';
    else if(tmp=="CCU")
      cout << 'P';
    else if(tmp=="CCC")
      cout << 'P';
    else if(tmp=="CCA")
      cout << 'P';
    else if(tmp=="CCG")
      cout << 'P';
    else if(tmp=="CAU")
      cout << 'H';
    else if(tmp=="CAC")
      cout << 'H';
    else if(tmp=="CAA")
      cout << 'Q';
    else if(tmp=="CAG")
      cout << 'Q';
    else if(tmp=="CGU")
      cout << 'R';
    else if(tmp=="CGC")
      cout << 'R';
    else if(tmp=="CGA")
      cout << 'R';
    else if(tmp=="CGG")
      cout << 'R';
else if(tmp=="AUU")
      cout << 'I';
    else if(tmp=="AUC")
      cout << 'I';
    else if(tmp=="AUA")
      cout << 'I';
    else if(tmp=="AUG")
      cout << 'M';
    else if(tmp=="ACU")
      cout << 'T';
    else if(tmp=="ACC")
      cout << 'T';
    else if(tmp=="ACA")
      cout << 'T';
    else if(tmp=="ACG")
      cout << 'T';
    else if(tmp=="AAU")
      cout << 'N';
    else if(tmp=="AAC")
      cout << 'N';
    else if(tmp=="AAA")
      cout << 'K';
    else if(tmp=="AAG")
      cout << 'K';
    else if(tmp=="AGU")
      cout << 'S';
    else if(tmp=="AGC")
      cout << 'S';
    else if(tmp=="AGA")
      cout << 'R';
    else if(tmp=="AGG")
      cout << 'R';
else if(tmp=="GUU")
      cout << 'V';
    else if(tmp=="GUC")
      cout << 'V';
    else if(tmp=="GUA")
      cout << 'V';
    else if(tmp=="GUG")
      cout << 'V';
    else if(tmp=="GCU")
      cout << 'A';
    else if(tmp=="GCC")
      cout << 'A';
    else if(tmp=="GCA")
      cout << 'A';
    else if(tmp=="GCG")
      cout << 'A';
    else if(tmp=="GAU")
      cout << 'D';
    else if(tmp=="GAC")
      cout << 'D';
    else if(tmp=="GAA")
      cout << 'E';
    else if(tmp=="GAG")
      cout << 'E';
    else if(tmp=="GGU")
      cout << 'G';
    else if(tmp=="GGC")
      cout << 'G';
    else if(tmp=="GGA")
      cout << 'G';
    else
      cout << 'G';
  }
  cout << endl;
}
