#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

struct letter{
  char l;
  int  nb;
  letter(char a='a', int c=0):l(a), nb(c){};

  bool operator<(const letter& le) const{
    return nb<le.nb || (nb==le.nb && l<le.l);
  }
};

int main(){
  int T;
  cin >> T;
  while(T--){
    string code;
    cin >> code;
    cin.ignore();
    string message;
    getline(cin, message);
    
    vector<letter> l(26);
    for(int i=0;i<int(message.size());++i)
      if(isalpha(message[i])){
	char c=tolower(message[i]);
	l[c-'a'].l=c;
	l[c-'a'].nb++;
      }
    
    sort(begin(l), end(l));
    
    vector<char> translate(26, 'a');

    for(int i=0;i<26;++i)
      translate[l[i].l-'a']=code[i];
    
    for(char c:message)
      if(isalpha(c)){
	if(islower(c))
	  cout << translate[c-'a'];
	else
	  cout << char(toupper(translate[char(tolower(c))-'a']));
      }
      else
	cout << c;
    cout << '\n';

  }
}
