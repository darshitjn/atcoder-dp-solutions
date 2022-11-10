#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second 

template <typename T> void selfmax(T &a, T b){
   a = max(a,b);
}

int32_t main(){
   /*
   state -> (i,j) gives the max. length of substring when string 's' till i
            and string 't' till j is taken
   transition -> (i,j) can be max(i,j-1) or (i-1,j) but if the s[i]==t[j]
   then we take the dp[i-1][j-1] and then add i,j to it
   retrieval of answer string 
   in dp[i][j].second we store the current maximum state (a,b) till (i,j)
   so to go to the previous state we take (a-1,b-1) state and check the max till that
   */
   string s,t; cin >> s >> t; 
   pair <int,int> neg = {-1,-1};
   int n = s.length();
   int m = t.length();
   pair <int,pair<int,int>> dp[n+1][m+1] = {};

   for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
         selfmax(dp[i+1][j+1],dp[i][j+1]);
         selfmax(dp[i+1][j+1],dp[i+1][j]);
         if(s[i]==t[j]){
            selfmax(dp[i+1][j+1],{dp[i][j].F+1,{i,j}});
         }
      }
   }

   pair <int,int> mx_ans = dp[n][m].S;
   int mx_val = dp[n][m].F;

   string ans;
   while(mx_val--){
      ans += s[mx_ans.F];
      mx_ans = dp[mx_ans.F][mx_ans.S].S;
   }

   reverse(ans.begin(),ans.end());
   cout << ans << endl;
}
