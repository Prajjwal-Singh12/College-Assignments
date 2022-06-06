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

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i)
{
    // initialize largest as root and get left and right nodes
    int largest = i;
    int left_node = 2*i + 1;
    int right_node = 2*i + 2;
    // Check if left node exists and is larger than root. If yes, change it
    if(left_node < n && arr[left_node] > arr[largest])
        largest = left_node;
    // Check if right node exists and is larger than root. If yes, change it
    if(right_node < n && arr[right_node] > arr[largest])
        largest = right_node;
    // change root, if needed
    if(largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
} 

void heapsort(int arr[], int n)
{
    int i;
    // Build a max heap
    for(i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    // One by one extract elements
    for(i = n-1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

//Time taken = T(n) = k*nlogn (k = Machine constant) 

int main() 
{ 
    system("cls");
    int n=1000, arr[1000]; 
    
    for(int i=0; i<n; i++) 
    arr[i] = 1000-i;
   
    double start1 = time(); 
    for(int i=0; i<100; i++) 
    { 
       for(int i=0;  i<n;  i++) 
       arr[i] = 1000-i; 
       heapsort(arr, n);  
    }
    double end1 = time();
     
    double t1 = (end1 - start1)/100;
    double c1 = t1/(n*log2(n));
    cout<<"Time by Heap Sort in worst case: "<< t1 <<" microseconds"<<endl; // O(nlogn)
    cout<<"Machine constant by Heap Sort in worst case: "<< c1 <<endl;

    cout<<endl;

    double start2 = time();
    for(int i=0; i<100; i++)
    {
        for(int i=0; i<n; i++)
        arr[i] = rand()%1000;        
        heapsort(arr, n);
    }
    double end2 = time();

    double t2 = (end2 - start2)/100;
    double c2 = t2/(n*log2(n));
    cout<<"Time by Heap Sort in average case: "<< t2 <<" microseconds"<<endl; // O(nlogn)
    cout<<"Machine constant by Heap Sort in average case: "<< c2 <<endl;
}