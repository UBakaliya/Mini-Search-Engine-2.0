/**
 * @file linkedList.h
 * @author Uvaish Bakaliya
 * @brief This the class implementation of the linked list class.
    The class operations' time complexity will be O(N).
    You may be thinking that we can use another data structure to achieve a
    better time complexity, but in order to fully comprehend the linked list
    data structure, we must make a compromise.
 * @date 2022-12-09
 * @copyright Copyright © 2022 UB
 * @note Feel free to use edit how every you please.
 */

#pragma once

#include <iostream>
#include <ostream>

template <typename LLT>
class LinkedList
{
private:
    struct Node
    {
        LLT value;
        Node *next;
    };
    Node *head;
    size_t size;
    // freeing the memory like a good programme
    void freeMemory()
    {
        // freeing the memory like a good programmer
        while (head != nullptr)
        {
            this->head = this->head->next;
            delete this->head;
        }
    }

public:
    LinkedList()
    {
        this->head = nullptr;
        this->size = 0;
    }

    ~LinkedList() { freeMemory(); }

    size_t listSize() { return this->size; }

    // insertion will be in 'descending' order
    void insert(LLT value)
    {
        // Create the new node
        Node *newNode = new Node;
        newNode->value = value;
        newNode->next = nullptr;

        // If the linked list is empty, insert the new node at the beginning
        if (this->head == nullptr)
        {
            this->head = newNode;
            return;
        }

        // Traverse the linked list to find the first node with a value smaller
        // than the new node
        Node *curr = this->head;
        while (curr->next != nullptr && curr->next->value > value)
            curr = curr->next;

        // If the value of the next node is the same as the new node's value,
        // don't insert the new node
        if (curr->next != nullptr && curr->next->value == value)
            return;

        // Insert the new node after the found node
        newNode->next = curr->next;
        curr->next = newNode;
    }

    // checks the value exists inside of the list
    bool contains(LLT value)
    {
        // Traverse the linked list
        Node *curr = head;
        while (curr != nullptr)
        {
            // If the curr node's value is the value we are searching for,
            // return true
            if (curr->value == value)
                return true;
            // Move to the next node
            curr = curr->next;
        }
        // If we reach the end of the linked list, the value is not present,
        // so return false
        return false;
    }

    void clear() { freeMemory(); }

    // Use full for testing
    void dump(std::ostream &ouput)
    {
        Node *curr = head;
        while (curr != nullptr)
        {
            ouput << curr->value << "->";
            curr = curr->next;
        }
    }
};
