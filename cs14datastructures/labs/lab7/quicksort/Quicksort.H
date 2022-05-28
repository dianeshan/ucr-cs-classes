/**
 * Course: CS014 Summer 2020
 *
 * First Name: Diane
 * Last Name: Shan
 * Username: dshan017
 * email address: dshan017@ucr.edu
 *
 *
 * Assignment: lab7
 * Filename : Quicksort.H
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

string random(const vector<string> &v, int k)
{
    int i = rand() % k;
    string median = v.at(i);
    return median;
}

string median_three(const vector<string> &v, int i, int k)
{
    if (v.size() == 0)
    {
        return "Vector is empty!";
    }
    string start = v.at(rand() % k);
    string end = v.at(rand() % k);
    string mid = v.at(rand() % k);
    string median;

    if ((start < end && start > mid) || (start > end && start < mid))
    {
        median = start;
    }
    else if ((end < start && end > mid) || (end > start && end < mid))
    {
        median = end;
    }
    else
    {
        median = mid;
    }
    return median;
}

void InsertionSort(vector<string> &v)
{
    for (int i = 1; i < v.size(); i++)
    {
        int j = i;
        while (j > 0 && v.at(j) < v.at(j - 1))
        {
            string temp = v.at(j);
            v.at(j) = v.at(j - 1);
            v.at(j - 1) = temp;
            j--;
        }
    }
}

int partitionm(vector<string> &v, int i, int k, string pivot)
{
    bool done = false;

    int l = i; //initialize low index with i (0)
    int h = k; //initialize high index with k (v.size() - 1)

    pivot = median_three(v, i, k);

    while (!done)
    {
        while (v.at(l) < pivot) //increment l while pivot > v.at(l)
        {
            ++l;
        }
        while (pivot < v.at(h)) //decrement h while pivot < v.at(h)
        {
            --h;
        }
        if (l >= h)
        {
            done = true;
        }
        else
        {
            string temp = v.at(l);
            v.at(l) = v.at(h);
            v.at(h) = temp;

            ++l;
            --h;
        }
    }

    return h;
}

int partitionr(vector<string> &v, int i, int k, string pivot)
{
    bool done = false;

    int l = i; //initialize low index with i (0)
    int h = k; //initialize high index with k (v.size() - 1)

    pivot = random(v, k);

    while (!done)
    {
        while (v.at(l) < pivot) //increment l while pivot > v.at(l)
        {
            ++l;
        }
        while (pivot < v.at(h)) //decrement h while pivot < v.at(h)
        {
            --h;
        }
        if (l >= h)
        {
            done = true;
        }
        else
        {
            string temp = v.at(l);
            v.at(l) = v.at(h);
            v.at(h) = temp;

            ++l;
            --h;
        }
    }

    return h;
}

void QuicksortMed(vector<string> &v, int i, int k, string pivot)
{
    int j = 0;
    //base case, if 1 or zero elements to sort
    if (i >= k)
    {
        return;
    }
    j = partitionm(v, i, k, pivot); //after partitioning, j is highest index of low partition
    // vector<string> v2;

    // vector<string> v3;
    QuicksortMed(v, i, j, pivot);     //recursively sort lower partition up to j
    QuicksortMed(v, j + 1, k, pivot); //recursively sort higher partition up to k starting from j + 1
}

void QuicksortRand(vector<string> &v, int i, int k, string pivot)
{
    int j = 0;
    //base case, if 1 or zero elements to sort
    if (i >= k)
    {
        return;
    }
    j = partitionr(v, i, k, pivot); //after partitioning, j is highest index of low partition
    // vector<string> v2;

    // vector<string> v3;
    QuicksortRand(v, i, j, pivot);     //recursively sort lower partition up to j
    QuicksortRand(v, j + 1, k, pivot); //recursively sort higher partition up to k starting from j + 1
}

void QuickSortRand(vector<string> &v, string pivot)
{
    if (v.size() <= 1)
    {
        cout << "Sorted!" << endl;
        return;
    }
    else
    {
        if (v.size() <= 5) //use insertion sort if size is less than 5
        {
            InsertionSort(v);
            return;
        }
        else
        {
            QuicksortRand(v, 0, v.size() - 1, pivot);
        }
    }
}

void QuickSortMed(vector<string> &v, string pivot)
{
    if (v.size() <= 1)
    {
        cout << "Sorted!" << endl;
        return;
    }
    else
    {
        if (v.size() <= 5)
        {
            InsertionSort(v);
            return;
        }
        else
        {
            QuicksortMed(v, 0, v.size() - 1, pivot);
        }
    }
}

void display(const vector<string> &v)
{
    for (unsigned int i = 0; i < v.size(); ++i)
    {
        cout << v.at(i) << " ";
    }
    cout << endl;
}
