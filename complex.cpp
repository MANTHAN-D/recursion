#include "complex.h"
#include<stdlib.h>
#include<algorithm>
Complex :: Complex(){
    real = 0.0;
    imaginary = 0.0;
}

Complex :: Complex(float r, float i){
    real = r;
    imaginary = i;
}

float Complex::value(){
    return sqrt((real*real) + (imaginary*imaginary));
}

Complex* findLargestRecursively(Complex *cArray[], int low, int high){
    if(low == high){
        return cArray[low];
    }
    else{
        //Complex* current = cArray[low];
        Complex* temp = findLargestRecursively(cArray, low+1,high);
        if(*cArray[low] > *temp){
            return cArray[low];
        }
        else{
            return temp;
        }
    }
}

int main(){
    /**Create array of complex number **/
    Complex* cArray[20];

    for(int i=0;i<20;i++){
        cArray[i] = new Complex(rand() %20 + 1, rand()%20 + 1);
    }

    cout<<"<<<<< Print array non-recursively >>>>>"<<endl;
    for(int i=0;i<20;i++){
        cout << cArray[i] << " has value as :: "<< cArray[i]->value() << endl;
    }

    cout<<"<<<<< Largest complex number determined recursively >>>>>"<<endl;
    cout<< findLargestRecursively(cArray,0,19) << endl;
}
