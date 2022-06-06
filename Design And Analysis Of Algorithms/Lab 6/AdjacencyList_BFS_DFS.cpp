//ADJACENCY LIST_BFS_DFS
#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std; 

class Graph                                                 
{ 
    int nV;                                                
    list<int> *adj;                                       
          
		public: 
    Graph(int nV);                                    
                                    
    void storeInputGraph(int nE);                          
    
    void printConnectedSubgraphDFS(int startV, bool *printedV); 
    void printGraphDFS();
     
    void printConnectedSubgraphBFS(int startV, bool *printedV); 
    void printGraphBFS();
}; 
 
 
Graph::Graph(int nV) 
{ 
    this->nV = nV; 
    adj = new list<int>[nV]; 
} 
  
void Graph::storeInputGraph(int nE)      
{ 
    for(int i=0; i<nE; i++)                            
    {  int v1, v2;
        cin>>v1>>v2;	
	   
       adj[v1].push_back(v2);  }                        
}
   
 
void Graph::printConnectedSubgraphDFS(int startV, bool printedV[])   
{  
	cout<<startV<<" ";
	printedV[startV] = true;
	 
    for(list<int>::iterator i=adj[startV].begin(); i!=adj[startV].end(); i++) 
    {
		if(!printedV[*i])                            
        printConnectedSubgraphDFS(*i, printedV); 
    } 
} 
  
void Graph::printGraphDFS()                               
{ 
	bool *printedV = new bool[nV];                       
	for(int i=0; i<nV; i++)
	printedV[i] = false;                                  
	
	for(int i=0; i<nV; i++)
	{
	   if(!printedV[i])
	   printConnectedSubgraphDFS(i, printedV); 
	}  
} 


void Graph::printConnectedSubgraphBFS(int startV, bool *printedV)
{
	queue<int> vList;                                             
	vList.push(startV);
	printedV[startV] = true;
	 
    while(vList.size() != 0)
    {
	   int currV = vList.front();
	   vList.pop();
	   cout<<currV<<" ";
		 
        for(list<int>::iterator i=adj[currV].begin(); i!=adj[currV].end(); i++)            
        {
            if(!printedV[*i])                               
            {
                printedV[*i] = true;
                vList.push(*i);
            }
        }
    } 
}

void Graph::printGraphBFS()
{
	bool *printedV = new bool[nV];                              
	for(int i=0; i<nV; i++)
	printedV[i] = false;                                     
	
	for(int i=0; i<nV; i++)
	{
	   if(!printedV[i])
	   printConnectedSubgraphBFS(i, printedV); 
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
    Graph g(nV);
    g.storeInputGraph(nE);
 
    double startTime, endTime; // Time taken = c*(nV + nE) = (Machine constant)*(nV + nE) 
	
	startTime = time(); 
	cout<<"\nGraph in DFS order: ";                            
	g.printGraphDFS();             
    endTime = time(); 
    cout<<"\nTime taken: "<< endTime - startTime <<" microseconds";
    cout<<"\nMachine constant: "<< (endTime - startTime)/(nV + nE) <<endl;
    
    startTime = time(); 
	cout<<"\nGraph in BFS order: ";                             
	g.printGraphBFS();             
    endTime = time(); 
    cout<<"\nTime taken: "<< endTime - startTime <<" microseconds";
    cout<<"\nMachine constant: "<< (endTime - startTime)/(nV + nE) <<endl; 
} 

/*

8 11
0 1
1 3
2 1
3 2
3 4
4 5
6 4
5 7
7 6
0 2
2 6  

             Input Graph

     0------>1----->3----->4----->5
      \     /\     /      /\      |
       \    |     /       |       |
         \  |   /         |       |  
         _\|| |/_         |       \/
		    2------------>6<------7
 
*/
