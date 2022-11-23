#include <bits/stdc++.h> 
bool f(int ind,int target,vector<int> &arr,vector<vector<int>> &dp){
    if(target==0){
        return true;
    }
    if(ind==0){
        return (arr[0]==target);
    }
    if(dp[ind][target]!=-1){
        return dp[ind][target];
    }
    bool nottake=f(ind-1,target,arr,dp);
    
    bool take=false;
    if(target>=arr[ind]){
        take=f(ind-1,target-arr[ind],arr,dp);
    }
    
    return dp[ind][target]=take || nottake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<bool>> dp(n,vector<int>(k+1,-1));
    for(int i=0;i<n;i++){
        dp[i][0]=true;
    }
    dp[0][arr[0]]=true;
    
    for(int i=1;i<n;i++){
        for(int target=1;target<=k;target++){
            bool nottake=dp[i-1][target];
            bool take=false;
            if(target>=arr[i]){
                take=dp[i-1][target-arr[i]];
             }
             dp[i][target]=take||nottake;       
        }
    }
    return dp[n-1][k];
}