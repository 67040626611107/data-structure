#include <iostream>
#include <sstream>
#include <string>

using namespace std;
struct Node
{
    int id;
    Node* next;
    Node(int id) : id(id) , next(NULL) {};
};

string command;
string order;

int NewId;
int target;
class Linked_Implement
{
    private:
        Node* head = NULL;
    public:
        void print() {
            Node* current = head;
            // cout << " DATA :";
            while (current)
            {
                cout <<current->id;
                if (current->next) {
                    cout << " ";
                }
                current = current->next;
            }
            cout << endl;
        };
        int IsDuplicate(int newid) {
            Node* current = head;
            while (current)
            {
                if (current->id == newid) {
                    return 1;
                }
                current = current->next;
            }
            return 0;
        };
        void pushback(int newid) {
            Node* Newnode = new Node(newid);
            Node* current = head;
            while(current->next) {
                current = current->next;
            }
            current->next = Newnode;
        };
        void InsertBefore(int newid,int target) {
            Node* Newnode = new Node(newid);
            if (IsDuplicate(newid)) return;
            if (!head) {
                head = Newnode;
            } else if (head->id == target) {
                Newnode->next = head;
                head = Newnode;
            } else {
                Node* previous = NULL;
                Node* current = head;
                while (current && current->id !=  target)
                {
                    previous = current;
                    current =  current->next;
                }
                if (current) {
                    previous->next = Newnode;
                    Newnode->next = current;
                    // cout << "found" << endl;

                } else {
                    // cout << "Not found" << endl;
                    pushback(newid);
                }
            }
            print();
        };
        void InsertAfter(int newid,int target) {
            Node* Newnode = new Node(newid);
            if (IsDuplicate(newid)) return;
            if (!head) {

                head = Newnode;
            } else {
                Node* current = head;
                while (current && current->id !=  target)
                {
                    current =  current->next;
                }
                if (current) {
                    Newnode->next = current->next;
                    current->next = Newnode;
                } else {
                    // cout << "Not found" << endl;
                    pushback(newid);
                }
            }
            print();
        }
        void Delete(int target) {
            Node* current = head;
            Node* previous = NULL;
            if (head->id == target) {
                head = current->next;
                print();
                return;
            }
            while (current)
            {
                if (current->id == target) {
                        previous->next = current->next;
                    break;
                }
                previous = current;
                current = current->next;
            }
            print();
        }
};



int main() {
    Linked_Implement Linked;
    while (true) {
        getline(cin,command);
        if (command.empty()) continue;
        stringstream ss(command);
        ss >> order;
        if (order == "I") {
            ss>>NewId;
            ss>>target;
            // cout << "dsads" << endl;
            Linked.InsertBefore(NewId,target);
        }else if (order == "A") {
            ss>>NewId;
            ss>>target;
            // cout << "dsads" << endl;
            Linked.InsertAfter(NewId,target);
        } else if (order == "D") {
            ss>>NewId;
            Linked.Delete(NewId);
        }else if (order == "E") {
            break;
        }
    }
    return 0;
}



