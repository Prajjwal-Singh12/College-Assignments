//TRAVELLING SALESMAN PROBLEM
#include <bits/stdc++.h>
using namespace std;

 
/*

Some cities & distancesBetweenEachPairOfCities are given, weAreFinding shortestRouteThatVisitsEachCityExactlyOnce & returnsToTheStartingPoint
Approximate Algorithm for Travlling Salesman Problem is a NP Hard problem (finding minimum weight Hamiltonian Cycle)
Time Complexity = O(n^2)

*/
                                                                                                                                               
                                                                                                     
int** storeInputGraph(int nV, int nE)
{
	int **arr = new int*[nV];                                   // creating adjacency matrix      
	for(int i=0; i<nV; i++)
	{  arr[i] = new int[nV];
	
	   for(int j=0; j<nV; j++)
	   arr[i][j] = 0;	}
	
	for(int i=0; i<nE; i++)                                     // storing graph         
	{  int v1, v2, w;  
	   cin>>v1>>v2>>w;
	   arr[v1][v2] = w;
	   arr[v2][v1] = w;	 }
	
	return arr;
}

 
int travllingSalesmanProblem_usingApproximationAlgo(int **arr, int sourceV, int nV)
{ 
    vector<int> vtr;                                            // store all vertex apart from source vertex
    for(int i=0; i<nV; i++)
    {
		if(i != sourceV)
        vtr.push_back(i);
    } 
    
    int minPathWeight = INT_MAX;                                // finding min weight Hamiltonian Cycle.
    do 
	{
	    int currPathWeight = 0;                                 // storing current Path weight/cost
   
   
        int k = sourceV;
        for(int i=0; i<vtr.size(); i++)                         // compute current path weight
		{
            currPathWeight += arr[k][vtr[i]];
            k = vtr[i];
        } 
        currPathWeight += arr[sourceV][k]; 
        
        
        minPathWeight = min(minPathWeight,currPathWeight);      // update minimum 
    }
	while(next_permutation(vtr.begin(),vtr.end()));   // rearrangingElementsIn [vtr.begin(),vtr.end()) intoNextLexicographicallyHigherPermutation
 
  
    cout<<"\nMinimum path weight when (SourceVertex="<<sourceV<<"): "; 
    cout<<minPathWeight<<endl;
}
  

int main()
{ 
    system("cls");
	int nV, nE;
	cout<<"Enter no of vertices & edges: ";
	cin>>nV>>nE;
	int **arr = storeInputGraph(nV, nE);              // storing graph in Adjacency Matrix    

    travllingSalesmanProblem_usingApproximationAlgo(arr, 0, nV);
	
	for(int i=0; i<nV; i++)                           // deleting the memory after use
	delete [] arr[i];
	delete [] arr;                                
}

  
/*
                                                                                                
6 11
0 1 1
0 2 2
0 3 12
1 2 3
1 3 6
2 3 7
2 4 5
2 5 8
3 4 10
3 5 9  
4 5 4
    
    
 Input Weighted Graph

          1 
    0-----------1
    |\        / |
	|  \12  /   |  
   2|    \/     |6
    |    /\     |
    |  /3   \   |
    |/        \ |              
    2-----7-----3
    |\        / |
	|  \8   /   |  
   5|    \/     |9
    |    /\     |
    |  /10  \   | 
    |/        \ |
    4-----------5
          4
        
*/
