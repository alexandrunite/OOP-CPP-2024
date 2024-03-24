#ifndef PROIECT1_NODE
#define PROIECT1_NODE
#include <iostream>

class Node {
private:
    char info;
    Node* next;

public:
    // Constructor fara parametru
    Node(): info('\0'), next(nullptr) {}

    // Constructor cu parametru
    Node(char value): info(value), next(nullptr) {}

    // Constructor de copiere
    Node(const Node& other): info(other.info), next(other.next) {}

    // Destructor
    ~Node() 
    {
        //eventual
        // std::cout << "s-a apelat destructorul" << std::endl;
    }

    // Supraincarcarea operatorului =
    Node& operator=(const Node& other) 
    {
        if (this!=&other) {
            this->info=other.info;
            this->next=other.next;
        }
        return *this;
    }

    //Getteri si setteri
    char getInfo() const 
    {
        return this->info;
    }

    void setInfo(char value) 
    {
        this->info = value;
    }

    Node* getNext() const 
    {
        return this->next;
    }

    void setNext(Node* node) 
    {
        this->next = node;
    }

    friend class CircularList;
};

#endif // PROIECT1_NODE
