#include <iostream>

using namespace std;

struct Node{
        string data;
        Node* next;
    };
    Node* head = NULL;

    void addingword(string word){
        Node* newNode = new Node;
        newNode->data = word;
        newNode->next = NULL;

        if(head==NULL){
            head=newNode;
        }else{
            Node* temp=head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void undo(Node* head){
        if(head == NULL){
            cout << "Nothing to undo!" << endl;
            return;
        }
        if(head->next == NULL){
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    void display(Node* head){
        Node* temp = head;
        while(temp != NULL){
                cout << "[" << temp->data << "] ->";
        temp = temp->next;
        }
        cout << "NULL" << endl;
    }


int main()
{
    Node* head = NULL;
    string input;

    cout << "Simple Text Editor" << endl;

    while (true) {
        cout << "Enter word: ";
        cin >> input;

        if (input == "EXIT") {
            break;
        }
        else if (input == "UNDO") {
            undo(head);
        }
        else {
            addingword(head,input);
        }

        display();
    }
    return 0;
}
