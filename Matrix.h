//C++ Standard Template Library
#include <deque>
#include <iostream>
#include <iterator>
#include <vector>

//C Standard Library
#include <cstdio>
#include <cstring>

//Matrix constants
#include "constants.h"

template<class T>
class Matrix {
	public:

		/*
		 * Default Constructor
		 */
		Matrix();

		/*
		 * Default Destructor
		 */
		 ~Matrix();

		/*
		 * Templated Constructors
		 */
		Matrix(std::vector<std::vector<T> > &nums);
		Matrix(T** nums, int dim);
		Matrix(const T nums[][4], int dim);

		/*
		 * Arithmetic Operators
		 */
		Matrix& operator+(const Matrix<T> &M);
		void print();
		const std::vector<T> &getCol(int idx);
		
		
	
	private:
		std::vector<std::vector<T> > values;
};
