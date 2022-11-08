#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    /*
    subproblem -> getting a minimum cost for reaching i-1, i-2,..., i-kth stone
    combining subproblem -> minimum cost for reaching ith stone will be
    minimum of (cost to reach i-1th stone + going from i-1 -> i) and 
               (cost to reach i-2th stone + going from i-2 -> i) till
               (cost to reach i-kth stone + going from i-k -> i)

    Time complexity = O(n*k) .   Space complexity = O(n) 
    */

    // input and initialization with 0 indexing
    int n,k; cin >> n >> k;
    vector <int> h(n);
    for(auto &x:h){cin >> x;}
    int dp[n];

    // base case -> cost for reaching the first stone will be 0
    dp[0] = 0;
    
    for(int i = 1; i<n; i++){
        dp[i] = INT_MAX;
        for(int j = max(i-k,0); j<i; j++)
            dp[i] = min(dp[j]+abs(h[i]-h[j]),dp[i]);

    }
    
    cout << dp[n-1] << endl;
    return 0;
}
