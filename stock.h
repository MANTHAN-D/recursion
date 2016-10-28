/** Stocks as single linked list node **/
#include <iostream>
#include<string>
using namespace std;
class Stock{
private:
    string symbol;
    float cost;
    int numberOfShares;
    Stock* next;
public:
    Stock();
    Stock(string,float,int);
    void setNext(Stock*);
    Stock* getNext();
    friend istream &operator>>( istream  &input, Stock &S )
    {
        input >> S.symbol >> S.cost >> S.numberOfShares;
        return input;
    }
    friend ostream &operator<<( ostream &output, const Stock *S )
    {
        output << "Symbol: " << S->symbol << ", Cost: " << S->cost << ", No of Shares: " << S->numberOfShares << endl;
        return output;
    }

};

