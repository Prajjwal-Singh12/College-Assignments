#include <iostream>
#include <stdlib.h>
#include <cmath>             
#include <sys/time.h>    
using namespace std;
 
double time() // microsecond time
{
   struct timeval start;
   gettimeofday(&start,NULL);
   return (start.tv_sec*1000000 + start.tv_usec);
}
 
template<class T> void swap(T *a, T *b)
{
    T t = *a;
    *a = *b;
    *b = t;
}

int partition(int a[], int start, int end)
{
    int pivot = a[end];
    int i = (start-1);
    for(int j=start; j<=end-1; j++)
    {
        if(a[j]<=pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(a[i+1], a[end]);
    return (i+1);
}

void quick_sort(int a[], int start, int end)
{
    if(start<end)
    {
        int pivot_index = partition(a, start, end);
        quick_sort(a, start, pivot_index-1);
        quick_sort(a, pivot_index+1, end);
    }
}
 
// Time taken = T(n) = k*nlogn (k = Machine constant) 
 
int main() 
{ 
    system("cls");
    int n=1000, arr[1000]; 
    
    for(int i=0; i<n; i++) 
    arr[i] = 1000-i;
   
    double start1 = time(); 
    for(int i=0; i<100; i++) 
    { 
       for(int i=0; i<n; i++) 
       arr[i] = 1000-i; 
       quick_sort(arr, 0, n-1);  
    }                          
    double end1 = time();
     
    double t1 = (end1 - start1)/100;
    double c1 = t1/(n*n);
    cout<<"Time by Quick Sort in worst case: "<< t1 <<" microseconds"<<endl; // O(n^2)
    cout<<"Machine constant by Quick Sort in worst case: "<< c1 <<endl;

    cout<<endl;

    double start2 = time();     
    for(int i=0; i<100; i++) 
    { 
        for(int i=0; i<n; i++) 
        arr[i] = rand()%1000;              
        quick_sort(arr, 0, n-1);  
    }
    double end2 = time();
    
    double t2 = (end2 - start2)/100;
    double c2 = t2/(n*log2(n));
    cout<<"Time by Quick Sort in average case: "<< t2 <<" microseconds"<<endl; // O(nlogn)
    cout<<"Machine constant by Quick Sort in average case: "<< c2 <<endl;
}