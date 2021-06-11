#include <iostream>

using namespace std;

void Sort(int price[],int  profit[], int n) {
   int mini, tempW,tempP;
   for (int i = 0; i < n - 1; i++) {
      mini = i;
      for (int j = i + 1; j < n; j++)
        if (price[j] < price[mini])
            mini = j;

      tempW = price[i];             tempP=profit[i];
      price[i] = price[mini];       profit[i]=profit[mini];
      price[mini] = tempW;          profit[mini]=tempP;
   }
}

int knapsackDP(int voucher, int prices[], int profits[], int n)
{
    Sort(prices,profits,n);
    int arr[n+1][voucher+1];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=voucher;j++)
        {
            if(i==0||j==0)
                arr[i][j]=0;
            else if(prices[i]<=j)
            {
                if(profits[i]+arr[i-1][j-prices[i]]>arr[i-1][j])
                    arr[i][j]=profits[i]+arr[i-1][j-prices[i]];
                else
                    arr[i][j]=arr[i-1][j];
            }
            else
            {
                arr[i][j] = arr[i-1][j];
            }
        }
    }
    return arr[n-1][voucher];
}

int main()
{
    int prices[8]={8, 3, 5, 1, 4, 20, 7, 22}, profit[8]={14, 5, 8, 3, 6, 28, 10, 27}, voucher=30;

    cout<<"maximum profile resale is : "<<knapsackDP(voucher,prices,profit,8);
    return 0;
}
