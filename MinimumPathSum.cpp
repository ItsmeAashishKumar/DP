#include <bits/stdc++.h> 
int helper(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &dp){
    if(i==0 && j==0){
        return grid[0][0];
    }
    if(i<0 || j<0){
        return 1e9;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int up=grid[i][j]+helper(i-1,j,grid,dp);
    int left=grid[i][j]+helper(i,j-1,grid,dp);
    return dp[i][j]=min(up,left);
}
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n=grid.size();
    int m=grid[0].size();
    int dp[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0){
                dp[i][j]=grid[i][j];
            }
            else{
                int up=0;
                int left=0;
                up=grid[i][j];
                if(i>0){
                    up+=dp[i-1][j];
                }
                else{
                    up+=1e9;
                }
                left=grid[i][j];
                if(j>0){
                    left+=dp[i][j-1];
                }
                else{
                    left+=1e9;
                }
                dp[i][j]=min(up,left);
            }
        }
    }
    return dp[n-1][m-1];
}