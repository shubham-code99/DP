#include<iostream>
#include<vector>
using namespace std;

int distance(vector<int> &a, vector<int> &b)
{
  vector<vector<long long>> dp(a.size() + 1, vector<long long>(b.size() + 1, 0));
  for (size_t i = 1; i <= a.size(); i++)
  {
    for (size_t j = 1; j <= b.size(); j++)
    {
      if (a[i - 1] == b[j - 1])
      {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      }
      else
      {
        dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  return dp[a.size()][b.size()];
}





int main()
{
    int n,m,a;
    cin>>n;
    vector<int> n1,n2;
    for(int i=0;i<n;++i)
    {
        cin>>a;
        n1.push_back(a); 
    }
    cin>>m;
    for(int  i=0;i<m;++i)
    {
        cin>>a;
        n2.push_back(a); 
    }
    cout<<distance(n1,n2);
    return 0;
}