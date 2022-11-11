#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    dp[i][j] -> probability of getting j heads in elements from 0 till i
    transition -> either the ith element can be head or it can be tail
    . So the probability of getting j heads is either it has a tail and there were already
    j heads till i-1 elements or i-1 elements got j-1 heads and ith element is head
    
    Then we can add the answer of getting more heads than tales till n elements
    TC :- O(n^2) .   SC :- O(n^2)
    */
    int n; cin >> n;
    vector <double> p(n);
    double one = 1.00;
    for(auto &x:p){cin >> x;}
    double dp[n][n+1];
    dp[0][1] = p[0];
    dp[0][0] = one-p[0];

    for(int i = 1; i<n; i++){
        dp[i][0] = dp[i-1][0]*(one-p[i]);
        for(int j = 1; j<=i+1; j++){
           dp[i][j] = dp[i-1][j-1]*(p[i]) + dp[i-1][j]*(one-p[i]);
        }
    }
    
    double ans = 0;
    for(int j = n; j>n/2; j--){
        ans += dp[n-1][j];
    }
    cout << setprecision(20) << ans << endl;
    return 0;
}
