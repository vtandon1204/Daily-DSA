#include <bits/stdc++.h>
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    vector<int> nums3(m + n); // Initialize nums3 with size m + n
    int i = 0, j = 0, k = 0;

    // Merge both arrays into nums3
    while (i < m && j < n)
    {
        if (nums1[i] < nums2[j])
        {
            nums3[k++] = nums1[i++];
        }
        else
        {
            nums3[k++] = nums2[j++];
        }
    }

    // Copy remaining elements from nums1, if any
    while (i < m)
    {
        nums3[k++] = nums1[i++];
    }

    // Copy remaining elements from nums2, if any
    while (j < n)
    {
        nums3[k++] = nums2[j++];
    }

    // Copy the merged array back to nums1
    for (int x = 0; x < m + n; x++)
    {
        nums1[x] = nums3[x];
    }
}