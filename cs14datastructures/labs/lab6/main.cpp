/*
 * cs014_sum20AB
 * lab6
 * main.cpp
 * test harness
 * RR
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <map>
#include <iomanip>
#include "pq_zero.H"

using namespace std;
void test_ordered_priorities(vector<string> &v1, vector<float> &v2);
void test_random_ordered_priorities(vector<string> &v1, vector<float> &v2);

//void test_same_priorities(vector<string>& v, vector<float>& v2);
void swap_entries(vector<float> &v);
void build_ISRA(vector<string> &v);
void build_forder(vector<float> &v, unsigned int size);
float rand_to_one();
float rand_to_limit(float hi);
float rand_range(float hi, float low);
int rand_range(int hi, int low);

int main()
{

    cout << setfill('=');     // for iomanip
    srand((unsigned)time(0)); // seed rand num gen

    vector<string> nato; // vector of items
    build_ISRA(nato);
    vector<float> vfs; // vector of priorities
    build_forder(vfs, nato.size());

    test_ordered_priorities(nato, vfs);        // see procedure comments
    test_random_ordered_priorities(nato, vfs); // see procedure comments

    /*
  vector<float> vfs2;                         // vector of priorities
  build_forder(vfs2, nato.size());
  test_same_priorities(nato, vfs2);           // see procedure comments
  */

    return 0;
}

// Test Procedure: Test that items inserted into the pq with increasing priorities
// are removed from the pq with the appropriate priority.
void test_ordered_priorities(vector<string> &v1, vector<float> &v2)
{
    string out = "test_ordered_priorities:";
    cout << setw(out.size()) << "" << endl;
    cout << out << endl;
    cout << setw(out.size()) << "" << endl;

    pq_zero<string> pqstr;
    for (unsigned int i = 0; i < v1.size(); i++)
    {
        pqstr.push(v1[i], v2[i]); // pushes a single string, priority pair
        cout << "v1[" << i << "i]=" << v1[i] << endl;
        cout << "v2[i" << i << "]=" << v2[i] << endl;
    }

    pqstr.print(); // print heap

    while (!pqstr.empty())
    {
        cout << "front(): " << pqstr.front() << endl;
        pqstr.pop();
    }
}

// Test Procedure: Test that items inserted into the pq with random priorities
// are removed from the pq with the appropriate priority.
void test_random_ordered_priorities(vector<string> &v1, vector<float> &v2)
{
    string out = "test_random_ordered_priorities:";
    cout << setw(out.size()) << "" << endl;
    cout << out << endl;
    cout << setw(out.size()) << "" << endl;

    swap_entries(v2); // randomly swap some priorities
    map<string, float> str2f;
    for (unsigned int i = 0; i < v1.size(); i++)
    {
        str2f[v1[i]] = v2[i];
    }

    for (unsigned int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << ", p=" << str2f[v1[i]] << endl; // show items with priorites after swap
    }

    pq_zero<string> pqstr;
    vector<string> top_order;
    for (unsigned int i = 0; i < v1.size(); i++)
    {
        pqstr.push(v1[i], v2[i]);
    }

    pqstr.print(); // print heap

    while (!pqstr.empty())
    {
        cout << "front(): " << pqstr.front() << ", p=" << str2f[pqstr.front()] << endl;
        pqstr.pop();
    }
}

// Utility: Randomly swaps approx 1/2 of vector's elements.
void swap_entries(vector<float> &f)
{
    int low = 0;
    int mid = f.size() / 2;
    int hi = f.size() - 1;
    for (unsigned int i = 0; i < f.size() / 4; i++)
    {
        int ri = rand_range(low, mid);
        int rj = rand_range(mid + 1, hi);
        swap(f[ri], f[rj]);
    }
}

// Utility: Builds a vector of floats, monotonically increasing.
void build_forder(vector<float> &v, unsigned int size)
{
    float f = 1.11;
    for (unsigned int i = 0; i < size; i++)
        v.push_back(i * f);
}

// Utility: Builds a vector of strings from NATO phonetic alphabet.
void build_ISRA(vector<string> &v)
{
    v.push_back("alpha");
    v.push_back("bravo");
    v.push_back("charlie");
    v.push_back("delta");
    v.push_back("echo");
    v.push_back("foxtrot");
    v.push_back("golf");
    v.push_back("hotel");
    v.push_back("india");
    v.push_back("juliet");
    v.push_back("kilo");
    v.push_back("lima");
    v.push_back("mike");
    v.push_back("november");
    v.push_back("oscar");
    v.push_back("papa");
    v.push_back("quebec");
    v.push_back("romeo");
    v.push_back("sierra");
    v.push_back("tango");
    v.push_back("uniform");
    v.push_back("victor");
    v.push_back("whiskey");
    v.push_back("xray");
    v.push_back("yankee");
    v.push_back("zula");
}

// Utilities: Random number generators
float rand_to_one()
{
    return (float)rand() / (float)RAND_MAX;
}
float rand_to_limit(float hi)
{
    return (float)rand() / ((float)RAND_MAX / hi);
}
float rand_range(float low, float hi)
{
    return low + (float)rand() / ((float)RAND_MAX / (hi - low));
}
int rand_range(int low, int hi)
{
    return low + (int)rand() / ((int)RAND_MAX / (hi - low));
}
