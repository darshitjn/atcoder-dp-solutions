#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    dp[i][j] -> number of method to go to (i,j) from (0,0)
    // if (i,j) is a wall square then number of methods to go to (i,j) is 0
    transition -> we can go to (i,j) from (i-1,j) or (i,j+1), so
    dp[i][j] = dp[i-1][j] + dp[i][j-1]
    TC :- O(n*m) .   SC :- O(n*m)
    */
    int h,w; cin >> h >> w;
    string s[h];
    for(int i = 0; i<h; i++)
        cin >> s[i];
    int dp[h+1][w+1] = {};
    dp[1][0] = (s[0][0]=='.');

    for(int i = 1; i<=h; i++){
        for(int j = 1; j<=w; j++){
            if(s[i-1][j-1]=='#'){continue;}
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
            if(dp[i][j]>=mod){dp[i][j] -= mod;}
        }
    }

    cout << dp[h][w] << endl;
    return 0;
}
