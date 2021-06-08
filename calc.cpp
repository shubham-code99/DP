#include<iostream>
#include<vector>
using namespace std;
/*
int ways(int n)
{
    vector<int> minways(n+1);
    vector<int> nums;
    int minw=0,num;
    minways[2]=1;
    minways[3]=1;
    for(int i=4;i<=n;++i)
    {
        minways[i]=minways[i-1]+1;
        if(i%3==0)
        {
            minw=minways[i/3]+1;
        }
        else if((i-1)%3==0)
        {
            minw=minways[i/3]+2;
        }
        else if(i%2==0)
        {
            minw=minways[i/2]+1;
        }
        else if((i-1)%2==0)
        {
            minw=minways[i/2]+2;
        }   
        if(minw<=minways[i])
            minways[i]=minw;  
    }
    return minways[n];
}

int main()
{
    int n;
    cin>>n;
    int w=ways(n);
    cout<<w<<endl;
    vector<int> num;
    //num.push_back(n);
    for(int i=1;i<=w;++i)
    {
        if(n%3==0)
        {
            num.push_back(n);
            n/=3;            
        }
        else if((n-1)%3==0)
        {
            num.push_back(n);
            n-=1;
        }
        else if(n%2==0)
        {
            num.push_back(n);
            n/=2;            
        }
        else if((n-1)%2==0)
        {
            num.push_back(n);
            n-=1;
        }   
                
    }
    num.push_back(1);
    for(int i=num.size()-1;i>=0;--i)
     cout<<num[i]<<" ";
    return 0;
}
*/

/*
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> dp_sequence(int n)
{
  vector<int> dp = {0};
  vector<int> sequence;
  vector<int> operations = {1};
  if (n == 1)
  {
    sequence.push_back(1);
    return sequence;
  }
  for (int i = 2; i <= n; i++)
  {
    int res1 = 999999;
    int res2 = 999999;
    int res3 = 999999;
    res1 = dp[i - 2];
    if (i % 2 == 0)
    {
      res2 = dp[(i / 2) - 1];
    }
    if (i % 3 == 0)
    {
      res3 = dp[(i / 3) - 1];
    }
    if (res3 <= res2 && res3 <= res1)
    {
      operations.push_back(3);
      dp.push_back(res3 + 1);
    }
    else if (res2 <= res1 && res2 <= res3)
    {
      operations.push_back(2);
      dp.push_back(res2 + 1);
    }
    else if (res1 <= res2 && res1 <= res3)
    {
      operations.push_back(1);
      dp.push_back(res1 + 1);
    }
  }

  int i = n;
  while (i >= 1)
  {
    sequence.push_back(i);
    if (operations[i - 1] == 1)
    {
      i -= 1;
    }
    else if (operations[i - 1] == 2)
    {
      i /= 2;
    }
    else
    {
      i /= 3;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}


int main()
{
  int n;
  std::cin >> n;
  vector<int> sequence = dp_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i)
  {
    std::cout << sequence[i] << " ";
  }
}
*/

