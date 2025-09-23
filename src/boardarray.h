#include <iostream>
#include "board.h"
#define SIZE 5
using namespace std;

class BoardArray : public Board {
    Entry* array;
    int index;

    public:
        BoardArray() {
            array = new Entry[SIZE];
            index = 0;
        }

        void add(Entry* entry) {
                        
         int pos = index;

    for (int i = 0; i < index; i++) {
        if (entry->compare(&array[i])) {
            pos = i;
            break;
        }
    }
    if (index == SIZE && pos == SIZE) {
    cout << entry->name << "'s score is too low to be added!" << endl;
    return;
    }
    if (index < SIZE) {
        index++;
    }
    for (int i = index - 1;i > pos;i--) {
        array[i] = array[i - 1];
    }
    array[pos] = *entry;
    return;
        }

        void print() {
            for (int i = 0; i < index; i++) {
                cout << i + 1 << ". ";
                array[i].print();
            }
        }
};