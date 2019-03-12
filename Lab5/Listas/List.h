#ifndef LISTA_H
#define LISTA_H

template <typename Position, typename Data>
class List {
public:
    List();
    List(Position* N);
    List(const List& orig);
    virtual ~List();

    virtual void insert(Data* e, Position* k) = 0;
    virtual void insert(Data* e) = 0; // default insert
    virtual bool remove(Data* e) = 0; // by element
    virtual bool remove(Position* k) = 0; // by position
    virtual Position* find(Data* e) = 0;
    virtual Data* find(Position* k) = 0;
    virtual void sort() = 0; // some kind of sorting?
    virtual void print() = 0;
    virtual void emptyList() = 0;
    Data* getSize();

    virtual Position* next(Position* k) = 0;
    virtual Position* next(Data* e) = 0;

    virtual Position* prev(Position* k) = 0;
    virtual Position* prev(Data* e) = 0;

protected:
    Position* N;


};

#endif /* LISTA_H */
