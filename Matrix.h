//C++ Standard Template Library
#include <deque>
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

//C Standard Library
#include <cstdio>
#include <cstring>
#include <cassert>

//Matrix constants
#include "constants.h"

//debugging mode
//#define NDEBUG

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
		Matrix(std::vector<std::vector<T> > nums);
		Matrix(T** nums, int dim);
		Matrix(const T nums[][4], int dim);

		/*
		 * Arithmetic Operators
		 */
		Matrix operator+(const Matrix<T> &M);
		Matrix operator-(const Matrix<T> &M);
		Matrix operator*(const Matrix<T> &M);

		//utility
		void print();
		const std::vector<T> &getCol(int idx);
		std::vector<std::vector<T> >& getValues();
		
	
	private:
		std::vector<std::vector<T> > values;

};

const Matrix<float> IDENTITY(IDENTITY_4D, 4);
