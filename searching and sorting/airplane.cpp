#include <bits/stdc++.h>
using namespace std;

int customerComputers(int n, string s){
    unordered_map<char, int> mp;
    int total = 0;
    int ans = 0;
    for(int i = 0;i<s.size();i++)
    {
       if(total < n){
           if(mp[s[i]] == 1){
           mp[s[i]]--;
           total--;
           }else{
               mp[s[i]]++;
               total++;
           }
       }
       else if(total == n && mp[s[i]] == 1){
           mp[s[i]]--;
           total--;
       }else{
           if(mp[s[i]] == 1){
           mp[s[i]]--;
           }else{
               mp[s[i]]++;
           }
           ans++;
       }
    }
    return ans;
}

int main()
{
    int computers;
    cin >> computers;
    string str;
    cin >> str;
    int ans = customerComputers(computers, str);
    cout << ans << endl;
}