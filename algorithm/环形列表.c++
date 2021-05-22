/*
给定一个链表，判断链表中是否有环。
如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，
我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。
注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
如果链表中存在环，则返回 true 。 否则，返回 false 。
输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。

输入：head = [1,2], pos = 0
输出：true
解释：链表中有一个环，其尾部连接到第一个节点。

输入：head = [1], pos = -1
输出：false
解释：链表中没有环。
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
//第一种算法，set或者unordered_set算法

//    Definition for singly-linked list.
   struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        unordered_set<ListNode*> ans;
        while(head != NULL){
            if(ans.count(head)) return true;
            ans.insert(head);
            head = head->next;
        }
        return false;
    }
};

//第二种算法，龟兔赛跑算法
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return false;
        ListNode* fast = head;
        while(head != NULL && fast != NULL && fast->next != NULL){
            head = head->next;
            fast = fast->next->next;
            if(head == fast) return true;
        }
        return false;
    }
};
