#include<iostream>
#include<chrono>
#include<iomanip>
using namespace std;


template <class T>

struct node 
{
    T data;
    int priority;
};


template <class T>
class PriorityQueue                           // implementing PriorityQueue using UnorderedArray  
{
    struct node<T> arr[1000];
    int size;
        
		public:
    PriorityQueue() 
	{   size = 0;   }
	
    void enqueue(T d, int priority)           // O(1)
	{ 
        arr[size].data = d;
        arr[size].priority = priority;
        size++;
    }
        
	void dequeue()                           // O(n)
	{ 
        int a = peek();
        for(int i=a; i<size-1; i++) 
        arr[i] = arr[i + 1];
            
        size--;
    }
        
	T peek()                                // O(n)
    {
		int maxp = INT32_MIN, maxpv;
        
		for(int i=0; i<size; i++) 
		{
            if(arr[i].priority > maxp) 
			{   
			    maxp = arr[i].priority;
                maxpv = i;    
			} 
			else if(arr[i].priority == maxp) 
			{
                if(arr[i].data >= arr[maxpv].data) 
                maxpv = i;
            }
        }
          
        return maxpv;
    }
};


int main() 
{
    PriorityQueue<int> p;
    p.enqueue(4, 2);
    p.enqueue(9, 8);	
	p.enqueue(1, 3);
    
    
    auto start1 = chrono::high_resolution_clock::now();
    p.enqueue(5, 1);                                                                // analyzing enqueue
    auto end1 = chrono::high_resolution_clock::now();
    double time_taken1 = chrono::duration_cast < chrono::nanoseconds > (end1 - start1).count();
    time_taken1 *= 1e-9;
    cout << "Time taken for enqueue : " << setprecision(9) << fixed << time_taken1 << endl;
     
    
    auto start2 = chrono::high_resolution_clock::now();
    p.peek();                                                                        // analyzing peek
    auto end2 = chrono::high_resolution_clock::now();
    double time_taken2 = chrono::duration_cast < chrono::nanoseconds > (end2 - start2).count();
    time_taken2 *= 1e-9;
    cout << "Time taken for peek : " << fixed << time_taken2 << setprecision(9) << endl;
    
    
    auto start3 = chrono::high_resolution_clock::now();
    p.dequeue();                                                                    // analyzing deque  
    auto end3 = chrono::high_resolution_clock::now();
    double time_taken3 = chrono::duration_cast < chrono::nanoseconds > (end3 - start3).count();
    time_taken3 *= 1e-9;
    cout << "Time taken for dequeue : " << fixed << time_taken3 << setprecision(9) << endl;
    
	
    cout << "\npeek value of the current PriorityQueue: " << p.peek() << endl;  
}