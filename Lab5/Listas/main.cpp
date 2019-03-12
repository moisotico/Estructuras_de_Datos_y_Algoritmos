#include <cstdlib>
#include <iostream>

#include "List.h"
#include "ListWithArray.h"
using namespace std;

int main(int argc, char** argv) {

    ListWithArray<int>* l = new ListWithArray<int>();

    l -> insert(3,2);

    return 0;
}
