#include <iostream> 
#include <stdlib.h>   // for using rand() function 
#include <sys/time.h>  // for using gettimeofday() function
#include <cmath>  // for using log2() function 
#include <vector>
#include <queue>
using namespace std;

 
double getTimeinMicroSeconds()
{
   struct timeval start;
   gettimeofday(&start,NULL);
   return (start.tv_sec*1000000 + start.tv_usec); 
}

 
class PriorityQueue // class for creating a Min Priority Queue 
{   
	vector<int> pq; // storing Min Priority Queue in an vector Array 
	
	   public:
    PriorityQueue()
	{     }	
	
	bool isEmpty()
	{  return (pq.size()==0);  }
	
	int getSize()
	{  return pq.size();  }	
	
	int getMin()
	{  if(isEmpty())
	   return 0;
	   
	   return pq[0];  }
	
	void insert(int x)
	{
		pq.push_back(x);
		int cI = pq.size()-1;
		
		while(cI > 0) // Up Heapify Process 
		{  int pI = (cI-1)/2;
		
		   if(pq[cI] < pq[pI])
		   {  int temp = pq[cI];
		      pq[cI] = pq[pI];
			  pq[pI] = temp;
			  
			  cI = pI;  }
		   else
		   break;	}
	}
	
	int removeMin()
	{
		if(isEmpty())
		return 0;
		
		int r = pq[0];
		pq[0] = pq[pq.size()-1];
		pq.pop_back();
		
		int pI=0, l_cI=2*pI+1, r_cI=2*pI+2;
		
		while(l_cI < pq.size()) // Down Heapify Process                
		{   int mI = pI;
		
		    if(l_cI < pq.size() && pq[l_cI] < pq[mI])
        	mI = l_cI;
		    if(r_cI < pq.size() && pq[r_cI] < pq[mI])
        	mI = r_cI;
		    if(mI==pI)
        	break;
			
		    int temp = pq[mI];
		    pq[mI] = pq[pI];
			pq[pI] = temp;
			  
			pI = mI;
			l_cI = 2*pI+1;
			r_cI = 2*pI+2;   }
		
		return r; 
	} 
};
 

int main()
{  
	PriorityQueue p;
    p.insert(12);
    p.insert(6);
    p.insert(5);
    p.insert(100);
    p.insert(1);
    p.insert(9);
    p.insert(0);
    p.insert(14); 
    cout << "\nSize of min priority queue: " << p.getSize() << endl;
	cout << "Min element: " << p.getMin() << endl;
    cout << "Elements of min priority queue (in sorted order): ";
    while(!p.isEmpty())
    cout << p.removeMin() << " ";
    
    
    cout << "\n\n\n\n"; 
    
     
    PriorityQueue pq;
    double start, end, time_taken, machine_constant;

 
    cout<<"Time complexity for insertion of an element in Priority Queue = O(logn)" << endl; 
    start = getTimeinMicroSeconds();
    for(int i=0; i<100000; i++)
    pq.insert(rand()%100000);
    end = getTimeinMicroSeconds(); 
    time_taken = (end - start) / 100000; 
    cout << "Average time taken for inserting an element: " << time_taken << " milliseconds" << endl; 
    cout << "Machine constant for insertion an element: " << time_taken/log2(10000) << endl;
 
   
    cout<<"\nTime complexity for finding min element in Priority Queue = O(1)" << endl; 
    start = getTimeinMicroSeconds();
    for(int i=0; i<100000; i++)
    pq.getMin();
    end = getTimeinMicroSeconds(); 
    time_taken = (end - start) / 100000; 
    cout << "Average time taken for finding min element: " << time_taken << " milliseconds" << endl; 
    cout << "Machine constant for finding min element: " << time_taken << endl;
  
 
    cout<<"\nTime complexity for deletion of min element in Priority Queue = O(logn)" << endl; 
    start = getTimeinMicroSeconds();
    for(int i=0; i<100000; i++)
    pq.removeMin();
    end = getTimeinMicroSeconds(); 
    time_taken = (end - start) / 100000; 
    cout << "Average time taken for deletion of min element: " << time_taken << " milliseconds" << endl; 
    cout << "Machine constant for deletion of min element: " << time_taken/log2(10000) << endl; 
	
	
    cout << "\n\n\n\n";  
}

          
		                                                                                          
 /*
  
  8 12 6 5 100 1 9 0 14    
  
            0            
           / \ 
          /   \ 
         5     1          
        /\     /\
       /  \   /  \
     100  12 9    6       
     /		
	 /
   14

   (Min Heap) = (Complete Binary Tree + Heap Order Property), (last level is filled left to right)
   	
  pq[] = {0,5,1,14,12,9,6,100} 	       
  
  (Min Priority Queue) = (Lowest Priority First Out), (O(logn)), (Root=Min element), (stored in array)                                   
 
 */

 // Min Heap = (parent data < child data)
 
 // (pq=PriorityQueue), (l_cI=leftChildIndex), (r_cI=rightChildIndex), (cI=childIndex), (pI=parentIndex), (mI=minValueChildIndex)   