#include <stdio.h>
#include <stdlib.h>

struct ListNode {
      int val;
      struct ListNode *next;
};

struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Helper function to create a linked list from an array (digits in reverse order)
struct ListNode* createList(int* arr, int size) {
    if (size == 0) return NULL;
    struct ListNode* head = createNode(arr[0]);
    struct ListNode* curr = head;
    for (int i = 1; i < size; i++) {
        curr->next = createNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
    struct ListNode* dummy = createNode(0);
    struct ListNode* curr = dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum / 10;
        curr->next = createNode(sum % 10);
        curr = curr->next;
    }
    struct ListNode* result = dummy->next;
    free(dummy);
    return result;
}

void printList(struct ListNode* head) {
    while (head) {
        printf("%d", head->val);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Test case 1: (2 -> 4 -> 3) + (5 -> 6 -> 4) = 342 + 465 = 807 (7 -> 0 -> 8)
    int arr1[] = {2, 4, 3};
    int arr2[] = {5, 6, 4};
    struct ListNode* l1 = createList(arr1, 3);
    struct ListNode* l2 = createList(arr2, 3);

    printf("Input 1: ");
    printList(l1);
    printf("Input 2: ");
    printList(l2);

    struct ListNode* result = addTwoNumbers(l1, l2);
    printf("Result:  ");
    printList(result);

    // Test case 2: (0) + (0) = 0
    int arr3[] = {0};
    int arr4[] = {0};
    l1 = createList(arr3, 1);
    l2 = createList(arr4, 1);

    printf("\nInput 1: ");
    printList(l1);
    printf("Input 2: ");
    printList(l2);

    result = addTwoNumbers(l1, l2);
    printf("Result:  ");
    printList(result);

    // Test case 3: (9 -> 9 -> 9 -> 9 -> 9 -> 9 -> 9) + (9 -> 9 -> 9 -> 9) = 9999999 + 9999 = 10009998
    int arr5[] = {9,9,9,9,9,9,9};
    int arr6[] = {9,9,9,9};
    l1 = createList(arr5, 7);
    l2 = createList(arr6, 4);

    printf("\nInput 1: ");
    printList(l1);
    printf("Input 2: ");
    printList(l2);

    result = addTwoNumbers(l1, l2);
    printf("Result:  ");
    printList(result);

    return 0;
}