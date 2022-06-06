#include <iostream>
#include <stdlib.h> // for rand() function 
#include <sys/time.h> // for gettimeofday() function
using namespace std;

double getTimeIn_microsec()
{
    struct timeval start;
    gettimeofday(&start,NULL);
    return (start.tv_sec*1000000 + start.tv_usec); 
}

int linearSearch(int *arr, int n, int x)
{
    for(int i=0; i<n; i++) 
    {
        if(arr[i] == x) 
        return i;
    }
        return -1;
}

int main() 
{ 
    system("cls");
    int n=100000, arr[100000]; 
    for(int i=0; i<n; i++) 
    arr[i] = rand()%10000;
    
    double start1 = getTimeIn_microsec(); 
    for(int i=0; i<10000; i++) // searching value not present in the array[Worst Case] 
    linearSearch(arr, n, 10001); 
    double end1 = getTimeIn_microsec();
    
    double timeTaken1 = (end1 - start1)/10000.0;
    double machineConstant1 = timeTaken1/n;
    cout<<"Time taken by Linear Search in worst case: "<< timeTaken1 <<" microseconds"<<endl;
    cout<<"Machine constant by Linear Search in worst case: "<< machineConstant1 <<endl<<endl;
    
    double start2 = getTimeIn_microsec(); 
    for(int i=0; i<10000; i++) // searching random value [Average Case]
    linearSearch(arr, n, rand()%10000);
    double end2 = getTimeIn_microsec();
    
    double timeTaken2 = (end2 - start2)/10000.0;
    double machineConstant2 = timeTaken2/n;
    cout<<"Time taken by Linear Search in average case: "<< timeTaken2 <<" microseconds"<<endl;
    cout<<"Machine constant by Linear Search in average case: "<< machineConstant2 <<endl;
}
// Time taken = T(n) = c*n = (Machine constant)*n