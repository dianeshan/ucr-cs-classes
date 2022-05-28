// main.cpp
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>

using namespace std;

// Display function declarations
void Display(list<int> &);       // displays std::list to std::out
void Display(int a[], int size); // displays array to std::out

// Sorting function declarations
void MergeSort(list<int> &S);                               // MergeSort for list
list<int> &Merge(list<int> &C, list<int> &A, list<int> &B); // Merge for list
void MergeSort(int numbers[], int i, int k);                // MergeSort for array
void Merge(int numbers[], int i, int j, int k);             // Merge for array
void InsertionSort(int numbers[], int numbersSize);         // InsertionSort for array
void InsertionSort(list<int> &S);                           // InsertionSort for list

// IMPLEMENT YOUR SOLUTION BELOW MAIN FUNCTION

int main()
{
  int numbers[] = {10, 2, 78, 4, 45, 32, 7, 11};
  const int NUMBERS_SIZE = 8;
  const int LARGE_N = 1000;

  cout << "ARRAY:\n";
  cout << "UNSORTED: ";
  Display(numbers, NUMBERS_SIZE);

  list<int> seq;
  for (int i = 0; i < NUMBERS_SIZE; i++)
    seq.push_back(numbers[i]);

  cout << "LIST:\n";
  cout << "UNSORTED: ";
  Display(seq);

  MergeSort(numbers, 0, NUMBERS_SIZE - 1);
  cout << "ARRAY:\n";
  cout << "SORTED: ";
  Display(numbers, NUMBERS_SIZE);

  MergeSort(seq);
  cout << "LIST:\n";
  cout << "SORTED: ";
  Display(seq);

  srand((unsigned)time(0)); // seed random number generator

  int *a = NULL;        // Pointer to int, initialize to OxO
  a = new int[LARGE_N]; // Allocate NUMBERS_SIZE ints and save ptr in a.
  list<int> seq2;       // list seq2
  for (int i = 0; i < LARGE_N; i++)
  {
    a[i] = (rand() % (LARGE_N * LARGE_N)) + 1; // insert into array
    seq2.push_back(a[i]);                      // insert into list
  }

  cout << "Array:\n";
  cout << "UNSORTED:";
  Display(a, NUMBERS_SIZE);

  cout << "LIST:\n";
  cout << "UNSORTED: ";
  Display(seq2);

  MergeSort(a, 0, NUMBERS_SIZE - 1);

  cout << "Array:\n";
  cout << "SORTED: ";
  Display(a, NUMBERS_SIZE);

  MergeSort(seq2);
  cout << "LIST:\n";
  cout << "SORTED: ";
  Display(seq2);

  numbers[0] = 20;
  numbers[1] = 10;
  numbers[2] = 79;
  numbers[3] = 2;
  numbers[4] = 200;
  numbers[5] = 50;
  numbers[6] = -50;
  numbers[7] = -51;

  cout << "UNSORTED: ";
  for (int i = 0; i < NUMBERS_SIZE; ++i)
  {
    cout << numbers[i] << " ";
  }
  cout << endl;

  InsertionSort(numbers, NUMBERS_SIZE);

  cout << "SORTED: ";
  for (int i = 0; i < NUMBERS_SIZE; ++i)
  {
    cout << numbers[i] << " ";
  }
  cout << endl;
  return 0;
}

void Display(int a[], int size)
{
  for (int i = 0; i < size; ++i)
    cout << a[i] << " ";
  cout << endl;
}

void Display(list<int> &S)
{
  for (list<int>::iterator it = S.begin(); it != S.end(); ++it)
    cout << *it << " ";
  cout << endl;
}

void MergeSort(list<int> &S)
{
  if (S.size() > 1)
  {
    list<int> S1; //initialize list1
    list<int> S2; //initialize list2

    list<int>::iterator iter = S.begin(); //initialize iterator to iterate through the list
    unsigned int i;
    for (i = 0; i < S.size() / 2; i++) //populate first list with first partition
    {
      S1.push_back(*iter);
      iter++;
    }

    for (unsigned int j = i; j < S.size(); j++) //populate second list with second partition
    {
      S2.push_back(*iter);
      iter++;
    }

    MergeSort(S1);         //sort recursively the left partition
    MergeSort(S2);         //sort recursively the right partition
    list<int> S3;          //initialize list to be merged into
    S = Merge(S3, S1, S2); //call merge function to merge lists into sorted list
  }
}

list<int> &Merge(list<int> &C, list<int> &A, list<int> &B)
{
  while (A.size() != 0 && B.size() != 0) //while both lists are not empty
  {
    if (*A.begin() < *B.begin()) //if A is smaller, pushback A into C and pop it off A
    {
      C.push_back(*A.begin());
      A.pop_front();
    }
    else
    {
      C.push_back(*B.begin()); //else pushback B into C and pop off B
      B.pop_front();
    }
  }

  while (A.size() != 0) //if A is not empty, pushback the remaining into C and pop them off
  {
    C.push_back(*A.begin());
    A.pop_front();
  }

  while (B.size() != 0) //if B is not empty, pushback the remaining into C and pop them off
  {
    C.push_back(*B.begin());
    B.pop_front();
  }

  return C; //return the merged list
}

void MergeSort(int numbers[], int i, int k)
{
  if (i < k)
  {
    int j = (i + k) / 2; //find midpoint in partition

    MergeSort(numbers, i, j);     //recursively sort left partition
    MergeSort(numbers, j + 1, k); //recursively sort right partition

    Merge(numbers, i, j, k); //call merge function to merge them in sorted order
  }
}

void Merge(int numbers[], int i, int j, int k)
{
  int mergedSize = k - i + 1;               //size of merged partition
  int mergePos = 0;                         //position to insert merged number
  int *mergedNumbers = new int[mergedSize]; //dynamically allocate array for merged numbers

  int leftPos = i;      //initiliaze left partition pos
  int rightPos = j + 1; //initiliaze right partition pos

  while (leftPos <= j && rightPos <= k) //add smallest element from either the left or right side to the array
  {
    if (numbers[leftPos] <= numbers[rightPos]) //see which one is smaller
    {
      mergedNumbers[mergePos] = numbers[leftPos];
      leftPos++;
    }
    else
    {
      mergedNumbers[mergePos] = numbers[rightPos];
      rightPos++;
    }
    mergePos++;
  }

  //copy remaining numbers from right partition if not empty
  while (rightPos <= k)
  {
    mergedNumbers[mergePos] = numbers[rightPos];
    rightPos++;
    mergePos++;
  }

  //copy remaining numbers from left partition if not empty
  while (leftPos <= j)
  {
    mergedNumbers[mergePos] = numbers[leftPos];
    leftPos++;
    mergePos++;
  }

  //copy array back to original array
  for (mergePos = 0; mergePos < mergedSize; mergePos++)
  {
    numbers[i + mergePos] = mergedNumbers[mergePos];
  }
}

void InsertionSort(int numbers[], int numbersSize)
{
  int temp = 0;

  for (int i = 1; i < numbersSize; ++i)
  {
    int j = i;
    while (j > 0 && numbers[j] < numbers[j - 1])
    {
      temp = numbers[j];
      numbers[j] = numbers[j - 1];
      numbers[j - 1] = temp;
      j--;
    }
  }
}

void InsertionSort(list<int> &S)
{
  int temp;                           //declare a temp for swapping
  list<int>::iterator it = S.begin(); //initialize an it for comparison

  for (list<int>::iterator iter = next(S.begin()); iter != S.end(); iter++)
  {
    it = iter;
    while (it != S.begin() && *it < *prev(it)) //insert whatever is at it into correct part
    {
      temp = *it; //swap it and prev
      *it = *prev(it);
      *prev(it) = temp;
      it--; //decrement it
    }
  }
}
