#include <bits/stdc++.h>
using namespace std;

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
/*
state i represents length of longest directed path which end at node i
transition -> let (i,j) be the edge from i to j. Then for every edge ending at j,
               the longest path ending at node j will be max(dp[i]+1) for all i 
               directed to j
if indegree of a node is zero, that means that now its answer is fixed because there are
no nodes going in that node i.e. all nodes are processed. So we can push all those nodes
in queue whose indegree is zero so that we can get an answer respective to that node. Then
we can remove that node and count again which nodes have indegree 0 after removal of that 
node
TC -> O(n+m) // going to every node only one time and traversing all the edges
SC -> O(n+m)
*/
int n,m,a,b; cin >> n >> m;
vector <int> edges[n];
int dp[n] = {};
int indegree[n] = {};
int ans = 0;
while(m--){
   cin >> a >> b;
   edges[--b].push_back(--a);
   indegree[a]++;
}

queue <int> q;
for(int i =0; i<n; i++){
   if(indegree[i]==0){
      q.push(i);
   }
}

while(q.size()){
   int node = q.front();
   q.pop();
   for(auto x:edges[node]){
      dp[x] = max(dp[x],dp[node]+1);
      indegree[x]--;
      if(indegree[x]==0){q.push(x);}
      ans = max(ans,dp[x]);
   }
}

cout << ans << endl;
}
