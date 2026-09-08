
class Solution {
public:

    int merge(vector<int>& nums, int st, int mid, int ed) {

        int count = 0;

        // Count reverse pairs
        int j = mid + 1;

        for (int i = st; i <= mid; i++) {

            while (j <= ed &&
                   (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }

            count += j - (mid + 1);
        }


        // Normal merge
        vector<int> temp;

        int i = st;
        j = mid + 1;

        while (i <= mid && j <= ed) {

            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i]);
                i++;
            }
            else {
                temp.push_back(nums[j]);
                j++;
            }
        }

        while (i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }

        while (j <= ed) {
            temp.push_back(nums[j]);
            j++;
        }


        // Copy back
        for (int k = 0; k < temp.size(); k++) {
            nums[st + k] = temp[k];
        }

        return count;
    }

    int mergeSort(vector<int>& arr, int st, int ed) {

        if (st >= ed) {
            return 0;
        }

        int mid = st + (ed - st) / 2;

        int leftCount = mergeSort(arr, st, mid);
        int rightCount = mergeSort(arr, mid + 1, ed);

        int count = merge(arr, st, mid, ed);

        return leftCount + rightCount + count;
    }


    int reversePairs(vector<int>& arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};
