
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
// - supraincarcarea operatorului +, care sa efectueze concatenarea a doua liste circulare

#include "CircularList.h"

class CircularList {
private:
    Node* first;
public:
    //constructor fara parametri
    CircularList() : first(nullptr) {}

    //destructor
    ~CircularList() {
        if (this->first != nullptr)
        {
            Node* current=this->first->next;
            while (current!=this->first) {
                Node* next=current->next;
                delete current;
                current=next;
            }
            delete this->first;
            this->first=nullptr;
        }
    }
    void adaugareElementPePozitia(int position,char value) {
        Node* newNode=new Node(value);
        if (!this->first)
        { // Lista este goala
            this->first=newNode;
            this->first->setNext(this->first);
        }
        else
        {
            Node* current=this->first;
            for (int i = 0; current->getNext() != this->first && i< position-1; ++i)
            {
                current=current->getNext();
            }
            newNode->setNext(current->getNext());
            current->setNext(newNode);
            if (position==0) {
                this->first=newNode;
            }
        }
    }
    friend std::istream& operator>>(std::istream& is, CircularList& list)
    {
        char value;
        is>>value;
        list.adaugareElementPePozitia(0, value);
        return is;
    }
    void stergeElementulDePePozitia(int position)
    {
        if (this->first == nullptr) return; // Lista este goala
        Node* current=this->first;
        Node* prev=nullptr;
        if (position==0)
        {
            while (current->getNext()!=this->first)
            {
                current = current->getNext();
            }
            current->setNext(this->first->getNext());
            delete this->first;
            this->first = current->getNext();
        }
        else
        {
            for (int i = 0; current->getNext() != this->first && i < position; ++i)
            {
                prev=current;
                current=current->getNext();
            }
            if (current!=this->first)
            {
                prev->setNext(current->getNext());
                delete current;
            }
        }
    }
    void reverse()
    {
        if (!this->first||this->first->getNext()==this->first)
        {
            return; //Lista este goala sau are un singur nod
        }
        Node* prev=nullptr;
        Node* current=this->first;
        Node* head=this->first;
        do
        {
            Node* next=current->getNext();
            current->setNext(prev);
            prev=current;
            current=next;
        }while (current!=this->first);

        head->setNext(prev);
        this->first=prev;
    }

    CircularList operator+(const CircularList& other) const {
        CircularList newList;
        Node* current=this->first;
        if (current)
        {
            do
            {
                newList.adaugareElementPePozitia(newList.size(),current->getInfo());
                current=current->getNext();
            }while (current!=this->first);
        }

        current=other.first;
        if (current)
        {
            do
            {
                newList.adaugareElementPePozitia(newList.size(), current->getInfo());
                current = current->getNext();
            } while (current!=other.first);
        }
        return newList;
    }

    //Functie ajutatoare pentru determinarea dimensiunii listei
    int size() const
    {
        int count = 0;
        Node* current = this->first;
        if (current)
        {
            do
            {
                count++;
                current = current->getNext();
            }while(current != this->first);
        }
        return count;
    }

    //Supraincarcarea operatorului <<
    friend std::ostream& operator<<(std::ostream& os, const CircularList& list)
    {
        Node* current = list.first;
        if(current)
        {
            do
            {
                os<<current->getInfo() << " ";
                current=current->getNext();
            }while(current!=list.first);
        }
        return os;
    }
};

//Functie pentru citirea, memorarea si afisarea a n obiecte complete din clasa CircularList
void citireAfisareListeCirculare(int n)
{
    CircularList* lists=new CircularList[n];
    for(int i = 0;i<n;i++)
    {
        std::cout<<"elementele:";
        char value;
        while (std::cin >> value && value != '0')
        {
            lists[i].adaugareElementPePozitia(lists[i].size(), value);
        }
    }

    for (int i=0;i<n;i++)
    {
        std::cout<<lists[i]<<std::endl;
    }
    delete[] lists;
}


int main() {
    CircularList list1, list2;
    list1.adaugareElementPePozitia(0,'1');
    list1.adaugareElementPePozitia(1,'2');
    list1.adaugareElementPePozitia(2,'3');

    list2.adaugareElementPePozitia(0,'4');
    list2.adaugareElementPePozitia(1,'5');
    list2.adaugareElementPePozitia(2,'6');

    std::cout<<"Lista 1:"<<list1<<std::endl;
    std::cout<<"Lista 2:"<<list2<<std::endl;

    CircularList listaConcatenata=list1+list2;
    std::cout<<listaConcatenata<<std::endl;
    int n;
    std::cin >> n;
    citireAfisareListeCirculare(n);
    return 0;
}
