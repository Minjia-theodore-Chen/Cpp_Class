
#pragma once
#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

class Two_Sum
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {

        std::unordered_map<int, int> indices;

        for (int i = 0; i < nums.size(); i++)
        {
            if (indices.find(target - nums[i]) != indices.end())
            {
                return {indices[target - nums[i]], i};
            }
            indices[nums[i]] = i;
        }
        return {};
    }
};

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Add_Two_Numbers
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *temp1 = l1;
        ListNode *temp2 = l2;
        ListNode *temp;
        int carry = 0;
        int a;
        while (temp1 && temp2)
        {

            if (temp1->next == NULL)
                temp = temp1;

            a = temp1->val;
            temp1->val = (temp1->val + temp2->val + carry) % 10;
            carry = (a + temp2->val + carry) / 10;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if (temp2)
        {
            temp1 = temp;
            temp1->next = temp2;
            temp1 = temp1->next;
        }

        if (temp1)
        {

            while (carry && temp1)
            {
                if (temp1->next == NULL)
                    temp = temp1;
                a = temp1->val;
                temp1->val = (temp1->val + carry) % 10;
                carry = (a + carry) / 10;
                temp1 = temp1->next;
            }
        }
        if (carry == 1)
        {
            ListNode *n = new ListNode(1);
            temp->next = n;
        }
        return l1;
    }
};

class Longest_Substring_Without_Repeating_Characters
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        int store[256] = {0};
        int l = 0;
        int r = 0;
        int ans = 0;

        while (r < s.length())
        {
            store[s[r]]++;
            while (store[s[r]] > 1)
            {
                store[s[l]]--;
                l++;
            }

            ans = std::max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};

class Median_of_Two_Sorted_Arrays
{
public:
    double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        double ans = 0.0;
        std::vector<int> Holder;
        Holder.reserve(nums1.size() + nums2.size());
        Holder.insert(Holder.end(), nums1.begin(), nums1.end());
        Holder.insert(Holder.end(), nums2.begin(), nums2.end());
        std::sort(Holder.begin(), Holder.end());
        if (Holder.size() % 2 != 0)
        {
            ans = Holder[Holder.size() / 2];
        }
        else
        {
            ans = 0.5f * (Holder[Holder.size() / 2] + Holder[Holder.size() / 2 - 1]);
        }
        return ans;
    }
};