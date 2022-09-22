#include "stdafx.h"
#include "Text.h"

bool Text::fast_solw_pointer(ListNode *head) {
	if (head == NULL || head->next == NULL) {
		return true;
	}
	// ����ָ��
	ListNode *slow = head;
	ListNode *fast = head;
	while (fast->next != NULL && fast->next->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	// �е��벿������
	fast = slow->next;
	slow->next = NULL;
	ListNode *change = NULL;
	while (fast != NULL) {
		change = fast->next;
		fast->next = slow;
		slow = fast;
		fast = change;
	}
	// �����ж�
	change = slow;
	fast = head;
	bool res = true;
	while (slow != NULL && fast != NULL) {
		if (slow->val != fast->val) {
			res = false;
			return res;
		}
		slow = slow->next;
		fast = fast->next;
	}
	// �������ָ�
	slow = change->next;
	change->next = NULL;
	while (slow != NULL) {
		fast = slow->next;
		slow->next = change;
		change = slow;
		slow = fast;
	}
	return res;
}

/*// ������
Node* Text::copyListWithRand(Node *head) {
	unordered_map<Node*, Node*> *map = new unordered_map<Node*, Node*>();
	Node *p = head;
	while (p != NULL) {
		map->insert(p,new Node(p->val));
		p = p->next;
	}
	p = head;
	while (p != NULL) {
		map->find(p)->second->next = map->find(p->next)->second;
		map->find(p)->second->rand = map->find(p->rand)->second;
		p = p->next;
	}
	return map->find(head)->second;
}*/

ListNode* Text::getLoopNode(ListNode *head) {
	if (head == NULL || head->next == NULL || head->next->next == NULL) {
		return NULL;
	}
	ListNode *fast = head->next->next;
	ListNode *slow = head->next;
	while (fast->next != NULL || fast->next->next != NULL) {
		if (fast == slow) {
			return fast;
		}
		else {
			fast = fast->next->next;
			slow = slow->next;
		}
	}
	return NULL;
}

ListNode* Text::noLoop(ListNode* head1, ListNode *head2) {
	ListNode *curr1 = head1;
	ListNode *curr2 = head2;
	int n = 0;// n = �������� - ��������
	while (curr1->next != NULL) {
		n++;
		curr1 = curr1->next;
	}
	while (curr2->next != NULL) {
		n--;
		curr2 = curr2->next;
	}
	if (curr1 != curr2) {
		return NULL;
	}
	curr1 = n > 0 ? head1 : head2;
	curr2 = curr1 == head1 ? head2 : head1;
	n = abs(n);
	while (n != 0) {
		n--;
		curr1 = curr1->next;
	}
	while (curr1 != curr2) {
		curr1->next;
		curr2->next;
	}
	return curr1;
}

ListNode* Text::bothLoop(ListNode* head1, ListNode* loop1, ListNode* head2, ListNode* loop2) {

	return head1;
}

void Text::OrderRecur(TreeNode *head) {
	if (head == NULL) {
		return;
	}
	//����
	OrderRecur(head->left);
	//����
	OrderRecur(head->right);
	//����
}// �������ݹ����
void Text::preOrderUnRecur(TreeNode *head) {
	if (head != NULL) {
		stack<TreeNode*> stackk;
		stackk.push(head);
		while (!stackk.empty()) {
			head = stackk.top();
			cout << head->val << endl;
			if (head->right != NULL) {
				stackk.push(head->right);
			}
			if (head->left != NULL) {
				stackk.push(head->left);
			}
		}
	}
} // �������ǵݹ��������
void Text::inOrderUnRecur(TreeNode *head) {
} // �������ǵݹ��������
void Text::posOrderUnRecur(TreeNode *head) {
} // �������ǵݹ�������