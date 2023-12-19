class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(), processorTime.end());
        sort(tasks.begin(), tasks.end());
        // No need to use "sort(tasks.begin(), tasks.end(), greater<>());" here

        // Just assign the tasks intuitively, ignoring the quite confusing description
        int ans = 0, i = tasks.size() - 1;
        for (auto& t : processorTime) {
            ans = max(ans, tasks[i] + t);
            i -= 4;
        }   
        return ans;
    }
};