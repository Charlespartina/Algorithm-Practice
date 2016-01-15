// Use vector.erase()
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int sz = nums.size();
        int cont = 0;
        for(int i = 0; i < sz && cont < sz; i++){
            cont++;
            if(nums[i] == 0){
                nums.erase(nums.begin()+i);
                i--;
                nums.push_back(0);
            }
        }
    }
};