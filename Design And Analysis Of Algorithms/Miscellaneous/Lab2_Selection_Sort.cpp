#include <iostream>
#include <stdlib.h>
#include <sys/time.h>
using namespace std;

double time() // in microseconds
{
    struct timeval start;
    gettimeofday(&start,NULL);
    return (start.tv_sec*1000000 + start.tv_usec); 
}

void selectionSort(int *A, int n) 
{
    int min; 
    for(int i = 0; i < n-1 ; i++)
    {
        min = i ;
        for(int j = i+1; j < n ; j++)
        {
            if(A[j] < A[min])
            min = j ;
        }
        swap (A[min], A[i]); 
    }
}

// Time taken = T(n) = k*n^2 (k = Machine constant) 

int main()
{ 
    system("cls");
    int n=5000, arr[5000]; 
    double start1 = time(); 
    for(int i=0; i<n; i++) 
    arr[i] = 5000-i; 
    selectionSort(arr, n); 
    double end1 = time();
    
    double diff1 = (end1 - start1);
    double c1 = diff1/(n*n);
    cout<<"Time by Selection Sort in worst case: "<< diff1 <<" microseconds"<<endl;
    cout<<"Machine constant by Selection Sort in worst case: "<< c1 <<endl;
    
    cout<<endl;
    
    double start2 = time(); 
    for(int i=0; i<n; i++)
    arr[i] = rand()%5000; 
    selectionSort(arr, n); 
    double end2 = time();
    
    double diff2 = (end2 - start2);
    double c2 = diff2/(n*n);
    cout<<"Time by Selection Sort in average case: "<< diff2 <<" microseconds"<<endl;
    cout<<"Machine constant by Selection Sort in average case: "<< c2 <<endl; 
}