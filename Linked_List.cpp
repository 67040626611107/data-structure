#include <iostream>
#include <sstream>
#include <string>

using namespace std;
struct Node
{
    int id;
    Node* next;
    Node(int id) : id(id) , next(nullptr) {};
};

Node* head = nullptr;
string command;
string order;

int NewId;
int target;
class Linked_Implement
{
    public:
        void InsertBefore(int newid,int target) {
            Node* Newnode = new Node(newid);
            if (!head) {
                head = Newnode;
            } else if (head->id == target) {
                Newnode->next = head;
                head = Newnode;
            } else {
            }
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
            Linked.InsertBefore(NewId,target);
        }
    }
    return 0;
}
