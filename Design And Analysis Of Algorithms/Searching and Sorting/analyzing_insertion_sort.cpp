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

 // Insertion Sort { O(n²) }: consider ([current array] = [sorted array][unsorted array]) & insert elements from right to left
 
void insertionSort(int *arr, int n)                                                                                         
{ 
	for(int i=0; i<n; i++)
	{ 
		for(int j=i; j>=0; j--)
		{
			if(arr[j-1] > arr[j])
			swap(arr, j-1, j);
			else
			break; 
		} 
	} 
}
 
    // Time taken = T(n) = c*n² = (Machine constant)*n²
 
int main() 
{ 
    int n=1000, arr[1000]; 
    
    for(int i=0; i<n; i++) 
    arr[i] = 1000-i;
   
    double startTime1 = getTimeinMicroSeconds(); 
    for(int i=0; i<n; i++) 
    arr[i] = 1000-i; 
    insertionSort(arr, n);                                          // sorting opposite sorted array [Worst Case] 
    double endTime1 = getTimeinMicroSeconds();
     
    double timeTaken1 = (endTime1 - startTime1);
    double machineConstant1 = timeTaken1/(n*n);
    cout<<"Time taken (t1) by Linear Search in worst case: "<< timeTaken1 <<" microseconds"<<endl;
    cout<<"Machine constant (c1) by Linear Search in worst case: "<< machineConstant1 <<endl;

 
 
    cout<<"\n";
 
   
   
    double startTime2 = getTimeinMicroSeconds();  
    for(int i=0; i<n; i++) 
    arr[i] = rand()%1000;              
    insertionSort(arr, n);                                        // sorting random array [Average Case] 
    double endTime2 = getTimeinMicroSeconds();
    
    double timeTaken2 = (endTime2 - startTime2);
    double machineConstant2 = timeTaken2/(n*n);
    cout<<"Time taken (t2) by Insertion Sort in average case: "<< timeTaken2 <<" microseconds"<<endl;
    cout<<"Machine constant (c2) by Insertion Sort in average case: "<< machineConstant2 <<endl;
}















