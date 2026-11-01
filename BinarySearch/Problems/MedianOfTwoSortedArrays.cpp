#include<iostream>
#include<vector>
#include<climits>

using namespace std;

double findMedianSortedArraysBrute(vector<int>& nums1, vector<int>& nums2) {
    //Brute Force Approach: using a third array to merge the given two arrays and finding median
    //T.C --> O(n1 + n2) + O(n1 + n2), S.C --> O(n1 + n2)
    int n1 = nums1.size(), n2 = nums2.size();
    vector<int> merged;

    int i = 0, j = 0;

    while(i < n1 && j < n2)
    {
        if(nums1[i] <= nums2[j])merged.push_back(nums1[i++]);
        else merged.push_back(nums2[j++]);
    }
    while(i < n1)
    {
        merged.push_back(nums1[i++]);
    }
    while(j < n2)
    {
        merged.push_back(nums2[j++]);
    }

    int n = merged.size(); //O(n1 + n2)
    
    if(n % 2 == 1)return (double)merged[n/2];
    return (merged[n/2] + merged[(n/2) - 1]) / 2.0;
}

double findMedianSortedArraysBetter(vector<int>& nums1, vector<int>& nums2) {
    //Better Approach:using 2 pointers and counter to identify the required elements for
    //calculating median of the merged arrays without actually merging them
    // O(n1 + n2), S.C --> O(1)
    //**Cleaner Code**
    int n1 = nums1.size(), n2 = nums2.size(), n = n1 + n2;
    int i = 0, j = 0, count = 0;
    int ele1 = 0, ele2 = 0, indEle1 = n/2, indEle2 = (n/2) - 1;

    while(i < n1 && j < n2)
    {
        if(nums1[i] <= nums2[j])
        {
            if(count == indEle1)ele1 = nums1[i];
            if(count == indEle2)ele2 = nums1[i];
            i++;
        }
        else
        {
            if(count == indEle1)ele1 = nums2[j];
            if(count == indEle2)ele2 = nums2[j];
            j++;
        }
        count++;
    }

    while(i < n1)
    {
        if(count == indEle1)ele1 = nums1[i];
        if(count == indEle2)ele2 = nums1[i];
        i++;
        count++;
    }

    while(j < n2)
    {
        if(count == indEle1)ele1 = nums2[j];
        if(count == indEle2)ele2 = nums2[j];
        j++;
        count++;
    }

    if(n % 2 == 1)return (double)ele1;

    return (ele1 + ele2) / 2.0;
}

double findMedianSortedArraysOptimal(vector<int>& nums1, vector<int>& nums2) {
    //Optmial Approach: applying binary search in a tricky manner. We make left and right
    //divisions of the hypothetically merged arrya and then decide how many elements we 
    //need in the left half from array1 and how many from array2  
    //calculating median of the merged arrays without actually merging them
    // O(logN1), S.C --> O(1)
    int n1 = nums1.size(), n2 = nums2.size();

    if(n1 > n2)return findMedianSortedArraysOptimal(nums2, nums1); //making sure array1 has the smaller size
    
    int low = 0, high = n1;
    int left = (n1 + n2 + 1) / 2;

    while(low <= high)
    {
        int mid1 = (low + high) >> 1; // same as(low + high) / 2;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        if(mid1 < n1)r1 = nums1[mid1];
        if(mid2 < n2)r2 = nums2[mid2];

        if(mid1 - 1 >= 0)l1 = nums1[mid1 - 1];
        if(mid2 - 1 >= 0)l2 = nums2[mid2 - 1];

        if(l1 <= r2 && l2 <= r1)
        {
            if((n1 + n2) % 2 == 1)return max(l1, l2);
            return ((double)(max(l1, l2) + min(r1, r2)) / 2.0);
        }
        else if(l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }

    return 0;
}

int main()
{
    vector<int> nums1 = {1, 3, 4, 7, 10, 12};
    vector<int> nums2 = {2, 3, 6, 15};

    cout<<"Median of given 2 Sorted arrays is: "<<findMedianSortedArraysBrute(nums1, nums2)<<"\n";
    cout<<"Median of given 2 Sorted arrays is: "<<findMedianSortedArraysBetter(nums1, nums2)<<"\n";
    cout<<"Median of given 2 Sorted arrays is: "<<findMedianSortedArraysOptimal(nums1, nums2);

    return 0;
}
