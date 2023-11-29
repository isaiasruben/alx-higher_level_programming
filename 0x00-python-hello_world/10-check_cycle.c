#!/usr/bin/python3
struct listint_t {
    int data;
    struct listint_t *next;
};

typedef struct listint_t listint_t;

int check_cycle(listint_t *list) {
    listint_t *slow = list;
    listint_t *fast = list;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        /* If there is a cycle, the pointers will eventually meet */
        if (slow == fast) {
            return 1;  // Cycle detected
        }
    }

    return 0;
}

int main() {
    // Create a linked list with a cycle for testing
    listint_t *head = malloc(sizeof(listint_t));
    listint_t *node1 = malloc(sizeof(listint_t));
    listint_t *node2 = malloc(sizeof(listint_t));
    listint_t *node3 = malloc(sizeof(listint_t));

    head->data = 1;
    head->next = node1;
    node1->data = 2;
    node1->next = node2;
    node2->data = 3;
    node2->next = node3;
    node3->data = 4;
    node3->next = node1;  // Cycle

    if (check_cycle(head)) {
        printf("There is a cycle in the linked list.\n");
    } else {
        printf("There is no cycle in the linked list.\n");
    }

    free(head);
    free(node1);
    free(node2);
    free(node3);

    return 0;
}
