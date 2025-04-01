#include <iostream>
#include <string>
#include <vector>

using namespace std;


string decrypt( const string& word ) 
{
  vector<int> ans;
   for(auto c : word){
     ans.push_back(c-'0');
   }
  
  int sumnow = 1;
 
  for(int i =0; i<ans.size();i++){
    //ans[i] = dec[i] + sumnow + 26*x;
    ans[i]-=sumnow;

    while(ans[i] < 97){
        ans[i]+=26;
    }
    sumnow+=ans[i];
  }
  
  string anss;
  for(auto a: ans)
    anss+=(a+'0');
  return anss;
}

int main() {
  return 0;
}
