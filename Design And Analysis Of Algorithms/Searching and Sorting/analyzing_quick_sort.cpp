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
 
 // Quick Sort { O(nlogn) }: Sort left array (elements < pivot) & right array (elements >= pivot) by recursion 
 
void swap(int *arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}                      
  
int createPartition(int *arr, int si, int ei)
{
	int pivotI = si; 
 
	for(int i=si+1, j=ei;  i<=j;  )
	{   while(arr[i] <= arr[pivotI])
	    i++; 
	    while(arr[j] > arr[pivotI])     
	    j--;
	
	    if(i<=j)
    	swap(arr, i, j);
		else
		{  swap(arr, pivotI, j);    // swap with j bcz currently (arr[i]>=arr[pivotI]) && (arr[j]<arr[pivotI]) && (i>j)  
           pivotI = j;  }    }
	 
	return pivotI;
}
 

void  quickSort(int *arr, int si, int ei)
{
	if(si>=ei)
	return;
	 
	int pivotI = createPartition(arr, si, ei); 
	quickSort(arr, si, pivotI-1);
	quickSort(arr, pivotI+1, ei);
	  
	return;
}

 
 // Time taken = T(n) = c*nlogn = (Machine constant)*nlogn


int main() 
{ 
    int n=1000, arr[1000]; 
 
 
  
    double startTime1 = getTimeinMicroSeconds();  
    for(int i=0; i<100; i++) 
    { 
       for(int i=0; i<n; i++) 
       arr[i] = 1000-i;  
       quickSort(arr, 0, n-1);                                   // sorting opposite sorted array [Worst Case] [O(n²)]
    }        
    double endTime1 = getTimeinMicroSeconds();
     
    double timeTaken1 = (endTime1 - startTime1)/100;
    double machineConstant1 = timeTaken1/(n*n);
    cout<<"Time taken (t1) by Quick Sort in worst case: "<< timeTaken1 <<" microseconds"<<endl;
    cout<<"Machine constant (c1) by Quick Sort in worst case: "<< machineConstant1 <<endl;

  
  
    cout<<"\n";
 
 

    double startTime2 = getTimeinMicroSeconds();  
    for(int i=0; i<100; i++) 
    { 
        for(int i=0; i<n; i++) 
        arr[i] = rand()%1000;              
        quickSort(arr, 0, n-1);                                 // sorting random array [Average Case] [O(nlogn)] 
    }     
    double endTime2 = getTimeinMicroSeconds();
    
    double timeTaken2 = (endTime2 - startTime2)/100;
    double machineConstant2 = timeTaken2/(n*log2(n));
    cout<<"Time taken (t2) by Quick Sort in average case: "<< timeTaken2 <<" microseconds"<<endl;
    cout<<"Machine constant (c2) by Quick Sort in average case: "<< machineConstant2 <<endl;        
}










