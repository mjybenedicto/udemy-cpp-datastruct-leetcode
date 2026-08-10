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
        Node* tail;
        int length;
    
    public:
        DoublyLinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
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
    
        Node* getTail() {
            return tail;
        }
    
        int getLength() {
            return length;
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (length == 0) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            length++;
        }

        void swapPairs(){
            if(length <= 1) return;
            
            Node* dummy = new Node(0);
            dummy->next = head;
            head->prev = dummy;
            
            Node* prev = dummy;
            Node* first = prev->next;
            
            while(first != nullptr && first->next != nullptr){
                Node* second = first->next;
                
                first->next = second->next;
                if(first->next){
                    first->next->prev = first;
                }
                
                second->next = first;
                first->prev = second;
                
                prev->next = second;
                second->prev = prev;
                
                prev = first;
                first = first->next;
            }
            
            head = dummy->next;
            delete dummy;
            
        }

};
