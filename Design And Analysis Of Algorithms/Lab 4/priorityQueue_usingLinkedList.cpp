#include<iostream>
#include<chrono>
#include<iomanip>
using namespace std;


template <class T>
struct node 
{
    T data;                    // data of the node
    int priority;              // priority of the node   
    node *next;                // address of the next node
        
	node(T d, int p) 
	{   data = d;
        priority = p;
        next = NULL;   }
};


template <class T>
class PriorityQueue            // implementing PriorityQueue using LinkedList                 
{
        public:
    node<T> *head;
    
    PriorityQueue() 
	{   head = NULL;    }
	
    void enqueue(T d, int priority)                // O(n)
    {
		node<T> *temp = new node<T>(d, priority);
            
		if(head == NULL) 
		{   head = temp;
            return;   }
            
        node<T> *p=head, *prev;
            
		while(p != NULL) 
		{
            if(p->priority > priority) 
			{
                prev = p;
                p = p->next;
            } 
			else if(p->priority == priority) 
			{
                if(p->data > d) 
				{   prev = p;
                    p = p->next;   } 
				else 
				break;
            } 
			else 
			break;
        }
            
		if(p == head) 
		{   temp->next = head;
            head = temp;    } 
		else 
		{   temp->next = prev -> next;
            prev->next = temp;   }
    }
        
	void dequeue()                             // O(1)
	{ 
        if(head == NULL) 
		{   cout << "Empty PriorityQueue" << endl;
            return;   }
             
        head = head->next;
    }
        
	T peek()                                   // O(1)
	{ 
        if(head == NULL) 
		{   cout << "Empty PriorityQueue" << endl;
            return -1;   }
            
		return head->data;
    }
};
 

int main() 
{
    PriorityQueue<int> p;
    p.enqueue(4, 2);
    p.enqueue(9, 8);    
    p.enqueue(1, 11);
    
    
    auto start1 = chrono::high_resolution_clock::now();
    p.enqueue(3, 1);                                                                // analyzing enqueue
    auto end1 = chrono::high_resolution_clock::now();
    double time_taken1 = chrono::duration_cast <chrono::nanoseconds> (end1 - start1).count();
    time_taken1 *= 1e-9;
    cout << "Time taken for enqueue : " << setprecision(9) << fixed << time_taken1 << endl;
    
    
    auto start2 = chrono::high_resolution_clock::now();
    p.peek();                                                                        // analyzing peek
    auto end2 = chrono::high_resolution_clock::now();
    double time_taken2 = chrono::duration_cast <chrono::nanoseconds> (end2 - start2).count();
    time_taken2 *= 1e-9;
    cout << "Time taken for peek : " << fixed << time_taken2 << setprecision(9) << endl;
    
    
    auto start3 = chrono::high_resolution_clock::now();
    p.dequeue();                                                                    // analyzing deque  
    auto end3 = chrono::high_resolution_clock::now();
    double time_taken3 = chrono::duration_cast <chrono::nanoseconds> (end3 - start3).count();
    time_taken3 *= 1e-9;
    cout << "Time taken for dequeue : " << fixed << time_taken3 << setprecision(9) << endl;
    
    
    cout << "\npeek value of the current PriorityQueue: " << p.peek() << endl;  
}