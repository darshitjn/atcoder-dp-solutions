#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+7;
const int inf = 1e15+7;

int32_t main(){
    /*
    knapsack problem with slight state variation
    As total value possible that we can take is less as well as the number of items, we can 
    apply knapsack dp on value possible and items
    state v,i -> minimum possible weight we can take if the value till i is v
    combining states -> for every item we can choose if we will be taking it or not
                        if the value is v
    getting answer -> if the minimum weight needed for getting value is less than w
    then we can take that weight
    */

    // input and initialization with 1 indexing
    int n,w; cin >> n >> w;
    int items[n+1][2];

    for(int i = 1; i<=n; i++)
       for(int j = 0; j<2; j++)
           cin >> items[i][j];

    int dp[N] = {};
    for(int i = 1; i<N; i++){dp[i] = inf;}
    dp[0] = 0;
    int ans = 0;

    for(int i = 1; i<=n; i++){
         for(int v = N-1; v>0; v--){
            if(items[i][1]>v){continue;}
            dp[v] = min(dp[v],dp[v-items[i][1]]+items[i][0]);
        }
    }
    
    for(int i = 1; i<N; i++){
        ans = max(ans,(dp[i]<=w)*i);
    }
    
    cout << ans << endl;
    return 0;
}
