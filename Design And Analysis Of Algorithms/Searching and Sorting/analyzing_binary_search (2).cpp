#include <bits/stdc++.h>
#include <algorithm>             // for using sort() function 
#include <cmath>                 // for using log2() function 
#include <stdlib.h>              // for using rand() function
#include <sys/time.h>            // for using gettimeofday() function
using namespace std;
 
 
long getTimeinMicroSeconds()
{
   struct timeval start;
   gettimeofday(&start,NULL);
   return (start.tv_sec*1000000 + start.tv_usec); 
}


int binarySearch(int *arr, int n, int x)           // searching a element in a sorted array { O(logn) }                                                                                 
{
	int startI = 0;
	int endI = n-1;
	
	while(startI <= endI)
	{  
	   int midI = (startI+endI)/2;
	   
	   if(arr[midI] == x)
	   return midI;
	   else if(arr[midI] > x)
	   endI = midI-1;
	   else
	   startI = midI+1;	
	}
	
	return -1; 
}


 // Time taken = T(n) = c*logn = (Machine constant)*logn


int main() 
{ 
    int n=100000, arr[100000]; 
    for(int i=0; i<n; i++) 
    arr[i] = rand()%10000;
    sort(arr, arr+n);
 
 
  
    double startTime1 = getTimeinMicroSeconds(); 
    for(int i=0; i<100000; i++)                          // searching absent value [Worst Case] 
    binarySearch(arr, n, 100001);              
    double endTime1 = getTimeinMicroSeconds();
     
    double timeTaken1 = (endTime1 - startTime1)/100000.000;
    double machineConstant1 = timeTaken1/log2(n);
    cout<<"Time taken (t1) by Binary Search in worst case: "<< timeTaken1 <<" microseconds"<<endl;
    cout<<"Machine constant (c1) by Binary Search in worst case: "<< machineConstant1 <<endl;



    cout<<endl;
    
    

    double startTime2 = getTimeinMicroSeconds(); 
    for(int i=0; i<1000000; i++)                         // searching random value [Average Case]
    binarySearch(arr, n, rand()%10001);
    double endTime2 = getTimeinMicroSeconds();
    
    double timeTaken2 = (endTime2 - startTime2)/10000000.000;
    double machineConstant2 = timeTaken2/log2(n);
    cout<<"Time taken (t2) by Binary Search in average case: "<< timeTaken2 <<" microseconds"<<endl;
    cout<<"Machine constant (c2) by Binary Search in average case: "<< machineConstant2 <<endl;
}









