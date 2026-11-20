class NumArray {
public:
    NumArray(vector<int>& nums) {
        m_nums = nums;
    }
    
    int sumRange(int left, int right) {
        if(left == right) return m_nums[left];

        int res = 0;

        for(int i = left; i <= right; i++) {
            res += m_nums[i];
        }

        return res;
    }

private:
    vector<int> m_nums;

};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */