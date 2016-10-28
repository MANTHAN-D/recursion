#include "stock.h"
using namespace std;


Stock :: Stock(){
    symbol = "";
    cost=0.0;
    numberOfShares = 0;
    next = NULL;
}
Stock :: Stock(string s, float c, int n){
    symbol = s;
    cost=c;
    numberOfShares = n;
    next = NULL;
}

void Stock::setNext(Stock* n){
    next = n;
}

Stock* Stock::getNext(){
    return next;
}

