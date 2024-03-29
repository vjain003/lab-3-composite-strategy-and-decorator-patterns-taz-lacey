#ifndef __STRATEGY_H__
#define __STRATEGY_H__
#include "component.h"
#include <iostream>
using namespace std;

class Sort;
class Container;


class Sort {
    public: 
        /* Constructors */
        Sort() { }

        /* Pure Virtual Functions */
        virtual void sort(Container* container) = 0;
};

class Container {
    protected: 
        Sort* sort_function;

    public: 
        /* Cosntructors */
        Container() : sort_function(NULL) { }
        Container(Sort* function); 

        /* Non Virtual Functions */
        // Set the type of sorting algorithm
        void set_sort_function(Sort* sort_function) {
            this->sort_function = sort_function;
        } 

        /* Pure Virtual Functions */
        // insert the top pointer of the tree into the container
        virtual void add_element(Base* element) = 0;
        // iterate through the trees and output values
        virtual void print() = 0;
        // calls on the previously set sorting-algorithm. 
        // Check if sort_function is not null, throw exception if is null
        virtual void sort() = 0;

        /* Essentially the only functions needed to sort */
        // switch tree locations
        virtual void swap(int i,int j) = 0;
        // get top pointer of tree at index i
        virtual Base* at(int i) = 0;
        // return container size;
        virtual int size() = 0;
};

class SelectionSort : public Sort {
    public:
        void sort(Container* cont) {
            for (int i = 0; i < cont->size(); ++i) {
                int min = i;
                for (int j = i + 1; j < cont->size(); ++j) {
                    if (cont->at(j)->evaluate() < cont->at(min)->evaluate()) {
                        min = j;
                    }
                }
                cont->swap(i, min);
            }
        }
};

class BubbleSort : public Sort {
    public:
        void sort(Container* cont) {
            for (int j = 1; j < cont->size(); ++j) {
                bool sorted = true;
                for (int i = 0; i < cont->size() - j; ++i) {
                    if (cont->at(i)->evaluate() > cont->at(i+1)->evaluate()) {
                        cont->swap(i, i+1);
                        sorted = false;
                    }
                }
                if (sorted == true) {
                    break;
                }
            }
        }
};

#endif // __STRATEGY_H__