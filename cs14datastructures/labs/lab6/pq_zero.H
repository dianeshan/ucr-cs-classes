/**
 * Course: CS014 Summer 2020
 *
 * First Name: Diane
 * Last Name: Shan
 * Username: dshan017
 * email address: dshan017@ucr.edu
 *
 *
 * Assignment: lab6
 * Filename : pq_zero.H
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */

#include <iostream>
#include <map>
#include <vector>

using namespace std;

template <class Item>
class pq_zero
{
private:
    vector<Item> heap;         // The heap expands/shrinks to fit data
    typedef int indx;          // index with heap
    map<Item, indx> index;     // records each Item's place in heap
    map<Item, float> priority; // records each Item's priority
    void percolate_up(indx i)
    {
        if (parent(i) > -1 && priority[heap.at(parent(i))] > priority[heap.at(i)]) //if there is a parent and the parent has higher priority than at i, percolate up
        {
            swap(parent(i), i);
            percolate_up(parent(i));
        }
    }

    void percolate_down(indx i)
    {
        if (size() > left(i)) //check first if there is a left child, bc only after there is left child is it possible to have right child
        {
            indx small;
            if (size() > right(i)) //if there is a right child
            {
                small = minPriority(left(i), right(i)); //find the one with the lowest priority and set it to small
            }
            else
            {
                small = left(i); //otherwise small is the left child
            }
            if (i == minPriority(i, small)) //base case, if index is lower in priority than child lowest
            {
                return;
            }
            else //else recursive call
            {
                swap(i, small);        //swap the input index with the small index
                percolate_down(small); //precolate down
            }
        }
    }

    void swap(indx i, indx j)
    {
        Item temp = heap.at(i);
        heap.at(i) = heap.at(j);
        heap.at(j) = temp;
    }

    indx parent(indx i)
    {
        return (i - 1) / 2;
    }

    indx left(indx i)
    {
        return (2 * i) + 1;
    }

    indx right(indx i)
    {
        return (2 * i) + 2;
    }

    indx minPriority(indx i, indx j)
    {
        indx min;
        if (priority[heap.at(i)] < priority[heap.at(j)])
        {
            min = i;
        }
        else
        {
            min = j;
        }
        return min;
    }

public:
    // These use the min-heap functions above.
    int size() const
    {
        return heap.size();
    }

    bool empty() const
    {
        if (size() == 0)
        {
            return true;
        }
        return false;
    }

    const Item &front() const
    {
        if (empty())
        {
            throw underflow_error("Heap is empty!");
        }
        return heap.at(0);
    }

    void pop()
    {
        if (empty())
        {
            throw underflow_error("Heap is empty!");
        }
        swap(0, heap.size() - 1);
        priority.erase(heap.at(heap.size() - 1));
        index.erase(heap.at(heap.size() - 1));
        heap.pop_back();
        percolate_down(0);
        return;
    }

    void push(const Item &w, float prio)
    {
        for (unsigned int i = 0; i < heap.size(); i++)
        {
            if (heap.at(i) == w) //updates priority if already exists
            {
                priority[w] = prio;
                return;
            }
        }
        heap.push_back(w);
        priority[w] = prio;
        index[w] = heap.size() - 1;
        percolate_up(size() - 1);
        return;
    }

    void print()
    {
        for (unsigned int i = 0; i < heap.size(); ++i)
            cout << heap.at(i) << " ";
        cout << endl;
    }
};
