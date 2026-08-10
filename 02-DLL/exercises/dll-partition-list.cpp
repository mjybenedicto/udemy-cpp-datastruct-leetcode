#include <iostream>

using namespace std;

class Node { 
    public: 
        int value;
        Node* next;
        Node* prev;
    
        Node(int value) {
            this->value = value;
            next = nullptr;
            prev = nullptr;
        }
};

class DoublyLinkedList {
    private:
        Node* head;
        int length;
    
    public:
        DoublyLinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            length = 1;
        }
    
        ~DoublyLinkedList() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }
    
        void printList() {
            Node* temp = head;
            if (temp == nullptr) {
                cout << "empty" << endl;
                return;
            }
            while (temp->next != nullptr) {
                cout << temp->value << " <-> ";
                temp = temp->next;
            }
            cout << temp->value << endl;
        }
    
        Node* getHead() {
            return head;
        }
    
        int getLength() {
            return length;
        }

        void makeEmpty() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
            length = 0;
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (length == 0) {
                head = newNode;
            } else {
                Node* temp = head;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = newNode;
                newNode->prev = temp;
            }
            length++;
        }
        
        void partitionList(int x) {
            if(head == nullptr) return;
            
            Node* d1 = new Node(0);
            Node* prev1 = d1;
            Node* d2 = new Node(0);
            Node* prev2 = d2;
            Node* current = head;
            
            while(current != nullptr){
                if(current->value < x){
                    prev1->next = current;
                    current->prev = prev1;
                    prev1 = prev1->next;
                }
                else {
                    prev2->next = current;
                    current->prev = prev2;
                    prev2 = prev2->next;
                }
                current = current->next;
            }
            
            prev2->next = nullptr;
            prev1->next = d2->next;
            if(d2->next != nullptr) d2->next->prev = prev1;
            head = d1->next;
        }
        
};
