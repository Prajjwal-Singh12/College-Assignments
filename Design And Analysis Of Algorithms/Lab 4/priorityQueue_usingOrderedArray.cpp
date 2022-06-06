#include<iostream> 
#include<chrono> 
#include<iomanip> 
using namespace std;


template <class T>
struct node 
{
    T data;                                 // data of the node
    int priority;                           // priority of the node 
};


template <class T>
class PriorityQueue                         // implementing PriorityQueue using OrderedArray   
{
        public:
    struct node<T> arr[1000];
    int size;
        
	PriorityQueue() 
	{   size = 0;   }
	
    void enqueue(T d, int priority)         // O(n)
    {
		int j = size;
            
		for(; j>=0; j--) 
		{
            if(priority > arr[j].priority) 
			arr[j+1] = arr[j];
            else if(priority == arr[j].priority) 
			{
                if(arr[j].data < d) 
                arr[j+1] = arr[j];
                else 
				break;
            } 
			else 
			break;
        }
            
		arr[j+1].data = d;
        arr[j+1].priority = priority;
        size++;
    }
        
	void dequeue()                           // O(n)
    {
		int a=0;
            
		for(int i=a; i<size-1; i++) 
        arr[i] = arr[i+1];
            
        size--;
    }

    T peek()                                // O(1)
    {   return arr[0].data;   }
};


int main() 
{
    PriorityQueue<int> p;
    p.enqueue(4, 2);
    p.enqueue(5, 9);
	p.enqueue(1, 8);
    
    
    auto start1 = chrono::high_resolution_clock::now();
    p.enqueue(3, 1);                                                                // analyzing enqueue
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