/**
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/
 *
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

	struct ListNode *cur_node = head;
	struct ListNode *prev_node = cur_node;

	while (cur_node) {
		if (cur_node->next == NULL)
		{
			prev_node->next = NULL;
		}

		if (prev_node->val != cur_node->val)
		{
			prev_node->next = cur_node;
			prev_node = cur_node;
		}
		cur_node = cur_node->next;
	}

	return head;
}

