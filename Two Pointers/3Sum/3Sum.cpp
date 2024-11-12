class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int len = nums.size();
        vector<vector<int>> v;

        //Initial Condition
        if(len < 3) return v;

        sort(nums.begin(),nums.end());

        //Boundary Condition 1
        for(int i = 0; i < len-2; i++)
        {
            //Boundary Condition 2
            if(i != 0 && nums[i] == nums[i-1]) continue;
            int l = i+1;
            int r = len-1;
            while(l<r)
            {

                long long ans = nums[i] + nums[l] + nums[r];
                

                if(ans == 0)  
                {
                    v.push_back({nums[i],nums[l],nums[r]});

                    //Remove the duplicate triplets
                    while(l < r && nums[l] == nums[l+1]){l++;}
                    l++;
                    while(l < r && nums[r] == nums[r-1]){r--;}
                    r--;
                }
                else if(ans > 0)
                {
                    //Move to left, decrease the ans
                    r--;
                }
                else
                {
                    //Move to right, increase the ans
                    l++;
                }
            }
        }
        return v;
    }
};
