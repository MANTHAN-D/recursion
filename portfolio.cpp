#include<iostream>
#include<fstream>
#include<sstream>
#include<stdlib.h>
#include "portfolio.h"

Portfolio :: Portfolio(){
    head = NULL;
};
Portfolio :: Portfolio(Stock* s){
    head = s;
};
void Portfolio :: setHead(Stock *h){
    head = h;
};

Stock* Portfolio :: getHead(){
    return head;
};

Stock* Portfolio :: load(string fileName){
    Stock* s = NULL;
    ifstream infile;
    string line,symbol,skip;
    float cost;
    int numberOfShares;

    infile.open(fileName.c_str());

    while(getline(infile,line)){
        istringstream iss(line);

        if(line.length() <= 0){
            break;
        }
        //skips
        getline(iss,skip,' ');
        getline(iss,symbol,',');/**Symbol captured*/

        //skips
        getline(iss,skip,':');
        getline(iss,skip,' ');
        getline(iss,skip,',');/**Cost captured*/

        /**parse the cost*/
        cost = atof(skip.c_str());

        //skips
        getline(iss,skip,':');
        getline(iss,skip,' ');
        getline(iss,skip);/**Number of shares captured*/

        /**parse the number of shares*/
        numberOfShares = atoi(skip.c_str());
        s = new Stock(symbol,cost,numberOfShares);
        insertAtEnd(s);
    }
    infile.close();
    return s;
};
void Portfolio :: store(string fileName, Portfolio* p){

    ofstream outfile;
    outfile.open(fileName.c_str());

    outfile << p;

    outfile.close();

};
void Portfolio :: insertAtStart(Stock* s){
    if(head == NULL){
        head = s;
    }
    else{
        s->setNext(head);
        head = s;
    }
};
void Portfolio :: insertAtMiddle(Stock* s){
    if(head == NULL){
        head = s;
        head->setNext(NULL);
    }
    else{
        Stock* p1 = head;
        Stock* p2 = head->getNext();
        while(p2 && p2->getNext()){
            p1 = p1->getNext();
            p2 = p2->getNext()->getNext();
        }
        //p1 would be middle node now
        s->setNext(p1->getNext());
        p1->setNext(s);
    }
};
void Portfolio :: insertAtEnd(Stock* s){
    if(head == NULL){
        head = s;
    }
    else{
        Stock* temp = head;
        while(temp->getNext() != NULL){
            temp = temp->getNext();
        }

        temp->setNext(s);
        s->setNext(NULL);
    }
};

void Portfolio :: reversePrint(Stock* s){

    if(s==NULL){
        return;
    }
    else if(s->getNext() == NULL){
        cout<< s << endl;
    }
    else{
        reversePrint(s->getNext());
        cout<< s << endl;
    }
};

//int main(){
//
//    Stock* s1 = new Stock("A1",34.67,5);
//    Stock* s2 = new Stock("A2",29.60,15);
//    Stock* s3 = new Stock("A3",12.56,50);
//    Stock* s4 = new Stock("A4",87.12,25);
//    Stock* s5 = new Stock("A5",110.00,54);
//    Stock* s6 = new Stock("A6",77.13,35);
//
//    Portfolio *p = new Portfolio(s1);
//    Portfolio *pFromFile = new Portfolio();
//
//    /**Initial Portfolio */
//    cout<< "<<<<<< Initial Portfolio >>>>>>" << endl;
//    cout << p << endl;
//
//
//    /**Test case 1 : Insert at beginning*/
//    p->insertAtStart(s2);
//    cout<< "<<<<<< Portfolio after insertion at beginning >>>>>>" << endl;
//    cout << p << endl;
//
//
//
//    /**Test case 2 : Insert in middle with even number of nodes */
//    p->insertAtMiddle(s3);
//    cout<< "<<<<<< Portfolio after insertion in middle >>>>>>" << endl;
//    cout << p << endl;
//
//    p->insertAtEnd(s4);
//
//    /**Test case 3 : Insert at end*/
//    p->insertAtEnd(s5);
//    cout<< "<<<<<< Portfolio after insertion at end >>>>>>" << endl;
//    cout << p << endl;
//
//    /**Test case 4 : Insert in middle with odd number of nodes */
//    p->insertAtMiddle(s6);
//    cout<< "<<<<<< Portfolio after insertion in middle >>>>>>" << endl;
//    cout << p << endl;
//
//    /**Test case 5 : Store the results to file */
//    //p->store("dlltest.txt",p); /**Comment this code after running program for first time to avoid file recreation **/
//
//    /**Test case 6 : Load the stocks from the file */
//    pFromFile->load("dlltest.txt");
//
//    /**Test case 7 :  Printing portfolio read from file */
//    cout<< "<<<<<< Portfolio after reading from file >>>>>>" << endl;
//    cout << pFromFile << endl;
//
//    /**Test case 8 :  Printing reverse portfolio using recursion */
//    cout<< "<<<<<< Reading Portfolio recursively in reverse order >>>>>>" << endl;
//    p->reversePrint(p->getHead());
//}

