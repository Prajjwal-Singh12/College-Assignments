#include<iostream>
#include<iomanip>
#include<ctime>
using namespace std;

void sort(int *A, int len)
{
    bool done = true;
    int offset = 1;

    while (done)
    {
        done = false;

        for (int i = 0; i < len - offset; ++i)
        {
            if (A[i] > A[i + 1])
                swap(A[i], A[i + 1]);
        }

        ++offset;
    }
}

int linear_search(int *A,int len, int val)
{
    for (int i = 0; i < len; ++i)
    {
        if (A[i] == val)
            return i;
    }

    return -1;
}

int binary_search(int *A, int len, int val)
{
    int high = len - 1;
    int low = 0;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (A[mid] > val)
            high = mid - 1;
        else if (A[mid] < val)
            low = mid + 1;
        else
            return mid;
    }

    return -1;
}

int main()
{
    system("cls");
    int A[100000];
    const int len = 100000;
    const int rounds = 1000;

    // filling the Array
    for (int i = 0; i < 100000; ++i)
        A[i] = rand() % 10000;

    clock_t start;
    clock_t end;
    double time_taken;

    cout << "Analyzing the linear search in worst case" << endl;
    start = clock();
    // finding the non-existing value
    linear_search(A, len, 10000);
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by linear search in worst case: " << setprecision(3) << time_taken * 1000 << " milisecond" << endl;


    cout << "Analyzing the linear search in average case" << endl;
    start = clock();
    for (int i = 0; i < rounds; ++i) {
        linear_search(A, len, rand() % 10001);
    }
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by linear search in average case: " << setprecision(3) << (time_taken * 1000) / rounds << " milisecond" << endl;


    cout << endl;
    cout << "-------" << endl;
    cout << "Sorting" << endl;
    cout << "-------" << endl;
    cout << endl;


    // sorting 
    sort(A, len);


    cout << "Analyzing the binary search in worst case" << endl;
    start = clock();
    // finding the non-existing value
    binary_search(A, len, 10000);
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by binary search in worst case: " << setprecision(3) << time_taken * 1000 << " milisecond" << endl;


    cout << "Analyzing the binary search in average case" << endl;
    start = clock();
    for (int i = 0; i < rounds; ++i) {
        binary_search(A, len, rand() % 10001);
    }
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by binary search in average case: " << setprecision(3) << (time_taken * 1000) / rounds << " milisecond" << endl;
}