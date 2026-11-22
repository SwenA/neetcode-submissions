class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> vec(arr.size(),-1);
        int x = arr[arr.size()-1];
        for(int i = arr.size()-2; i >= 0; --i) {
            x = max(arr[i+1],x);
            vec[i] = x; 
        }
        return vec;
    }
};