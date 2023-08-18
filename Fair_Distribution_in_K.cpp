#include<bits/stdc++.h>
using namespace std;
int res=INT_MAX;
    void solve(int idx,vector<int> &nums,int k,vector<int> &temp)
    {
        if(idx>=nums.size())
        {
            int mx=*max_element(temp.begin(),temp.end());
            res=min(res,mx);
            return;
        }
        // int res=0;
        for(int i=0;i<k;i++)
        {
            temp[i]+=nums[idx];
            solve(idx+1,nums,k,temp);
            temp[i]-=nums[idx];
            // solve(idx+1,nums,k,temp);
        }
        return;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        
        vector<int> temp(k,0);
        solve(0,cookies,k,temp);
        return res;
    }

int main()
{
    vector<int> nums={8,10,5,15,16};
    int k=2;
    vector<int> temp(k,0);
    solve(0,nums,k,temp);
    return res;
}