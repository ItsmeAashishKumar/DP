#include <bits/stdc++.h> 
int f(vector<int> &arr){
    int n=arr.size();
    int prev=arr[0];
    int prev2=0;
    for(int i=1;i<n;i++){
        int take=arr[i];
        if(i>1){
            take+=prev2;
        }
        int nottake=0+prev;
        int curi=max(take,nottake);
        prev2=prev;
        prev=curi;
    }
    return prev;
    
}
long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    vector<int> temp1,temp2;
    int n=valueInHouse.size();
    if(n==1){
        return valueInHouse[0];
    }
    for(int i=0;i<n;i++){
        if(i!=0){
            temp1.push_back(valueInHouse[i]);
        }
        if(i!=n-1){
            temp2.push_back(valueInHouse[i]);
        } 
    }
    return max(f(temp1),f(temp2));
}