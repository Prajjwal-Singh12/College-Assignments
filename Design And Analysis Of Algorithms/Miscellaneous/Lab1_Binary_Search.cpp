#include <iostream>
#include <algorithm> // for using sort() function 
#include <stdlib.h> // for using rand() function
#include <cmath> // for using log2() function 
#include <sys/time.h> // for using gettimeofday() function
using namespace std;

long getTimeIn_microsec()
{
    struct timeval start;
    gettimeofday(&start,NULL);
    return (start.tv_sec*1000000 + start.tv_usec); 
}

int binarySearch(int *arr, int n, int x) 
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

int main() 
{ 
    system("cls");
    int n=100000, arr[100000]; 
    for(int i=0; i<n; i++)
    arr[i] = rand()%10000;
    sort(arr, arr+n);
    
    double start1 = getTimeIn_microsec(); 
    for(int i=0; i<1000000; i++) // searching value not present in the array[Worst Case] 
    binarySearch(arr, n, 10001); 
    double end1 = getTimeIn_microsec();
    
    double timeTaken1 = (end1 - start1)/100000.0;
    double machineConstant1 = timeTaken1/log2(n);
    cout<<"Time taken by Binary Search in worst case: "<< timeTaken1 <<" microseconds"<< endl;
    cout<<"Machine constant by Binary Search in worst case: "<< machineConstant1 << endl << endl;
    
    
    double start2 = getTimeIn_microsec(); 
    for(int i=0; i<1000000; i++) // searching random value [Average Case]
    binarySearch(arr, n, rand()%10000);
    double end2 = getTimeIn_microsec();
    
    double timeTaken2 = (end2 - start2)/1000000.0;
    double machineConstant2 = timeTaken2/log2(n);
    cout<<"Time taken by Binary Search in average case: "<< timeTaken2 <<" microseconds"<< endl;
    cout<<"Machine constant by Binary Search in average case: "<< machineConstant2 << endl;
}
// Time taken = T(n) = c*logn = (Machine constant)*logn