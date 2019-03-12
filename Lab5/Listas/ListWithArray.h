#ifndef LISTWITHARRAY_H
#define LISTWITHARRAY_H
#include "List.h"

#include <iostream>

using namespace std;

template <class Data>
 class ListWithArray : public List <int, Data> {
public:

    ListWithArray();
    ListWithArray(int N);
    ListWithArray(const ListWithArray& orig);
    virtual ~ListWithArray();


    void insert(Data e, int k);
    void insert(Data* e); // default insert
    bool remove(Data* e); // by element
    bool remove(int k); // by position
    int find(Data* e);
    Data* find(int k);
    void sort(); // some kind of sorting?
    void print();
    void emptyList();
    int getSize();

    int next(int k);
    int next(Data* e);

    int prev(int k);
    int prev(Data* e);
private:
    Data* data;
    int arraySize;

};

#endif /* LISTWITHARRAY_H */
