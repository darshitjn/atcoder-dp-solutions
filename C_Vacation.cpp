#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    /*
    state -> maximum happiness till the ith day if last activity of the ith day is A/B/C
    combining states -> maximum happiness till (i+1)th day for activity A will be:
    maximum of (happiness till (i-1)th day if last activity was B) and 
               (happiness till (i-1)th day if last activity was C)
                + happiness from activity A on the ith day
            // note that we cannot take happiness of (i-1)th day if last activity was A
            // as we cannot do Ath activity on the consecutive days

    Time complexity = O(n) .   Space complexity = O(n) 
    */

    // input and initialization with 1 indexing
    int n; cin >> n;
    int happy[n+1][3];
    for(int i = 1; i<=n; i++)
       for(int j = 0; j<3; j++)
           cin >> happy[i][j];

    // 1 indexing by keeping happiness 0 on the 0th day for every activity
    int dp[n+1][3] = {};

    for(int i = 1; i<=n; i++){
        dp[i][0] = max(dp[i-1][1],dp[i-1][2]) + happy[i][0];
        dp[i][1] = max(dp[i-1][0],dp[i-1][2]) + happy[i][1];
        dp[i][2] = max(dp[i-1][0],dp[i-1][1]) + happy[i][2];
    }
    
    int ans = max(max(dp[n][0],dp[n][1]),dp[n][2]);
    cout << ans << endl;
    return 0;
}
