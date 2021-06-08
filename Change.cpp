#include<iostream>
#include<vector>
using namespace std;

int mincoin(int n, vector<int> &arr)
{
    vector<int> ways(n+1);
    ways[0]=1;
    for(int i=0;i<arr.size();++i)
    {
        for(int j=0;j<ways.size();++j)
        {
            if(arr[i]<=j)
            {
                ways[j]+=ways[(j-arr[i])];
            }
        }        
    }
    return ways[n];
}

int main()
{
    int n;
    vector<int> arr={1,3,4};
    cin>>n;
    cout<<mincoin(n,arr);
    return 0;
}