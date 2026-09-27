class Solution {
public:

    void merge(vector<pair<int, int>>& arr,
               vector<int>& ans,
               int low, int mid, int high) {

        vector<pair<int, int>> temp;

        int left = low;
        int right = mid + 1;
        int rightCount = 0;

        while (left <= mid && right <= high) {

            if (arr[right].first < arr[left].first) {
                temp.push_back(arr[right]);
                rightCount++;
                right++;
            }
            else {
                ans[arr[left].second] += rightCount;
                temp.push_back(arr[left]);
                left++;
            }
        }

        while (left <= mid) {
            ans[arr[left].second] += rightCount;
            temp.push_back(arr[left]);
            left++;
        }

        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    void mergeSort(vector<pair<int, int>>& arr,
                   vector<int>& ans,
                   int low, int high) {

        if (low >= high)
            return;

        int mid = low + (high - low) / 2;

        mergeSort(arr, ans, low, mid);
        mergeSort(arr, ans, mid + 1, high);

        merge(arr, ans, low, mid, high);
    }

    vector<int> countSmaller(vector<int>& nums) {

        int n = nums.size();

        vector<pair<int, int>> arr;
        vector<int> ans(n, 0);

        // Store {value, original index}
        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        mergeSort(arr, ans, 0, n - 1);

        return ans;
    }
};