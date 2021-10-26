//C++ code for Matrix Chain Multiplication
//problem by top_down approach

#include <bits/stdc++.h>
using namespace std;

//making a dp matrix to store results after each call
int dp[500][500];
//MCM function to calculate minimum number of
//operations required to multiply all matrices

int MCM (int arr[], int i, int j)
{
    //base case
    if(i==j)return dp[i][j]=0;
    
    //if ans has already calculated then
    //simply returing that
    if(dp[i][j]!=-1)return dp[i][j];
    
    //initializing ans as max integer
    int ans=INT_MAX;
    
     for (int k = i; k < j; k++)
    {
        if(dp[i][k]==-1)MCM(arr,i,k);
        if(dp[k+1][j]==-1)MCM(arr,k+1,j);
        
        //calculating temporary ans for particular case
        int temp_ans = dp[i][k]+dp[k+1][j]+(arr[i-1]*arr[k]*arr[j]);
        
        //updating final answer
        ans=min(ans,temp_ans);
    }
    
    return dp[i][j]=ans;
    
}

//Main Function

int main()
{
    int arr[] = {4,6,9,3,5,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    memset(dp, -1, sizeof dp);
    //calling MCM function
    cout<<MCM(arr,1,n-1);
    return 0;
}

//output= 450