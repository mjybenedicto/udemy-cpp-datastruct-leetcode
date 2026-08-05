#include <iostream>

using namespace std;

class Node {
    public:
        int value;
        Node* next;
        Node(int value) {
            this->value = value;
            next = nullptr;
        }
};

class LinkedList {
    private:
        Node* head;
        
    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
        }
        
        ~LinkedList() {
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
                cout << "empty";
            } else {
                while (temp != nullptr) {
                    cout << temp->value;
                    temp = temp->next;
                    if (temp != nullptr) {
                        cout << " -> ";
                    }
                }
            }
            cout << endl;
        }

        Node* getHead() {
            return head;
        }
        
        void makeEmpty() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = newNode;
            } else {
                Node* currentNode = head;
                while (currentNode->next != nullptr) {
                    currentNode = currentNode->next;
                }
                currentNode->next = newNode;
            }
        }

        //   +======================================================+
        //   |                 WRITE YOUR CODE HERE                 |
        //   | Description:                                         |
        //   | - Convert binary number in list to decimal           |
        //   | - Return type: int                                   |
        //   |                                                      |
        //   | Tips:                                                |
        //   | - Use a single pointer: 'current'                    |
        //   | - Initialize an integer 'num' to 0                   |
        //   | - Loop through the list                              |
        //   | - Use the formula: num = num * 2 + current->value    |
        //   | - Return 'num' as the decimal value                  |
        //   +======================================================+
        
        int binaryToDecimal(){
            Node* current = head;
            int num = 0;
            while(current != nullptr){
                num = num * 2 + current->value;
                current = current->next;
            }
            return num;
        }
        
};
