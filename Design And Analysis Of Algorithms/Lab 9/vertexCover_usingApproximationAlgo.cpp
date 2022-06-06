//VERTEX COVER USING APPROXIMATION ALGO
#include <bits/stdc++.h>
using namespace std;


/*

Vertex Cover: subset of vertices such that for every edge arr[i][j] of the graph, both 'i' or 'j' should be in Vertex Cover
Approximate Algorithm for Vertex Cover is a NP Complete problem
Time Complexity = O(n^2)

*/
                                                                                                                                               
                                                                                                     
int** storeInputGraph(int nV, int nE)
{
	int **arr = new int*[nV];                     // creating adjacency matrix      
	for(int i=0; i<nV; i++)
	{  arr[i] = new int[nV];
	
	   for(int j=0; j<nV; j++)
	   arr[i][j] = 0;	}
	
	for(int i=0; i<nE; i++)                       // storing graph         
	{  int v1, v2;  
	   cin>>v1>>v2;
	   arr[v1][v2] = 1;
	   arr[v2][v1] = 1;	 }
	
	return arr;
}


void vertexCover_usingApproximationAlgo(int **arr, int nV)
{ 
    bool visitedV[nV];                        // storing that vertex [i] is already visited or not 
    for(int i=0; i<nV; i++)
    visitedV[i] = false;
 
  
    for(int i=0; i<nV; i++)
    {                                         // an edge arr[i][j] is only picked when both i & j are unvisited
        if(visitedV[i]==false)
        {                                     // (picking an edge from remaining edges) / (consider first unvisited neighbour vertex'j' of vertex'i') 
            for(int j=0; j<nV; j++)
            { 
                if(arr[i][j]>0 && visitedV[j]==false)
                {                             // making the vertex i and j visited, so that all edges from/to them would be ignored
                    visitedV[i] = true;
                    visitedV[j]  = true;
                    break;
                }
            }
        }
    }
 
 
    cout<<"\nVertex Cover of input graph: ";
    for(int i=0; i<nV; i++)
    {   if(visitedV[i])
        cout<<i<<" ";    }
    cout<<endl;
}
 

int main()
{ 
    system("cls");
	int nV, nE;
	cout<<"Enter no of vertices & edges: ";
	cin>>nV>>nE;
	int **arr = storeInputGraph(nV, nE);          // storing graph in Adjacency Matrix    

    vertexCover_usingApproximationAlgo(arr, nV);
	
	for(int i=0; i<nV; i++)                       // deleting the memory after use
	delete [] arr[i];
	delete [] arr;                                
}

 
/*

9 9

0 1
0 2
0 3
2 5
3 5
3 4
4 5
5 6
6 7 
 

9 9

0 1
0 2
0 8
1 5
2 4
2 5
5 4
5 6
6 7

 
 [  Input Graph  ]

    0      3       
   /|\
  / | \
 1  2  8
 | / \
 |/   \
 5-----4
 | 
 6
 | 
 7
 
*/