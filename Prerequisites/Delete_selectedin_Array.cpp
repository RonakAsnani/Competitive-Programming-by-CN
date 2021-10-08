/* ---Problem--
As we are on the verge of witnessing
maiden World Test Championship aka
(Test World Cup) and Indian team does
not want to lose it, so going one step
ahead, after controversial Yo-yo
test managment has decided to add one
more criteria for selection in playing 11
the criteria is none other than
competetive coding. So every player is
given the following problem to solve
Help them out in securing their position
in the team.
ICC WORLD TEST CHAMPIONSHIP
You are given an array arr consisting
of n Positive integers. You want to
delete exactly mintegers (m<=n) from
the array.
You will use following operations m
times,
. if there is at least one integer 1
delete the first occurrence and stop
the algorithm, otherwise proceed to
next integer
• If there is at least one integer 2
delete the first occurrence and stop
the algorithm, otherwise proceed to
next integer;
....and so on
This algorithm removes an Integer from
the array. You will perform this
algorithm exactly m times, thus removing
exactly m Integers.
You have to find final state of the array.
Input
The first line of input contains two
integers n and m (1 <=m<=TI<= 4.100
and 1 <=arr;<= 100 )— the length of the
array and the number of integers
You will delete..
The second line contains n integers
where ith Integer denotes arn.
Output
Print the array that will be obtained from
arr after you delete exactly
m Integers using the above algorithm
m times.  */

// solution code here 

#include<bits/stdc++.h>
 
#include<iostream>
 
using namespace std;
 
int main() 
{
    int n,m,i;
    cin>>n>>m;
    if(m==n)
    {
        cout<<-1<<endl;
        return 0;
    }
int a[n];
for (int i=0;i<n;i++) cin>>a[i];
vector<pair<int, int>>vp; 
        for (i=0;i<n; i++)
            {
                vp.push_back(make_pair (a[i],i));
            }
 
sort(vp.begin(),vp.end());
 vector<pair<int, int>>vn;
 
for ( i=m;i<n;i++)
{ 
    vn.push_back(make_pair (vp[i].second, vp[i].first));
}
sort(vn.begin(),vn.end()
);
 
for ( i=0; i<vn.size();i++)
    {
        cout<<vn [i].second<<" ";       
    }
return 0;
}