/*
#include<iostream>
#include<vector>
#include<tuple>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

tuple<int, int> minmax(int i, int j, vector<vector<int>> &M, vector<vector<int>> &m, vector<char> &op2)
{
    int Min=INT_MAX, Max=INT_MIN;
    int a,b,c,d;
    for(int k=i;k<j;++k)
    {
        if(op2[k]=='+')
        {
            a=M[i][k]+M[k+1][j];
            b=M[i][k]+m[k+1][j];
            c=m[i][k]+M[k+1][j];
            d=m[i][k]+m[k+1][j];

        }
        else if(op2[k]=='-')
        {
            a=M[i][k]-M[k+1][j];
            b=M[i][k]-m[k+1][j];
            c=m[i][k]-M[k+1][j];
            d=m[i][k]-m[k+1][j];
        }
        else
        {
            a=M[i][k]*M[k+1][j];
            b=M[i][k]*m[k+1][j];
            c=m[i][k]*M[k+1][j];
            d=m[i][k]*m[k+1][j];
        }
        Min=min({Min,a,b,c,d});
        Max=max({Max,a,b,c,d});
    }
    return make_tuple(Min, Max);
}

int paranthesis(vector<int> &num, vector<char> &op)
{
    vector<vector<int>> M( num.size()+1 , vector<int> (num.size()+1, 0));
    vector<vector<int>> m( num.size()+1 , vector<int> (num.size()+1, 0));
    for(int i=1;i<=num.size();++i)
    {
        M[i][i]=num[i-1];
        m[i][i]=num[i-1];
    }
    int j;
    for(int s=1;s<num.size();s++)
    {
        for(int i=1;i<=num.size()-s;++i)
        {
            j=i+s;
            tie(m[i][j],M[i][j])=minmax(i,j,M,m,op);
        }
    }
    return M[1][num.size()];
}

int main()
{
    string s;
    cin>>s;
    vector<int> num;
    vector<char> op;
    for(int i=1;s[i-1]!='\0';++i)
    {
        if(i%2!=0)
            num.push_back((int)(s[i-1]-'0'));
        else
            op.push_back(s[i-1]);
    }
    cout<<paranthesis(num,op);
    return 0;
}
*/

#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <cstring>
#include <climits>
#include <cmath>
using std::vector;
using std::string;
using std::max;
using std::min;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
  return 0;
}

long long get_maximum_value(const string &exp) {
  int length = exp.size();
  int numOfnum = (length + 1) / 2;
  long long minArray[numOfnum][numOfnum];
  long long maxArray[numOfnum][numOfnum];
  memset(minArray,0,sizeof(minArray)); // initialize to 0
  memset(maxArray,0,sizeof(maxArray));
  for (int i = 0; i < numOfnum; i++)
  {
	  //The values on the main diagonal is just the number themselves
	  minArray[i][i] = std::stoll(exp.substr(2*i,1));
	  maxArray[i][i] = std::stoll(exp.substr(2*i,1));
  }

  for (int s = 0; s < numOfnum - 1; s++)
  {
	  for (int i = 0; i < numOfnum - s - 1; i++)
	  {
		  int j = i + s + 1;
		  long long minVal = LLONG_MAX;
	      long long maxVal = LLONG_MIN;
	      // find the minimum and maximum values for the expression
	      // between the ith number and jth number
		  for (int k = i; k < j; k++ )
	      {
			  long long a = eval(minArray[i][k],minArray[k + 1][j],exp[2 * k + 1]);
			  long long b = eval(minArray[i][k],maxArray[k + 1][j],exp[2 * k + 1]);
			  long long c = eval(maxArray[i][k],minArray[k + 1][j],exp[2 * k + 1]);
			  long long d = eval(maxArray[i][k],maxArray[k + 1][j],exp[2 * k + 1]);
			  minVal = min(minVal,min(a,min(b,min(c,d))));
			  maxVal = max(maxVal,max(a,max(b,max(c,d))));
	      }
		  minArray[i][j] = minVal;
		  maxArray[i][j] = maxVal;
	  }
  }

  return maxArray[0][numOfnum - 1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}