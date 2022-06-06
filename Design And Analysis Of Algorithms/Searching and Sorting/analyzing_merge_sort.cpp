#include <iostream> 
#include <stdlib.h>              // for using rand() function 
#include <sys/time.h>            // for using gettimeofday() function
#include <cmath>                 // for using log2() function
#include <algorithm>             // for using sort() function             
using namespace std;
 
 
double getTimeinMicroSeconds()
{
   struct timeval start;
   gettimeofday(&start,NULL);
   return (start.tv_sec*1000000 + start.tv_usec); 
}
 
 // Merge Sort { O(nlogn) }: Sort left half array & right half array by recursion, then merge sorted arrays                
 
void mergeSortedArrays(int *arr, int si, int mid, int ei)
{
	int n = ei-si+1;
	int *a = new int[n];
	
	for(int i=si,j=mid+1,k=0; k<n; k++)
	{ 
		if( (i<=mid && j<=ei && arr[i]<arr[j]) ||  (i<=mid && j>ei) )
	    a[k] = arr[i++];  
		else  
	    a[k] = arr[j++];   
	}
	 
	for(int i=si,j=0; i<=ei; i++,j++)
	arr[i] = a[j]; 
	
	delete []a;
}
 

void  mergeSort(int *arr, int si, int ei)
{
	if(si>=ei)
	return;
	
	 
	int mid = (si+ei)/2;
	
	mergeSort(arr, si, mid);
	mergeSort(arr, mid+1, ei);
	
	mergeSortedArrays(arr, si, mid, ei);
	
	
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
       mergeSort(arr, 0, n-1);                                   // sorting opposite sorted array [Worst Case]
    }        
    double endTime1 = getTimeinMicroSeconds();
     
    double timeTaken1 = (endTime1 - startTime1)/100;
    double machineConstant1 = timeTaken1/(n*log2(n));
    cout<<"Time taken (t1) by Merge Sort in worst case: "<< timeTaken1 <<" microseconds"<<endl;
    cout<<"Machine constant (c1) by Merge Sort in worst case: "<< machineConstant1 <<endl;

  
  
    cout<<"\n";
 
 

    double startTime2 = getTimeinMicroSeconds();  
    for(int i=0; i<100; i++) 
    { 
        for(int i=0; i<n; i++) 
        arr[i] = rand()%1000;              
        mergeSort(arr, 0, n-1);                                 // sorting random array [Average Case]
    }     
    double endTime2 = getTimeinMicroSeconds();
    
    double timeTaken2 = (endTime2 - startTime2)/100;
    double machineConstant2 = timeTaken2/(n*log2(n));
    cout<<"Time taken (t2) by Merge Sort in average case: "<< timeTaken2 <<" microseconds"<<endl;
    cout<<"Machine constant (c2) by Merge Sort in average case: "<< machineConstant2 <<endl;        
}












