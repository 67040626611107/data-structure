#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct Node
{
    int value;
    string key;
    int idx;
    Node* next;
    Node(int value,string key,int idx) : value(value), next(NULL), key(key), idx(idx) {};
};

class hash_tbl_im {
    public:
        int head;
        Node* node = NULL;
        hash_tbl_im(int h) {
            head = h;
        }
        void add_modulo(int key ,string data) {
            Node* now = new Node(key,data,key%head);
            if (!node) {
                node = now;
                return; 
            }
            Node* current = node;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = now;
        };
        void printAll() {
            for (int i = 0; i < head;i++) {
                int found = 0;
                Node* current = node;
                while (current != NULL) {
                    if (current->idx == i) {
                        cout << "(" << current->value << "," << current->key << ")";
                        found++;
                    }
                    current = current->next;
                } 
                if (!found) {
                    cout << "(-1,-)";
                }
                cout << endl;
            }
        }
        void search(int values) {
            Node* current = node;
            int found = 0;
            while (current != NULL) {
                if (current->value == values) {
                    found++;
                    cout << current->key;
                    break;
                }
                current = current->next;
            }
            if (!found) {
                cout << "-";
            }
            cout << endl;
        }
};

int main() {
    string command;
    int value;
    string key;
        hash_tbl_im* my_hash_tbl = new hash_tbl_im(17);    
        while (true) {
        cin >> command;
        if (command == "a") {
            cin >> value;
            cin >> key;
            my_hash_tbl->add_modulo(value,key);
        } else if (command == "p"){
            my_hash_tbl->printAll();
        } else if (command == "s") {
            cin >> value;
            my_hash_tbl->search(value);
        }
        else{
            break;
        }
    }
    return (0);
}