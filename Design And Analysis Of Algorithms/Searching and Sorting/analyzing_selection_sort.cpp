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

 
void swap(int *arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp; 
}

 // Selection Sort { O(n²) }: find index min element from unsorted array & put at front
   
void selectionSort(int *arr, int n)                                                                                              
{  
	for(int i=0; i<n; i++)
	{ 
		int minI = i;
		for(int j=i+1; j<n; j++)
		{
		   if(arr[j] < arr[minI])
		   minI = j;
		}
		 
		swap(arr, i, minI);
	} 
}

 
 // Time taken = T(n) = c*n² = (Machine constant)*n²


int main() 
{ 
    int n=1000, arr[1000];  
  
     
     
    double startTime1 = getTimeinMicroSeconds(); 
    for(int i=0; i<n; i++) 
    arr[i] = 1000-i;    
    selectionSort(arr, n);                              // sorting opposite sorted array [Worst Case]
    double endTime1 = getTimeinMicroSeconds();
     
    double timeTaken1 = (endTime1 - startTime1);
    double machineConstant1 = timeTaken1/(n*n);
    cout<<"Time taken (t1) by Selection Sort in worst case: "<< timeTaken1 <<" microseconds"<<endl;
    cout<<"Machine constant (c1) by Selection Sort in worst case: "<< machineConstant1 <<endl;

 
 
    cout<<"\n";
 
  
 
    double startTime2 = getTimeinMicroSeconds(); 
    for(int i=0; i<n; i++) 
    arr[i] = rand()%1000;              
    selectionSort(arr, n);                                   // sorting random array [Average Case]
    double endTime2 = getTimeinMicroSeconds();
    
    double timeTaken2 = (endTime2 - startTime2);
    double machineConstant2 = timeTaken2/(n*n);
    cout<<"Time taken (t2) by Selection Sort in average case: "<< timeTaken2 <<" microseconds"<<endl;
    cout<<"Machine constant (c2) by Selection Sort in average case: "<< machineConstant2 <<endl;
}






