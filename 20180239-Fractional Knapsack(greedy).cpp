#include <iostream>

using namespace std;

struct item
{
    int W,P;
    double P_per_W;
    item()
    {
        W=0;    P=0;
    }
    item(int weight, int profit)
    {
        W=weight;   P=profit;
        P_per_W=(double)P/W;
    }

};

void sortItems(struct item it[], int siz)
{
    struct item temp;
    for (int i=0;i<siz-1;i++) {
          int mini = i;
          for (int j=i+1;j<siz;j++)
              if(it[mini].P_per_W>it[j].P_per_W)
                mini=j;

          temp=it[i];
          it[i]=it[mini];
          it[mini]=temp;
    }
};

double knapsack(struct item it[],int siz,int capacity)
{
    double profit=0.0;
    sortItems(it,siz);
    for(int i=siz-1;i>=0;i--)
    {
        if(capacity-it[i].W>=0)
        {
            capacity-=it[i].W;
            profit+=it[i].P;
        }
        else{
            profit+=it[i].P*((double)capacity/it[i].W);
            break;
        }
    }
    return profit;
}

int main()
{
    int capacity,n;
    cout<<"enter the capacity : ";
    cin>>capacity;
    cout<<"enter number of the items : ";
    cin>>n;
    item items[n];
    for(int i=0;i<n;i++)
    {
        int w,p;
        cout<<"enter weight for the "<<i+1<<" item : ";     cin>>w;
        cout<<"enter it's value : ";                        cin>>p;
        items[i]= item(w,p);
    }

    cout<<"\nthe maximum total value is : "<<knapsack(items,n,capacity);
    return 0;
}
