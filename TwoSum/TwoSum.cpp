
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (vector<int>::iterator it = nums.begin(); it != nums.end() - 1; it++){
            for (vector<int>::iterator itt = nums.begin() + 1; itt != nums.end(); it++){
                if((*it + *itt) == target){
                    vector<int> result = new vector<int>;
                    result.push_back(*it);
                    result.push_back(*itt);
                    return 
                }
            }
        }
    }
};