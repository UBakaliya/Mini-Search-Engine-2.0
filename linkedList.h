/**
 * @file linkedList.h
 * @author Uvaish Bakaliya
 * @brief This the class implementation of the linked list class
 * @date 2022-12-09
 * @copyright Copyright © 2022 UB
 * @note Feel free to use it/edit it.
 */

#pragma once
#include <ostream>
template <typename LLT>
class LinkedList
{
private:
    struct Node
    {
        LLT data;
        Node *next;
    };
    Node *head;
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
    LinkedList() { this->head = nullptr; }
    ~LinkedList() { freeMemory(); }
    // NOTE: The insertion will be in 'descending' order
    void insert(LLT val);
    // checks the value exists inside of the list
    bool contains(LLT val);
    void clear() { freeMemory(); }
    // Use full for testing
    void dump(ostream &output);
};
