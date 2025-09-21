#include <iostream>
#include <string>
using namespace std;

// nb changing int* data to char* data to allow printing of char array
void printArray(char* data, int size) {
    if (data != NULL && size > 0) {
        string result = "[";
        for (int count = 0; count < size; count++) {
            result += to_string(data[count]);
            if (count < size - 1) {
                result += ", ";
            }
        }
        result += "]";

        cout << result << endl;
    }
    else {
        cout << "Error - Invalid Array" << endl;
    }
}


bool bResizeArray(int*& pi, int& size, int sizeNew)
{
    // allocate new array
    int* piNew = NULL;
    if (sizeNew <= 0 || (piNew = new int[sizeNew]) == NULL)
        return false;   // resize fails

    // if expanding, initialise the new tail to zero
    if (sizeNew > size) {
        for (int i = 0; i < size; i++)
            piNew[i] = pi[i];
        for (int i = size; i < sizeNew; i++)
            piNew[i] = 0;
    }

    // if shrinking, erase the tail contents
    else {
        for (int i = 0; i < sizeNew; i++)
            piNew[i] = pi[i];
    }

    // delete old array
    delete[] pi;

    // point pi to the new array, and update size to sizeNew
    pi = piNew;
    size = sizeNew;

    // resize successful
    return true;
}



bool bAddArrays(char*& pchs, int& size, char* pchs2, int size2) {
    
    // adding size to determine new array size
    int newSize = size + size2;

    // creating new temporary array to hold values
    char* temp = new char[newSize];
    
    // adding first array to temporary array
    for (int i = 0; i < size; i++) {
        temp[i] = pchs[i];
    }   

    // adding second array to temporary array
    int count = 0;
    for (int i = size; i < newSize; i++ ) {
        temp[i] = pchs2[count];
        count++;
    }

    // delete old array
    delete[] pchs;

    // point pi to the new array, and update size to newSize
    pchs = temp;
    size = newSize;

    // addition successful
    return true;

}


int main() {

    // initial array
    int size = 10;
    char* pchs = new char[size];
    for (int i = 0; i < size; i++) {
        char ch = 97 + rand() % 26;
        pchs[i] = ch;
    }

    printArray(pchs, size);

    // second array
    int size2 = 6;
    char* pchs2 = new char[size2];
    for (int i = 0; i < size2; i++) {
        char ch = 97 + rand() % 26;
        pchs2[i] = ch;
    }

    printArray(pchs2, size2);



    // adding the arrays
    bAddArrays(pchs, size, pchs2, size2);
    // printing new array
    printArray(pchs, size);

    return 0;
}



/*
int main1()
{
    // initial array
    int size = 10;
    int* pi = new int[size];
    for (int i = 0; i < size; i++)
        pi[i] = i;

    printArray(pi, size);

    cout << endl;

    // expanding
    if (bResizeArray(pi, size, 20)) {
        printArray(pi, size);
        cout << endl;
    }

    // shrinking
    if (bResizeArray(pi, size, 5)) {
        printArray(pi, size);
        cout << endl;
    }

    // free array memory
    delete[] pi;

    return 0;
}
*/
