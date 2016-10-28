/***Single linked list maintaining stocks***/
#include "stock.h"
#include<iostream>
using namespace std;

class Portfolio{
private:
    Stock* head;
public:
    Portfolio();
    Portfolio(Stock* s);
    Stock* getHead();
    void setHead(Stock *h);
    Stock* load(string fileName);
    void store(string fileName, Portfolio* p);
    void insertAtStart(Stock* s);
    void insertAtMiddle(Stock* s);
    void insertAtEnd(Stock* s);
    void reversePrint(Stock* s);

    friend ostream &operator<<( ostream &output, const Portfolio *P )
    {
        Stock* temp = P->head;
        while(temp != NULL){
            output << temp;
            temp = temp->getNext();
        }
        output << endl;
        return output;
    }
};
