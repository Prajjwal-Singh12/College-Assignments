//ADJACENCY MATRIX_BFS_DFS
#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;
        
int** storeInputGraph(int nV, int nE)
{
	int **arr = new int*[nV];                                                         
	for(int i=0; i<nV; i++)
	{  arr[i] = new int[nV];
	
	   for(int j=0; j<nV; j++)
	   arr[i][j] = 0;	}
	
	for(int i=0; i<nE; i++)                                                
	{  int v1, v2;
	   cin>>v1>>v2;
	   arr[v1][v2] = 1;
	   arr[v2][v1] = 1;	 }
	
	return arr;
}

void printConnectedSubgraphDFS(int **arr, int nV, int startV, bool *printedV)
{
	cout<<startV<<" ";
	printedV[startV] = true;
	
	for(int i=0; i<nV; i++)
	{
	   if(i==startV)                                         
	   continue;
	   else if(arr[startV][i]==1 && !printedV[i])
	   printConnectedSubgraphDFS(arr, nV, i, printedV); 
	} 
}

void printGraphDFS(int **arr, int nV)
{
	bool *printedV = new bool[nV];                       
	for(int i=0; i<nV; i++)
	printedV[i] = false;                                   
	
	for(int i=0; i<nV; i++)
	{
	   if(!printedV[i])
	   printConnectedSubgraphDFS(arr, nV, i, printedV); 
	}  
}

void printConnectedSubgraphBFS(int **arr, int nV, int startV, bool *printedV)
{
	queue<int> vList;                                           
	vList.push(startV);
	printedV[startV] = true;
	
	while(vList.size() != 0)
	{
	   int currV = vList.front();
	   vList.pop();
	   cout<<currV<<" ";
	
	   for(int i=0; i<nV; i++){   
			if(i==currV)                                  
	    		continue;
	       	else if(arr[currV][i]==1 && !printedV[i]){
	       		vList.push(i);
			  	printedV[i] = true;  
			}   
		}  
	} 
}

void printGraphBFS(int **arr, int nV)
{
	bool *printedV = new bool[nV];                            
	for(int i=0; i<nV; i++)
	printedV[i] = false;                                 
	
	for(int i=0; i<nV; i++)
	{
	   if(!printedV[i])
	   printConnectedSubgraphBFS(arr, nV, i, printedV); 
	}  
}

long time()
{
   struct timeval start;
   gettimeofday(&start,NULL);
   return (start.tv_sec*1000000 + start.tv_usec); 
}
 
 
int main()
{ 
	int nV, nE;                                        
	cin>>nV>>nE;
	int **arr = storeInputGraph(nV, nE);                                
	

    double startTime, endTime;  // Time taken = c*(nV + nE) = (Machine constant)*(nV + nE) 
	
	
	startTime = time(); 
	cout<<"\nGraph in DFS order: ";                       
	printGraphDFS(arr, nV);             
    endTime = time(); 
    cout<<"\nTime taken: "<< endTime - startTime <<" microseconds";
    cout<<"\nMachine constant: "<< (endTime - startTime)/(nV + nE) <<endl;

    
    startTime = time(); 
	cout<<"\nGraph in BFS order: ";                          
	printGraphBFS(arr, nV);             
    endTime = time(); 
    cout<<"\nTime taken: "<< endTime - startTime <<" microseconds";
    cout<<"\nMachine constant: "<< (endTime - startTime)/(nV + nE) <<endl; 
}

/*

8 7
0 1
1 3
1 6
3 7
2 4
2 5
4 5

      Input graph   
                  0
      2           |
     /\           1
    /  \          /\
   4----5        /  \
                6    3
                     |
                     7

*/