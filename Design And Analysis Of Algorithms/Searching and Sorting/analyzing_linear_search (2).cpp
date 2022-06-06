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

 
int linearSearch(int *arr, int n, int x)     // searching a element in an array { O(n) }
{
    for(int i=0; i<n; i++) 
	{
        if(arr[i] == x) 
        return i;
    }

    return -1;
}

 
 // Time taken = T(n) = c*n = (Machine constant)*n


int main() 
{ 
    int n=100000, arr[100000]; 
    for(int i=0; i<n; i++) 
    arr[i] = rand()%10000;
  
    
  
    double startTime1 = getTimeinMicroSeconds(); 
    for(int i=0; i<100; i++)                          // searching absent value [Worst Case] 
    linearSearch(arr, n, 10001);              
    double endTime1 = getTimeinMicroSeconds();
     
    double timeTaken1 = (endTime1 - startTime1)/100.000;
    double machineConstant1 = timeTaken1/n;
    cout<<"Time taken (t1) by Linear Search in worst case: "<< timeTaken1 <<" microseconds"<<endl;
    cout<<"Machine constant (c1) by Linear Search in worst case: "<< machineConstant1 <<endl;

 
 
    cout<<endl;
 
 

    double startTime2 = getTimeinMicroSeconds(); 
    for(int i=0; i<10000; i++)                         // searching random value [Average Case]
    linearSearch(arr, n, rand()%10001);
    double endTime2 = getTimeinMicroSeconds();
    
    double timeTaken2 = (endTime2 - startTime2)/10000.000;
    double machineConstant2 = timeTaken2/n;
    cout<<"Time taken (t2) by Linear Search in average case: "<< timeTaken2 <<" microseconds"<<endl;
    cout<<"Machine constant (c2) by Linear Search in average case: "<< machineConstant2 <<endl;
}















