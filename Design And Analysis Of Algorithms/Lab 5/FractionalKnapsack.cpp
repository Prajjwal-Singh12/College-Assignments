    //FRACTIONAL KANPSACK
    #include <bits/stdc++.h>
    using namespace std;

    struct item
    {
        int value,weight;
    };

    bool cmp(item a,item b)
    {
        double r1=(double)a.value/a.weight;
        double r2=(double)b.value/b.weight;
        return(r1>r2);
    }

    double fractionalKnapsack(item A[],int Total_Capacity,int n)
    {
        sort(A,A+n, cmp);
        
        int cur_weight = 0;
        double final_val = 0.0;
        
        for(int i=0;i<n;i++)
        {
            if(cur_weight + A[i].weight <= Total_Capacity)
            {
                cur_weight += A[i].weight;
                final_val += A[i].value;
            }
            else
            {
                int remain = Total_Capacity - cur_weight;
                final_val += A[i].value * ((double)remain / A[i].weight);
            }
        }
        return final_val;
    }

    int main()
    {
        system("cls");
        int n=3, W=50;  
        item arr[] = {{60,10 }, {100,20}, {120,30}};
    
        cout << "Maximum value we can obtain = " << fractionalKnapsack(arr, W,  n); 
    }