/**
 * Medium
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
 * 
 
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3

注意：直接移除节点，不在保留其一

 */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* deleteDuplicates(struct ListNode* head){
	if (head == NULL || head->next == NULL)
	{
		return head;
	}

	struct ListNode *result_head = NULL;
	struct ListNode *current = NULL;
	struct ListNode *p = head;
	struct ListNode *q = head->next;
	while (q != NULL) {
		if (p->val == q->val) {
			q = q->next;
		} else {
			if (p->next != q)
			{
				p = q;
				q = q->next;
			} else {
                if (current != NULL) {
                    current->next = p;
                }
                current = p;
				if (result_head == NULL)
				{
					result_head = p;
				}
				p = q;
				q = q->next;
			}
		}
	}

    // 处理最后剩下的部分，分两种情况，一种是多个相同节点，这种情况只判断p和p->next即可；
    // 另一种情况是只有p一个节点，p->next == NULL，直接追加即可；
	if (q == NULL) {
        if (p != NULL && p->next != NULL && p->next->val == p->val) {
            if(current == NULL) {
                return NULL;	// [1,1]
            } else {
                current->next = NULL;
            }
        } else if (p != NULL && p->next == NULL) {
            if(current == NULL) {
                return p;
            } else {
                current->next = p;
            }
        }
	}

	return result_head;
}
