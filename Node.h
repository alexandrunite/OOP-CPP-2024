#ifndef PROIECT1_NODE
#define PROIECT1_NODE
#include <iostream>


// - Se cere implementarea unei structuri de tip lista. Pentru acest scop, se va crea clasa:
// class Node cu membrii privati:
// - info: char – caracterul de o pozitie din stiva
// - next: Node* – pointer catre urmatorul nod din lista
// Pentru clasa Node se cer constructori de initializare (cu si fara parametri), constructor de copiere,
// destructor si supraincarcarea operatorului =, precum si getteri si setteri.
// - Clasa CircularList are ca mebru privat:
// - first: Node * - nodul care este considerat a fi primul
// Functionalitati:
// - metoda publica de adaugare a unui element pe o poziție
// - supraincarcare a operatorului >>, realizata prin utilizarea succesiva a metodei decarata anterior
// - metoda publica de stergere a unui element de pe o poziție
// - metoda publica pentru inversarea legaturilor listei
// - supraincarcarea operatorului +, care sa efectueze concatenarea a doua liste circulare, rezultand într-o
// noua lista circulara (ca în exemplul de mai jos)
// Lista_circulara L1 = { 1 → 2 → 3 → 1} , L2 = {4 → 5 → 6 → 4} L1 + L2 = { 1 → 2 → 3 → 4 → 5
// → 6 → 1}
// implementare in C++ folosind clase
// • datele membre private
// • constructori de initializare (cu si fara parametri), constructor de copiere, destructor
// • supraincarcarea operatorului =
// • getteri si setteri pentru toate datele membre sau argumentare (intr-un comentariu) de ce nu ar
// avea sens
// • supraincarcarea operatorilor se poate face ca metode sau ca functii prieten
// • supraincarcarea operatorilor << si >> pentru citire si afisare
// • alocare dinamica pentru tablouri unidimensionale, matrici, liste, etc.
// • functie (nu metoda) pentru citirea, memorarea si afisarea a n obiecte complete din clasa din
// subiect
// • toate conceptele trebuie utilizate/testate
// • numele claselor, membrilor si metodelor trebuie sa fie sugestive
// • programul sa nu contina erori de compilare
class Node{
    private:
        char info;
        Node* next;
        //declarare variabile necesare
    public:
    Node(): info('\0'), next(nullptr){}
    //constructor fara parametru
    Node(char value): info(value), next(nullptr){}
    //constructor cu parametru
    Node(const Node& other): info(other.info), next(other.next){}
    //constructor de copiere
    ~Node();
    //destructor
    Node& operator=(const Node& other){
        if (this != &other){
            info= other.info;
            next= other.next;
        }
        return *this;
    }
    char getInfo() const{
        return info;
    }
    void setInfo(char value){
        info = value;
    }
    Node* getNext() const{
        return next;
    }
    void setNext(Node* node){
        next=node;
    }
};

#endif