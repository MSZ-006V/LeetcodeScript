/*
 * @lc app=leetcode id=385 lang=cpp
 *
 * [385] Mini Parser
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
    NestedInteger construct(string &s, int& i){
        NestedInteger res;
        int n = s.size();
        if(s[i] == '['){
            i++;
            while(i < n && s[i] != ']'){
                res.add(construct(s, i));
            }
            i++;
            if(i < n && s[i] == ',') i++;
        }
        else{
            string num="";
            while(i < n && s[i] != ',' && s[i] != ']'){
                num.push_back(s[i++]);
            }
            res.setInteger(stoi(num));
            if(i < n && s[i] == ',') i++;
        }
        return res;
    }
public:
    NestedInteger deserialize(string s) {
        NestedInteger res;
        int i = 0;
        res = construct(s, i);
        return res;
    }
};
// @lc code=end

