class Solution {
public:
    int maxArea(vector<int>& height) {
        int water = 0;
    int i = 0, j = height.size() - 1;
    while (i < j) {
        int h = min(height[i], height[j]);
        water = max(water, (j - i) * h);
        if (height[i] <= h && i < j) i++;
        if (height[j] <= h && i < j) j--;
    }
    return water;
    }
};