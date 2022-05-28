#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "Quicksort.H"

using namespace std;

int main()
{
    string pivotm;
    string pivotr;
    vector<string> v1;
    vector<string> v2;

    v1.push_back("juliet");
    v1.push_back("papa");
    v1.push_back("bravo");
    v1.push_back("victor");
    v1.push_back("romeo");
    v1.push_back("delta");
    v1.push_back("whiskey");
    v1.push_back("charlie");
    v1.push_back("lima");
    v1.push_back("apple");

    v2.push_back("juliet");
    v2.push_back("papa");
    v2.push_back("bravo");
    v2.push_back("victor");
    v2.push_back("romeo");
    v2.push_back("delta");
    v2.push_back("whiskey");
    v2.push_back("charlie");
    v2.push_back("lima");
    v2.push_back("apple");

    cout << "UNSORTED: " << endl;
    display(v1);
    pivotm = median_three(v1, 0, v1.size());
    QuickSortMed(v1, pivotm);
    cout << "SORTED (median): " << endl;
    display(v1);
    cout << "UNSORTED: " << endl;
    display(v2);
    pivotr = random(v2, v2.size());
    QuickSortRand(v2, pivotr);
    cout << "SORTED (random): " << endl;
    display(v2);
    return 0;
}