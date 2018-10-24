//338. Counting Bits
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>res;
        res.push_back(0);
        int prev_bit = 1;
        int num2 = 0;
        for(int i=1;i<=num;i++)
        {
            if (prev_bit * 2 == i)
            {
                prev_bit *= 2;
            }
            res.push_back(res[i - prev_bit] + 1);

        }
        return res;
    }
};
