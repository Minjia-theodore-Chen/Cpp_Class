
#pragma once
#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

#define Log(x) std::cout << x << std::endl;

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

class Longest_Palindromic_Substring
{
    int n;

public:
    int longestLength(std::string &s, int left, int right)
    {
        while (left >= 0 && right <= n)
        {
            if (s[left] != s[right])
                break; // exits when the two pointers are already two characters too wide apart
            left--;
            right++;
        }
        return right - left - 1;
    };
    std::string longestPalindrome(std::string s)
    {
        n = s.size();
        int start = 0, end = 0;
        for (int i = 0; i < n; i++)
        {
            int x = longestLength(s, i, i);
            int y = longestLength(s, i, i + 1);
            int len = std::max(x, y);

            if (len > end - start + 1)
            {
                start = i - ((len - 1) / 2);
                end = i + (len / 2);
            }
        }
        return s.substr(start, end - start + 1);
    }
};

class Zigzag_Conversion
{
public:
    std::string convert(std::string s, int numRows)
    {
        std::string ans;
        std::vector<std::string> tmp(numRows);
        int i = 0, n = s.size();
        while (i < n)
        {
            for (int j = 0; j < numRows && i < n; j++, i++)
            {
                tmp[j] += s[i];
            }
            for (int j = numRows - 2; j > 0 && i < n; j--, i++)
            {
                tmp[j] += s[i];
            }
        }
        for (int j = 0; j < numRows; j++)
        {
            ans += tmp[j];
        }

        return ans;
    };
};

class Reverse_Interger
{
public:
    int reverse(int x)
    {
        int y = 0;
        while (x)
        {
            if (y > INT_MAX / 10 || y < INT_MIN / 10)
            {
                return 0;
            }
            else
            {
                y = y * 10 + x % 10;
                x = x / 10;
            }
        }
        return y;
    }

    int reverse_alt(int x)
    {
        int ans = 0;
        while (x && x <= INT_MAX && x >= INT_MIN)
        {
            std::string holder = std::to_string(x);
            std::reverse(holder.begin(), holder.end());

            try
            {
                ans = std::stoi(holder);
            }
            catch (const std::exception &e)
            {
                return 0;
            }

            return (x > 0) ? ans : -ans;
        }
        return ans;
    }
};

class String_to_Integer
{
    bool isDigit(char ch)
    {
        return ch >= '0' && ch <= '9';
    }

public:
    int myAtoi(std::string s)
    {
        const int len = s.size();
        if (len == 0)
        {
            return 0;
        }
        int index = 0;
        while ((index < len) && (s[index] == ' '))
        {
            ++index;
        }

        if (index == len)
        {
            return 0;
        }

        char ch;
        bool Neg = (ch = s[index]) == '-';
        if (Neg || ch == '+')
        {
            ++index;
        }

        const int maxLimit = INT_MAX / 10;
        int result = 0;
        while (index < len && isDigit(ch = s[index]))
        {
            int digit = ch - '0';
            if (result > maxLimit || (result == maxLimit && digit > 7))
            {
                return Neg ? INT_MIN : INT_MAX;
            }

            result = (result * 10) + digit;
            ++index;
        }
        return Neg ? -result : result;
    }
};