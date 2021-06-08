#include<iostream>
#include<vector>

using namespace std;
int change(int n, vector<int> &coins)
{
    vector<int> minways(n+1);
    int numcoins;
    for(int i=1;i<=n;++i)
    {
        minways[i]=2147483647;
        for(int j=0;j<3;++j)
        {
            if(i>=coins[j])
            {
                numcoins=minways[i-coins[j]]+1;
                if(numcoins<minways[i])
                    minways[i]=numcoins;
            }
        }
    }
    return minways[n];
}
int main()
{
    int n;
    cin>>n;
    vector<int> coins= {1,8,10};
    cout<<change(n,coins);
    return 0;
}