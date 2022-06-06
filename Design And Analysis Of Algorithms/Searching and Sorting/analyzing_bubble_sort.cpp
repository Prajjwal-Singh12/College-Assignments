#include <iostream> 
#include <stdlib.h>              // for using rand() function 
#include <sys/time.h>            // for using gettimeofday() function
using namespace std;
 
 
double getTimeinMicroSeconds()
{
   struct timeval start;
   gettimeofday(&start,NULL);
   return (start.tv_sec*1000000 + start.tv_usec); 
}

 
  // Bubble Sort { O(n²) }: each time travel from (0) to (n-i) & do swapping when wrong order
  
void swap(int *arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp; 
}
 
 
void bubbleSort(int *arr, int n)                                                                                                        
{ 
	for(int i=0; i<n; i++)
	{ 	
	    for(int j=1; j<n-i; j++)
		{ 	
		    if(arr[j-1] > arr[j])
			swap(arr, j-1, j); 	
		}  
	}   
}

 
 // Time taken = T(n) = c*n² = (Machine constant)*n²


int main() 
{ 
    int n=1000, arr[1000]; 
 
 
  
    double startTime1 = getTimeinMicroSeconds(); 
    for(int i=0; i<n; i++) 
    arr[i] = 1000-i;                     
    bubbleSort(arr, n);                                           // sorting opposite sorted array [Worst Case]
    double endTime1 = getTimeinMicroSeconds();
     
    double timeTaken1 = (endTime1 - startTime1);
    double machineConstant1 = timeTaken1/(n*n);
    cout<<"Time taken (t1) by Bubble Sort in worst case: "<< timeTaken1 <<" microseconds"<<endl;
    cout<<"Machine constant (c1) by Bubble Sort in worst case: "<< machineConstant1 <<endl;

  
  
    cout<<"\n";
 
 

    double startTime2 = getTimeinMicroSeconds(); 
    for(int i=0; i<n; i++) 
    arr[i] = rand()%1000;          
    bubbleSort(arr, n);                                         // sorting random array [Average Case]
    double endTime2 = getTimeinMicroSeconds();
    
    double timeTaken2 = (endTime2 - startTime2);
    double machineConstant2 = timeTaken2/(n*n);
    cout<<"Time taken (t2) by Bubble Sort in average case: "<< timeTaken2 <<" microseconds"<<endl;
    cout<<"Machine constant (c2) by Bubble Sort in average case: "<< machineConstant2 <<endl;        
}









