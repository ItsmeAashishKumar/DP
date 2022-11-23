#include <bits/stdc++.h> 

int helper(int ind,vector<int> &nums,vector<int> &dp){
    /*ind==0){
        return nums[ind];
    }
    if(ind<0){
        return 0;
    }
    if(dp[ind]!=-1){
        return dp[ind];
    }
    int take=nums[ind]+helper(ind-2,nums,dp);
    int nottake=0+helper(ind-1,nums,dp);
    return dp[ind]=max(take,nottake);
    */
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    vector<int> dp(n);
    dp[0]=0;
    for(int i=1;i<n;i++){
        int take=nums[i];
        if(i>1){
            take+=dp[i-2];
        }
        int nottake=dp[i-1];
        dp[i]=max(take,nottake);
    }
    return dp[n-1];
}