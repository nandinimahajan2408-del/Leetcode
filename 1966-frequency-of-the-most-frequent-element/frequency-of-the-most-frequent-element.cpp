class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        // Sort the array to group similar values and process sequentially
        sort(nums.begin(), nums.end());
        
        int left = 0;
        int max_freq = 0;
        long long current_sum = 0; // Use long long to prevent integer overflow
        
        for (int right = 0; right < nums.size(); ++right) {
            current_sum += nums[right];
            
            // Total operations needed to make all elements in current window 
            // equal to nums[right] is: (nums[right] * window_length) - current_sum
            while ((long long)nums[right] * (right - left + 1) - current_sum > k) {
                current_sum -= nums[left];
                left++;
            }
            
            // Update the maximum frequency found so far
            max_freq = std::max(max_freq, right - left + 1);
        }
        
        return max_freq;
    }
};