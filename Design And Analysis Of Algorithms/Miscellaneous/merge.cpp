#include <iostream> 
#include <stdlib.h>       
#include <cmath>       
#include <algorithm>                 
#include <sys/time.h>           
using namespace std;
 
double time() // microsecond time
{
   struct timeval start;
   gettimeofday(&start,NULL);
   return (start.tv_sec*1000000 + start.tv_usec); 
}
   
void merge(int *input, int left, int middle, int right)
{
    int n =middle-left+1; // size of first array
    int m =right -middle; // size of rest of the elements
    int first[n];
    for(int i=0;i<n;i++)
    {
        first[i]=input[left+i];
        //cout<<first[i]<<" ";
    }
    // cout<<endl;
   int rest[m];
     for(int i=0;i<m;i++)
    {
        rest[i]=input[middle+1+i];
        //cout<<rest[i]<<" ";
    }
    // cout<<endl;
    int ptr1=0;
    int ptr2=0;
    int index=left;
    // MERGE PROCESS WITH COMPARISONS 
    while(ptr1<n && ptr2<m)
    {
        if(first[ptr1] < rest[ptr2])
        {
            input[index]=first[ptr1];
            index++;
            ptr1++;
        }
        else 
        {
             input[index]=rest[ptr2];
            index++;
            ptr2++;
        }
    }
    while(ptr1 < n)
    {
        input[index]=first[ptr1];
            index++;
            ptr1++;
    }
    while(ptr2 < m)
    {
        input[index]=rest[ptr2];
            index++;
            ptr2++;
    }
}

void merge_sort(int *input, int left, int right)
{
   if(left < right)
   {
      // LETS DIVIDE
      int middle =(left+right)/2;
      merge_sort(input,left,middle);
      merge_sort(input,middle+1,right);
      // after dividing lets merge it
      merge(input,left,middle,right);        
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
       for(int i=0,j=0;  i<n/2;  i++,j+=2) 
       arr[i] = j; 
       for(int i=n/2,j=1;  i<n;  i++,j+=2) 
       arr[i] = j; 
       
       reverse(arr, arr+n);
       
       merge_sort(arr, 0, n-1);  
    }                          
    double end1 = time();
     
    double t1 = (end1 - start1)/100;
    double c1 = t1/(n*log2(n));
    cout<<"Time by Merge Sort in worst case: "<< t1 <<" microseconds"<<endl; // O(nlogn)
    cout<<"Machine constant by Merge Sort in worst case: "<< c1 <<endl;
 
    cout<<endl;

    double start2 = time(); 
    for(int i=0; i<100; i++) 
    { 
        for(int i=0; i<n; i++) 
        arr[i] = rand()%1000;              
        merge_sort(arr, 0, n-1);  
    }
    double end2 = time();
    
    double t2 = (end2 - start2)/100;
    double c2 = t2/(n*log2(n));
    cout<<"Time by Merge Sort in average case: "<< t2 <<" microseconds"<<endl; // O(nlogn)
    cout<<"Machine constant by Merge Sort in average case: "<< c2 <<endl;
}