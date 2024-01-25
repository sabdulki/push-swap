#include <stdio.h>
#include <stdlib.h>

// Функция для создания односвязного связанного списка определенной длины
t_dict* createLinkedList(int length) {
    if (length <= 0) {
        return NULL; // Некорректная длина списка
    }

    struct Node* head = NULL;
    struct Node* current = NULL;

    // Создаем голову списка
    head = (struct Node*)malloc(sizeof(struct Node));
    if (head == NULL) {
        perror("Unable to allocate memory for the linked list");
        exit(EXIT_FAILURE);
    }

    // Инициализируем данные и указатель на следующий узел
    head->data = 0; // Например, начнем с 0
    head->next = NULL;
    current = head;

    // Создаем остальные узлы списка
    for (int i = 1; i < length; ++i) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            perror("Unable to allocate memory for a new node");
            exit(EXIT_FAILURE);
        }

        // Инициализируем данные и указатель на следующий узел
        newNode->data = i;
        newNode->next = NULL;

        // Связываем текущий узел с новым
        current->next = newNode;
        current = newNode;
    }

    return head;
}

// Функция для печати списка
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Функция для освобождения памяти, выделенной под список
void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    // Задаем длину списка
    int length = 5;

    // Создаем односвязный связанный список
    struct Node* myList = createLinkedList(length);

    // Печатаем список
    printList(myList);

    // Освобождаем память, выделенную под список
    freeList(myList);

    return 0;
}
