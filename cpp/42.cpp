//42. Trapping Rain Water
class Solution {
public:
    int trap(vector<int>& height) {
        //题目意思是由给定数组搭建成的俄罗斯方块之间有多少空隙
        
        int l = 0;
        int r = height.size() - 1;
        int level = 0;
        int water = 0;
        while (l < r)
        {
            int lower = height[height[l] < height[r] ? l++:r--];
            level = max(level,lower);
            water += level - lower;
        }
        return water;
    }
};
