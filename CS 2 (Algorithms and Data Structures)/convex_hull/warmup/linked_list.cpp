/**
 * @file
 * @author The CS2 TA Team
 * @version 1.0
 * @date 2013-2014
 * @copyright This code is in the public domain.
 *
 * @brief Example of a linked list class and usage.
 *
 */

 /**
  * Only the first node of the List is deleted, leaving all of the others.
  * This leaves a lot of memory still allocated, giving potential for the
  * program to run at unacceptably slow rates and for it to use increasingly
  * large amounts of memory.
  */

#include <iostream>
#include "looped_list.hpp"
#include "linked_list.hpp"

/**
 * List constructor.
 */
List::List()
{
    head = nullptr;
    num_elements = 0;
}

/**
 * List destructor.
 */
List::~List()
{
  cout << "Test" << endl;
    Node * temp = head, * temp_2 = nullptr;
    while(temp != nullptr)
    {
      temp_2 = temp->next;
      delete temp;
      temp = temp_2;
    }
}

/**
 * insert   Insert an integer at the end of the list.
 * @param   item integer to be inserted at the end of the list
 */
void List::insert(int item)
{
    // If we have elements...
    if (num_elements > 0)
    {
        // Set up a pointer to get to end of current list
        Node *temp = head;
        for (int i = 0; i < num_elements - 1; ++i)
        {
            temp = temp->next;
        }
        // temp now points to node at end of list

        // Construct our new node, it doesn't point to anything yet
        Node *new_node = new Node(item, nullptr);

        // Make the old tail point to the new tail
        temp->next = new_node;

        // and update the number of elements in the list
        num_elements++;
    }
    else
    {
        head = new Node(item, nullptr);
        num_elements++;
    }
    return;
}

/**
 * printList    Prints the contents of our list out, one integer per line.
 */
void List::printList()
{
    Node *temp = head;
    while (temp != nullptr)
    {
        std::cout << temp->data << std::endl;
        temp = temp->next;
    }
    return;
}


int main(int argc, char const *argv[])
{
    List * lst = new List();
    for (int i = 0; i < 10; ++i)
    {
        lst->insert(i);
    }
    if(is_looped(lst))
      cout << "This list is looped and cannot be printed!" << endl;
    else
    {
      cout << "This list is not looped!" << endl;
      lst->printList();
    }
    delete lst;
    return 0;
}
