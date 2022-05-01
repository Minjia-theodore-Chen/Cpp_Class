#include "..\header\functions.h"
#include "..\header\answers.h"

int main()
{
    Median_of_Two_Sorted_Arrays problem;
    std::vector<int> nums1{1, 2};
    std::vector<int> nums2{3, 4, 5};
    std::vector<int> nums3{3};

    std::cout << problem.findMedianSortedArrays(nums1, nums2) << std::endl;

    std::cin.get();
}
