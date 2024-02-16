#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	int count = 0;
    node * curr = head;

    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    return count;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
    int len = length(head);
    char* str = (char*)malloc((len) * sizeof(char));
    if (str == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    int index = 0;
    while (head != NULL) {
        str[index] = head->letter;
        head = head->next;
        index++;
    }
    str[index] = '\0'; 
    return str;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node* newNode = (node*)malloc(sizeof(node));
	if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->letter = c;
    newNode->next = NULL;
    node* current = *pHead;

    if (*pHead == NULL) {
        // If the list is empty, make the new node the head
        *pHead = newNode;
        return;
    }

    // Traverse the list to find the last node
    while (current->next != NULL) {
        current = current->next;
    }

    // Update the next pointer of the last node to point to the new node
    current->next = newNode;
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	node * curr = *pHead;
	node * nextt;

	while (curr != NULL) {
		nextt = curr->next;
		free(curr);
		curr = nextt;
	}

	*pHead = NULL;
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}