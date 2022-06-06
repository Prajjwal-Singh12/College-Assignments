#include <bits/stdc++.h>
using namespace std;

// [Knapsack Problem]                                  
// finding max value that bag (can bear max W weight) can contain, by storing some items of n given items (each item has (value,weight)) 
// arr[i][j] = maxValue can be stored in bag when (i = no of items) & (j = maxWeight that bag can bear)
                                                                 
                                                                                                   
int main()
{
	int n=5, wMax=16, W[5]={10,3,2,5,20}, V[5]={5,7,1,0,8};
	cout<<"Max value that bag can contain, by storing some items of n given items, is:"<<endl;
                          
                    
    int **dp = new int*[n+1];                                                             // Dynamic Programming { O(m*n) }
	for(int i=0; i<n+1; i++)
	dp[i] = new int[wMax+1]; 
	 
	dp[0][0] = 0;
	for(int i=1; i<n+1; i++)
	dp[i][0] = 0; 
	for(int j=1; j<wMax+1; j++)
	dp[0][j] = 0; 
	for(int i=1; i<n+1; i++)                                                                // i=current_n, j=current_wMax
	{   for(int j=1; j<wMax+1; j++)             
        {	
         	int vMax1=INT_MIN, vMax2=INT_MIN;
	
        	if(j-W[i-1] >= 0)                                                                // including weight at index (i-1) 
         	vMax1 = V[i-1] + dp[i-1][j-W[i-1]];                              
 
            vMax2 = dp[i-1][j];                                                           // excluding weight at index (i-1)            
	                       
	        dp[i][j] = max(vMax1, vMax2);       
		}
    }
    cout<<dp[n][wMax]<<endl; 
}