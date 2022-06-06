
#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

int ope (int a, int b, int (*pf)(int, int)){
    int k = (*pf)(a,b);
    return k;
}
int add(int a , int b) {
    return a+b;
}
#include <string>

class Employee {
    public : 
    string name;
};

class Node {
    public : 
    Employee e;
    Node *next;

    Node(Employee e) {
        this->e = e;
        this->next = nullptr;
    }    
};

class LinkedList {

    Node *head;

    public :
    LinkedList(){
        this->head = nullptr;
    }

     void add(Employee e) {
        if(this->head ==nullptr) {
            Node * newNode = new Node(e);
            this->head = newNode;
        }
        else {
            Node *newNode = new Node(e);
            newNode->next = this->head;
            this->head = newNode;
        }
    }

     void traverse() {// traverse all node 
        Node *current = this->head;
        while(current != nullptr){
            cout << current->e.name << endl;
            current = current->next;
        }
    }
};

int main()
{
	Employee ram = Employee();
    ram.name = "ram";
    Employee tom = Employee();
    tom.name = "tom";
    Employee sam = Employee();
    sam.name = "sam";
    Employee dave = Employee();
    dave.name = "dave";
    Employee troy = Employee();
    troy.name = "troy";
    LinkedList l = LinkedList();
    l.add(ram);
    l.add(tom);
    l.add(sam);
    l.add(dave);
    l.add(troy);
    l.traverse();
    // didnt delete new operator was used to use delete 
	return 0;
}
