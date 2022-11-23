int f(int ind,vector<int> &weight,vector<int> &value,int maxWeight, vector<vector<int>> &dp){
    if(ind==0){
        if(weight[ind]<=maxWeight){
            return value[ind];
        }
        else{
            return 0;
        }
    }
    if(dp[ind][maxWeight]!=-1){
        return dp[ind][maxWeight];
    }
    int notpick=0+f(ind-1,weight,value,maxWeight,dp);
    int pick=INT_MIN;
    if(weight[ind]<=maxWeight){
        pick=value[ind]+f(ind-1,weight,value,maxWeight-weight[ind],dp);
    }
    
    return dp[ind][maxWeight]=max(notpick,pick);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here 
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,0));
    for(int w=weight[0];w<=maxWeight;w++){
        dp[0][w]=value[0];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=maxWeight;j++){
            int notpick=0+dp[i-1][j];
            int pick=INT_MIN;
            if(weight[i]<=maxWeight){
                pick=value[i]+dp[i-1][j-weight[i]];
            }
            dp[i][j]=max(pick,notpick);
        }
    }
    return dp[n-1][maxWeight];
	
}