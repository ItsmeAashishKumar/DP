
1
#include <bits/stdc++.h> 
2
​
3
int helper(int i,int j,vector<vector<int>> &dp){
4
    if(i==0 && j==0){
5
        return 1;
6
    }
7
    if(i<0 || j<0){
8
        return 0;
9
    }
10
    if(dp[i][j]!=-1){
11
        return dp[i][j];
12
    }
13
    int up=helper(i-1,j,dp);
14
    int left=helper(i,j-1,dp);
15
    return dp[i][j]=up+left;
16
}
17
int uniquePaths(int m, int n) {
18
    // Write your code here.
19
    int dp[m][n];
20
    for(int i=0;i<m;i++){
21
        for(int j=0;j<n;j++){
22
            if(i==0 && j==0){
23
                dp[i][j]=1;
24
            }
25
            else{
26
                int up=0;
27
                int left=0;
28
                if(i>0){
29
                    up=dp[i-1][j];
30
                }
31
                if(j>0){
32
                    left=dp[i][j-1];
33
                }
34
                dp[i][j]=left+up;
35
            }   
36
        }
37
    }
38
    return dp[m-1][n-1];
39
}
