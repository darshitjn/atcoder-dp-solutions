#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    /*
    Standard knapsack problem 
    As total weight that we can take is less as well as the number of items, we can 
    apply knapsack dp on weight and items
    state w,i -> Maximum possible sum taro can take if the weight of knapsack is atmost w
                 and items are till i
    combining states -> for every item we can choose if we will be taking it or not
                        if the weight is w
    */

    // input and initialization with 1 indexing
    int n,w; cin >> n >> w;
    int items[n+1][2];

    for(int i = 1; i<=n; i++)
       for(int j = 0; j<2; j++)
           cin >> items[i][j];

    int dp[w+1] = {};
    int ans = 0;

    for(int i = 1; i<=n; i++){
         for(int wt = w; wt>=0; wt--){
            if(items[i][0]>wt){continue;}
            dp[wt] = max(dp[wt],dp[wt-items[i][0]]+items[i][1]);
            ans = max(ans,dp[wt]);
        }
    }
    
    cout << ans << endl;
    return 0;
}
