/* ---Problem ---
You have an array of n integers
containing elements A[i] = 1,1 Sisn.
You have to rearrange the array in a
manner such that
(mar(A1), A2)....,Ai) - min(All), A2),
is Maximum
max(A[1], A2)... Ail) is the maximum
element from index 1 to i
min(A[1], A2), . , A[i]) is the minimum
element from index 1 to i
INPUT
First-line contains a single integer t: The number of
test cases
Next t lines contain a single integer n
OUTPUT
For each test case print the maximum sum you can
obtain
CONSTRAINTS
1<t<10%
1<n<106

*/

// solution 
#include <iostream>
int main()
{
    
    using namespace std;
    int t,n;
   cin>>t;
   while(t--)
    {   long long int n;
        cin>>n;          
        cout<<((n-1)*(n-1))<<"\n";
    }
    return 0;
}