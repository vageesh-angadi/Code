class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1),hash(n,-1);
        int res=1;
        int li=0;
        for(int i=0;i<n;i++){
            hash[i]=0;
            for(int pre=0;pre<i;pre++){
                if(nums[pre]<nums[i] && dp[i]<1+dp[pre])
                {
                   dp[i]=dp[pre]+1;
                   hash[i]=pre;
                }
            }
            if(res<dp[i]){
                res=dp[i];
                li=i;
            }   
        }
        vector<int>ans;
        ans.push_back(nums[li]);
        while(hash[li]!=li){
            li=hash[li];
            ans.push_back(nums[li]);
        }
        reverse(ans.begin(),ans.end());
        for(auto it:ans){
            cout<<it<<" ";
        }
        cout<<endl;
        return res;
    }
};
