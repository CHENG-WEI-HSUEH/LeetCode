class Solution 
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

        int Len1 = nums1.size(), Len2 = nums2.size();
        int Len = Len1 + Len2;
        int Start = 0, End = Len1;

        while(Start<=End)
        {
            int Mid1 = Start + (End - Start)/2;
            int Mid2 = (Len+1)/2 - Mid1;
            
            int L1 = Mid1 == 0? INT_MIN:nums1[Mid1-1];
            int L2 = Mid2 == 0? INT_MIN:nums2[Mid2-1];
            int R1 = Mid1 == Len1? INT_MAX:nums1[Mid1];
            int R2 = Mid2 == Len2? INT_MAX:nums2[Mid2];

            if(L1>R2)
            {
                End = Mid1 - 1;
            }
            else if(L2>R1)
            {
                Start = Mid1 + 1;
            }
            else 
            {
                
                if(Len%2 == 0) return (max(L1,L2) + min(R1,R2))/2.0;
                else return max(L1,L2);
            }
        }
        return 0.0;

    }


};
