class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int occur = 1;
        int maxOccur = occur;

        cout << n / 2 << endl;
        
        for(int i = 1; i < n; i++) {
            if(nums[i] != nums[i-1]) {
                maxOccur = max(occur, maxOccur);
                cout << "max occur = ";
                cout << maxOccur << endl;
                occur = 1;
                if(maxOccur > n / 2) return nums[i-1];
            }
            occur++;
        }

        return nums[n-1];
    }
};