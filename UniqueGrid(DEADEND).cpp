int helper(int i,int j,vector<vector<int>> &dp,vector< vector< int> > &mat){
    if(i==0 && j==0){
        return 1;
    }
    if(i<0 || j<0){
        return 0;
    }
    if(i>=0 && j>=0 && mat[i][j]==-1){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int up=helper(i-1,j,dp,mat);
    int left=helper(i,j-1,dp,mat);
    return dp[i][j]=up+left;
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
   int dp[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0){
                dp[i][j]=1;
            }
            else if(mat[i][j]==-1){
                dp[i][j]=0;
            }
            else{
                int up=0;
                int left=0;
                if(i>0){
                    up=dp[i-1][j];
                }
                if(j>0){
                    left=dp[i][j-1];
                }
                dp[i][j]=left+up;
            }   
        }
    }
    return dp[n-1][m-1];
}