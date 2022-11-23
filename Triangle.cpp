#include <bits/stdc++.h> 
int f(int i,int j,vector<vector<int>>& triangle,int n,vector<vector<int>> &dp){
    if(i==n){
        return triangle[i][j];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int down=triangle[i][j]+f(i+1,j,triangle,n,dp);
    int dg=triangle[i][j]+f(i+1,j+1,triangle,n,dp);
    
    return dp[i][j]=min(down,dg);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
    int dp[n][n];
    for(int j=0;j<n;j++){
        dp[n-1][j]=triangle[n-1][j];
    }
    for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            int up=triangle[i][j]+dp[i+1][j];
            int dg=triangle[i][j]+dp[i+1][j+1];
            dp[i][j]=min(up,dg);
        }
    }
    return dp[0][0];
}