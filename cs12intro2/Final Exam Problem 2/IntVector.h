#ifndef __INTVECTOR_H__
#define __INTVECTOR_H__

class IntVector {
  private:
   unsigned sz;
   unsigned cap;
   int *data;
  public:
   // Declare your constructor here
   IntVector(int arr[], int beg, int end);
	~IntVector();
	unsigned size() const;
	unsigned capacity() const;
	bool empty() const;
	const int & at(unsigned) const;
	int & at(unsigned);
};

#endif
