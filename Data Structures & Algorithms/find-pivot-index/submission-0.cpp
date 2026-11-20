class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sumLeft = 0;
        int sumRight = 0;
        for(int i = 0; i < nums.size(); i++){
            sumLeft = 0;
            sumRight = 0;
            for(int j = 0; j < nums.size(); j++){
                while(j < i){ 
                    sumLeft += nums[j];
                    j++;
                }
                if(j == i) continue;
                sumRight += nums[j];
            }
        cout << sumLeft << endl;
        cout << sumRight << endl;
        if(sumLeft == sumRight) return i;
        }
        return -1;
    }
};