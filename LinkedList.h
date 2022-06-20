//
// Created by Nate Lampros on 10/1/21.
//

#ifndef INC_235LAB3_LINKEDLIST_H
#define INC_235LAB3_LINKEDLIST_H
#include "LinkedListInterface.h"
#include <iostream>
#include <fstream>

using namespace std;

template<typename T>
//class LinkedList{
class LinkedList : public LinkedListInterface<T>{

private:
    struct Node
    {
        T data;
        Node* next;
        Node(const T& d, Node* n) : data(d), next(n) {}
        ~Node() = default;
    };
    Node* head;

public:
    LinkedList() : head(NULL) {}
    ~LinkedList() {clear();}
    /** Copy Constructor */
    LinkedList<T>(const LinkedList<T>& copyList) : head(NULL) {
        // Copy (append) copyList to *this
        Node* cptr = copyList.head;
        Node** nptr = &head;			// point to head
        while (cptr != NULL) {
            // append next node to end of copyList
            *nptr = new Node(cptr->data, NULL);
            // update pointer to next of appended node
            nptr = &((*nptr)->next);
            cptr = cptr->next;
        }
    }

    LinkedList& operator=(const LinkedList& other){
        LinkedList<T> temp(other);
        std::swap(temp.head, head);
        return *this;
    }

    /** Insert Node(value) at beginning of linked list */
    void push_front(const T& value){
        head = new Node(value, head);
        return;
    }

    /** Remove Node at beginning of linked list */
    void pop_front(){
        if (head == NULL){
            return;
            //cout << "Empty!" << endl; ///WHY DOES IT NEED TO BE COUT??
        }
        else {
            Node* temp = head;
            head = head->next;

            delete temp;
        }
    }

    /** Return reference to value of Node at beginning of linked list */
    T& front(){
        return head->data; ///TODO IS THIS CORRECT
        ///return head;
    }

    /** Return true if linked list size == 0 */
    bool empty() const{
        if (head->next == NULL){
            return true;
        }
        else{
            return false;
        }
    }

    /** Remove all Nodes with value from linked list */
    void remove(const T& value){
        // Initialize current
        Node* current = head;
        Node* temp = head;

        while (current != NULL){
            if (current->data == value){
                if (current == head){
                    temp = current->next;
                    delete current;
                    current = temp;
                    head = current;
                }
                else {
                    temp->next = current->next;
                    delete current;
                    current = temp->next;
                }
            }
            else {
                temp = current;
                current = current->next;
            }
        }

//
//        if (head == NULL){
//            return;
//        }
//        else{
//            while (head->data == value){
//                head = head->next;
//            }
//            while (current->next != NULL){
//                if (current->next->data == value){
//                    current->next = current->next->next;
//                }
//                else{
//                    current = current->next;
//                }
//            }
//        }

//        return head;
    }

    /** Remove all Nodes from linked list */
    void clear(){

        while (head != NULL){
            Node* temp = head;
            head = temp->next;
            delete temp;
        }
        head = NULL;

//        // Initialize current
//        Node* current = head;
//        Node* temp = head;
//
//        while (current != NULL){
//            temp = current->next;
//            delete current;
//            current = temp;
//        }
//        head = NULL;
    }

    /** Reverse Nodes in linked list */
    void reverse(){
        // Initialize current, previous & next ptrs
        Node* current = head;
        Node *prev = NULL;
        Node *next = NULL;

        while (current != NULL) {
            // Store next
            next = current->next;
            // Reverse current node's pointer
            current->next = prev;
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
    }

    /** Return the number of nodes in the linked list */
    size_t size() const{
        // Initialize counter and current
        int counter = 0;
        Node* current = head;

        while (current != NULL){
            current = current->next;
            counter++;
        }
        return counter;
    }

    /** Return contents of Linked List as a string */
    std::string toString() const{
        Node* current = head;
        while (current != NULL){
//            os << current->data << (current->next != NULL ? " " : "");
//            current = current->next;
        }
    }

    /**Friend operator*/
    friend ostream& operator<<(ostream& os, LinkedList& ll)
    {
        Node* node_ptr = ll.head;
        while (node_ptr != NULL)
        {
            os << node_ptr->data << (node_ptr->next != NULL ? " " : "");
            node_ptr = node_ptr->next;
        }
        return os;
    }

    /** BONUS ** Insert Node(value) at end of linked list */
    //virtual void push_back(const T& value) = 0;

    /** BONUS ** Remove Node at end of linked list */
    //virtual void pop_back(void) = 0;

    /** BONUS ** Return reference to value of Node at end of linked list */
    //virtual T& back(void) = 0;
};
#endif //INC_235LAB3_LINKEDLIST_H
