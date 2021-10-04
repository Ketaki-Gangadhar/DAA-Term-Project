//C++ code for Matrix Chain Multiplication
//problem by bottom-up approach

#include <bits/stdc++.h>
using namespace std;

//MCM function to calculate minimum number of
//operations required to multiply all matrices

int MCM (int arr[], int n)
{
      int dp[500][500];

   for(int gap=0; gap<n-1; gap++)
    {
        for(int x=1; x<n-gap; x++)
        {
            int y = x+gap;

            if(x==y)
                dp[x][y]=0;
            else{
                //making all possible partitions
                int operations=INT_MAX;
                for (int k=x; k<y; k++)
                {
                    //operations for current partitions
                    int temp_operations = dp[x][k]+dp[k+1][y]+arr[x-1]*arr[k]*arr[y];
                    operations = min(operations,temp_operations);
                }
                dp[x][y]=operations;

            }
        }
    }

    return dp[1][n-1];
}

//Main Function

int main()
{
    int arr[] = {4,6,9,3,5,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    //calling MCM function
    cout<<MCM(arr,n);
    return 0;
}

//output= 450