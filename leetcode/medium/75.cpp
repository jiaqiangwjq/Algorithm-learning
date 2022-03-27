class Solution {
public:
    void quickSort(vector<int>& a, int left, int right) {
        int i, j, temp;
        if (left > right) return;
        temp = a[left];
        i = left;
        j = right;

        while(i != j) {
            while(a[j] >= temp && i < j) --j;
            while(a[i] <= temp && i < j) ++i;
            if (i < j) swap(a[i], a[j]);
        }
        a[left] = a[i];
        a[i] = temp;

        quickSort(a, left, i-1);
        quickSort(a, i+1, right);
    }

    void sortColors(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
    }
};