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
        
        void reverseBetween(int startIndex, int endIndex) {
            if(head == nullptr || startIndex == endIndex) return;
            
            Node* dummy = new Node(0);
            dummy->next = head;
            head->prev = dummy;
            Node* prev = dummy;
            
            for(int i=0;i < startIndex;i++){
                prev = prev->next;
            }
            Node* current = prev->next;
            
            for(int i=0;i < endIndex-startIndex;i++){
                Node* temp = current->next;
                
                current->next = temp->next;
                if(current->next){
                    current->next->prev = current;
                }
                
                temp->next = prev->next;
                prev->next->prev = temp;
                
                prev->next = temp;
                temp->prev = prev;
            }
            
            head = dummy->next;
            delete dummy;
        }
        
};
