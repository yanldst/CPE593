/*
 * Title： DoubleLinkedList
 * Author: Lei Yan
 *
 */

#include<fstream>
#include<sstream>
#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

class DoubleLinkedList {
private:
    class Node {
    public:
        int value;
        Node * next;
        Node * prev;
        Node(Node * p, int v, Node * n) {
            value = v;
            next = n;
            prev = p;
        }
    };
    Node * head;
    Node * tail;
public:
    DoubleLinkedList() {
        head = tail = nullptr;
    }

    ~DoubleLinkedList() {
        Node * temp;
        for (temp = head->next; temp != nullptr; temp = temp->next) {
            delete temp->prev;
        }
    }

    void ADD_BACK(int v) {
        if (head == nullptr) {
            head = tail = new Node(nullptr, v, nullptr);
        }
        else {
            tail->next = new Node(tail, v, nullptr);
            tail = tail->next;
        }
    }

    void ADD_FRONT(int v) {
        if (head == nullptr) {
            head = tail = new Node(nullptr, v, nullptr);
        }
        else {
            head->prev = new Node(nullptr, v, head);
            head = head->prev;
        }
    }

    void REMOVE_FRONT() {
        if(head == nullptr){
            return;
        }
        Node * temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }

    void REMOVE_BACK() {
        if(head == nullptr){
            return;
        }
        Node * temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }

    friend ostream& operator << (ostream& s, const DoubleLinkedList& list) {
        Node * temp;
        for (temp = list.head; temp != nullptr; temp = temp->next) {
            s << temp->value << " ";
        }
        return s;
    }
};

int main() {
    DoubleLinkedList a;

    string linetemp, choice;
    int input, i;

    ifstream in;
    in.open("C:\\Users\\Lei\\Desktop\\HW4b.txt");

    if (in.good()) {
        while (getline(in, linetemp)) {
            istringstream line(linetemp);
            line >> choice;

            if (choice == "ADD_FRONT") {
                string stringLength, tempString;
                stringLength = linetemp.substr(linetemp.find(" ")+1);
                //store inputing integers to be string, used to reverse the order of inputing numbers
                for(int i=stringLength.length()-1; i>=0; i--){
                    if(stringLength[i]==' '){
                          continue;
                    } else{
                    tempString = stringLength[i];
                    input = atoi(tempString.c_str());
                    a.ADD_FRONT(input);
                    continue;
                    }
                }

            }

            else if (choice ==  "ADD_BACK") {
                while (line >> input) {
                    a.ADD_BACK(input);
                }
            }
            else if (choice == "REMOVE_FRONT") {
                line >> input;
                for (i = 0; i < input; ++i) {
                    a.REMOVE_FRONT();
                }
            }
            else if (choice == "REMOVE_BACK") {
                line >> input;
                for (i = 0; i < input; ++i) {
                    a.REMOVE_BACK();
                }
            }
            else if (choice == "OUTPUT") {
                cout << a << endl;
            }
            else {
                cout << "BAD INPUT";
                break;
            }
        }
    }
    else
    {
        cerr << "File open failed!" << endl;
    }
}
