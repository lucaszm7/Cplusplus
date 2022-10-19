#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::vector<int> cp = nums;
        std::sort(cp.begin(), cp.end());
        int low, up;
        int i = 0;
        int k = nums.size() - 1;
        while (i != k)
        {
            if ((cp[i] + cp[k]) == target)
                break;
            else if ((cp[i] + cp[k]) > target)
                --k;
            else // nums[i] + nums[k]) < target
                ++i;
        }

        int r1 = 0, r2 = 0;
        for (int j = 0; j < nums.size(); ++j)
        {
            if (nums[j] == cp[i])
            {
                r1 = j;
                break;
            }
        }
        for (int j = 0; j < nums.size(); ++j)
        {
            if (nums[j] == cp[k] && j != i)
            {
                r2 = j;
                break;
            }
        }

        std::vector<int> result;
        result.push_back(r1);
        result.push_back(r2);
        return result;
    }
};