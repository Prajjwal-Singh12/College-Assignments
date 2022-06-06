#include <iostream> 
#include <stdlib.h>              // for using rand() function 
#include <sys/time.h>            // for using gettimeofday() function
#include <cmath>                 // for using log2() function           
using namespace std;
 
 
double getTimeinMicroSeconds()
{
   struct timeval start;
   gettimeofday(&start,NULL);
   return (start.tv_sec*1000000 + start.tv_usec); 
}

 // Heap Sort {Time Complexity: O(nlogn), Space Complexity: O(1)}

void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
	arr[j] = temp;
}

void heapSort(int *pq, int n)                               
{                                                             
	for(int i=0; i<n; i++)                       // build maxHeap array in input array         
	{	                                         // inserting elements in maxHeapArray (left) from InputArray (right)
	    int cI = i;
	
	    while(cI > 0)                            // Up Heapify Process (travelling child node to root)
		{  int pI = (cI-1)/2;
		
		   if(pq[cI] > pq[pI])
		   {  swap(pq, cI, pI); 
			  cI = pI;  }
		   else
		   break;  }
    }
   	                                                                                                             
	while(n > 1)	                             // build sorted array in heap array 
	{                                                              
		swap(pq, 0, n-1);                        // inserting elements in SortedArray (right) from HeapArray (left) 
		n--;
		
		int pI=0, l_cI=2*pI+1, r_cI=2*pI+2; 
		
		while(l_cI < n)                          // Down Heapify Process (travelling root to child node)                
		{   int mI = pI;
		
		    if(l_cI < n && pq[l_cI] > pq[mI])
        	mI = l_cI;
		    if(r_cI < n && pq[r_cI] > pq[mI])
        	mI = r_cI;
        	
		    if(mI==pI)
        	break;
			else
		    swap(pq, mI, pI);
			                                                                   
			pI = mI;
			l_cI = 2*pI+1;
			r_cI = 2*pI+2;   }
    }  
}

 
 // Time taken = T(n) = c*nlogn = (Machine constant)*nlogn


int main() 
{ 
    int n=1000, arr[1000]; 
 
 
  
    double startTime1 = getTimeinMicroSeconds();  
    for(int i=0; i<100; i++) 
    { 
       for(int i=0;  i<n;  i++) 
       arr[i] = 1000-i; 
       heapSort(arr, n);                                   // sorting opposite sorted array [Worst Case]
    }        
    double endTime1 = getTimeinMicroSeconds();
     
    double timeTaken1 = (endTime1 - startTime1)/100;
    double machineConstant1 = timeTaken1/(n*log2(n));
    cout<<"Time taken (t1) by Heap Sort in worst case: "<< timeTaken1 <<" microseconds"<<endl;
    cout<<"Machine constant (c1) by Heap Sort in worst case: "<< machineConstant1 <<endl;

  
  
    cout<<"\n";
 
 

    double startTime2 = getTimeinMicroSeconds();  
    for(int i=0; i<100; i++) 
    { 
        for(int i=0; i<n; i++) 
        arr[i] = rand()%1000;              
        heapSort(arr, n);                                 // sorting random array [Average Case]  
    }     
    double endTime2 = getTimeinMicroSeconds();
    
    double timeTaken2 = (endTime2 - startTime2)/100;
    double machineConstant2 = timeTaken2/(n*log2(n));
    cout<<"Time taken (t2) by Heap Sort in average case: "<< timeTaken2 <<" microseconds"<<endl;
    cout<<"Machine constant (c2) by Heap Sort in average case: "<< machineConstant2 <<endl;        
}












