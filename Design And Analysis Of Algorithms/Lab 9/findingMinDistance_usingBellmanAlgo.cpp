//BELLMAN FORD
#include <bits/stdc++.h>
using namespace std;                     
                                
class Edge                                                    
{     public:
	int startV;                                                 
	int endV;                                                     
	int weight;                                                               
};


void findingMinDistance_usingBellmanFordAlgo(int nV, int nE, Edge *arr)
{                                                              
	int *distance = new int[nV];                            
	for(int i=0; i<nV; i++)                             
	distance[i] = INT_MAX;                              
	 
	distance[0] = 0;   
	
	for(int i=0; i<nV-1; i++)                                  
	{
		for(int j=0; j<nE; j++)                             
		{
			int v1 = arr[j].startV;
			int v2 = arr[j].endV;
			int w = arr[j].weight;
			
			if((distance[v1]!=INT_MAX) && ((distance[v1] + w) < distance[v2]))
			distance[v2] = distance[v1] + w;                 
		}
	}

	int flag = 0;

	for(int j=0; j<nE; j++)                             
	{
		int v1 = arr[j].startV;
		int v2 = arr[j].endV;
		int w = arr[j].weight;
		
		if((distance[v1]!=INT_MAX) && ((distance[v1] + w) < distance[v2]))
		flag = 1;                
	}
	 
	if(flag==0)
	{
		for(int i=0; i<nV; i++)
		cout << "Vertex " << i << ": " << distance[i] << endl;
	}
	else
	{
		cout<<"ERROR: Negative weight cycle present";
	}
}

 
int main()
{ 
	system("cls");
	int nV, nE;
	cin>>nV>>nE;
	
	Edge *arr = new Edge[nE]; 
	for(int i=0; i<nE; i++)
	cin >> arr[i].startV >> arr[i].endV >> arr[i].weight;   
	 
	findingMinDistance_usingBellmanFordAlgo(nV, nE, arr);
}


/*

4 5
0 1 -3
0 2 4
1 3 2
1 2 1
2 3 0

(Source Vertex = 0)

          -3
       0------1
       |     /|
       |  1/  | 
      4|  /   |2
       |/     |
       2------3   
          0

*/