#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    /*
    subproblem -> getting a minimum cost for reaching i-1th and i-2th stone
    combining subproblem -> minimum cost for reaching ith stone will be
    minimum of (cost to reach i-1th stone + going from i-1 -> i) and 
               (cost to reach i-2th stone + going from i-2 -> i)
    */

    // input and initialization with 0 indexing
    int n; cin >> n;
    vector <int> h(n);
    for(auto &x:h){cin >> x;}
    int dp[n];

    // base case -> cost for reaching the first stone will be 0 and reaching second 
    // stone will be abs(h[1]-h[0])
    dp[0] = 0; dp[1] = abs(h[1]-h[0]);
    
    for(int i = 2; i<n; i++){
        dp[i] = min(dp[i-1]+abs(h[i]-h[i-1]),dp[i-2] + abs(h[i]-h[i-2]));
    }
    
    cout << dp[n-1] << endl;
    return 0;
}
