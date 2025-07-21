#include <iostream>
#include "linkedlist.h"

struct Node
{
    int data;
    struct Node *next;

    // Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList
{
public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }
    void createNode(T value)
    void createNode(int value)
    {
        Node *temp = new Node;
        temp->next = nullptr;
        temp->data = value;

        if (head == nullptr)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    void pushNode(T value)
    void pushNode(int value)
    {
        Node *new_node;
        new_node = new Node;

        new_node->data = value;
        new_node->next = head;

        head = new_node;
    }
    void insertNodeAtPosition(int pos, T value)
    void insertNodeAtPosition(int pos, int value)
    {
        Node *pre = new Node;
        Node *current = new Node;
        Node *temp = new Node;
        current = head;

        for (int i = 1; i < pos; i++)
        {
            pre = current;
            current = current->next;
        }
        temp->data = value;
        pre->next = temp;
        temp->next = current;
    }

    int pop()
    {
        int retval = 0;
        Node *next_node = nullptr;

        next_node = head->next;
        retval = head->data;
        delete head;
        head = next_node;

        int retval;
    }

    int removeLast()
    {
        int retval = 0;
        /* if there is only one item in the list, remove it */
        if (head->next == nullptr)
        {
            retval = head->data;
            delete head;
            return retval;
        }

        /* get to the second to last node in the list */
        Node *current = head;
        while (current->next->next != nullptr)
        {
            current = current->next;
        }

        /* now current points to the second to last item of the list, so let's remove current->next */
        retval = current->next->data;
        delete current->next;
        current->next = nullptr;
        return retval;
    }

    int removeByIndex(int n)
    {
        int i = 0;
        int retval = -1;
        Node *current = head;
        Node *temp_node = nullptr;

        if (n == 0)
        {
            return pop(); //(head);
        }

        for (i = 0; i < n - 1; i++)
        {
            if (current->next == nullptr)
            {
                return -1;
            }
            current = current->next;
        }

        temp_node = current->next;
        retval = temp_node->data;
        current->next = temp_node->next;
        delete temp_node;

        return retval;
    }

    void printList()
    {
        Node *current = head;

        while (current != nullptr)
        {
            std::cout << current->data << std::endl;
            current = current->next;
        }
    }

private:
    Node *head;
    Node *tail;
};