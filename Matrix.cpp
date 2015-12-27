/*
 * 	Matrix class implementation
 *
 *	(C) 2015 Tyler Raborn
 *	This software is distributed under the GNU General Public License, v3.0
 */

#include "Matrix.h"

/*
 * ARITHMETIC OPERATORS
 */
template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &M) {
	std::vector<std::vector<T> > result;
	for (auto i = 0; i < M.values.size(); i++) {
		std::vector<T> newVec;
		for (auto j = 0; j < M.values[0].size(); j++) {
			newVec.push_back(0);
		}
		result.push_back(newVec);
	}

	for (typename std::vector<std::vector<T> >::iterator iter = this->values.begin(); iter != this->values.end(); iter++) {
		for (typename std::vector<T>::iterator _iter = (*iter).begin(); _iter != (*iter).end(); _iter++) {
			auto outerDistance = std::distance<typename std::vector<std::vector<T> >::const_iterator>(iter, this->values.end()) - 1;
			auto innerDistance = std::distance(_iter, (*iter).end()) - 1;
			result[outerDistance][innerDistance] = (*_iter) + M.values[outerDistance][innerDistance];
		}
	}
	return Matrix<T>(result);
}

template<class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &M) {
	std::vector<std::vector<T> > result;
	for (auto i = 0; i < M.values.size(); i++) {
		std::vector<T> newVec;
		for (auto j = 0; j < M.values[0].size(); j++) {
			newVec.push_back(0);
		}
		result.push_back(newVec);
	}

	for (typename std::vector<std::vector<T> >::iterator iter = this->values.begin(); iter != this->values.end(); iter++) {
		for (typename std::vector<T>::iterator _iter = (*iter).begin(); _iter != (*iter).end(); _iter++) {
			auto outerDistance = std::distance<typename std::vector<std::vector<T> >::const_iterator>(iter, this->values.end()) - 1;
			auto innerDistance = std::distance(_iter, (*iter).end()) - 1;
			result[outerDistance][innerDistance] = (*_iter) - M.values[outerDistance][innerDistance];
		}
	}
	return Matrix<T>(result);
}

template<class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &M) {
	std::vector<std::vector<T> > result;
	for (auto i = 0; i < this->values.size(); i++) {
		std::vector<T> newVec;
		for (auto j = 0; j < M.values[0].size(); j++) {
			newVec.push_back(0);
		}
		result.push_back(newVec);
	}

	Matrix<T>& left = (*this);
	const Matrix<T>& right = M; 
	for (auto lrow = 0; lrow < left.values.size(); lrow++) {
		for (auto rcol = 0; rcol < right.values[0].size(); rcol++) {
			for (auto i = 0; i < left.values[0].size(); i++) {
				result[lrow][rcol] += left.values[lrow][i] * right.values[i][rcol];
			}
		}
	}
	return Matrix<T>(result);
}

/*
 * CONSTRUCTORS
 */
template<class T>
Matrix<T>::Matrix() {
	for (auto i : {0, 1, 2, 3}) {
		std::vector<T> newVec;
		for (auto j : {0, 1, 2, 3}) {
			newVec.push_back(0);
		}
		this->values.push_back(newVec);
	}
}

template<class T>
Matrix<T>::Matrix(std::vector<std::vector<T> > nums) {
	this->values = nums;
}

template<class T> 
Matrix<T>::Matrix(T** nums, int dim) {
	for (int i = 0; i < dim; i++) {
		std::vector<T> newVec;
		for (int j = 0; j < dim; j++) {
			newVec.push_back(nums[i][j]);
		}
		this->values.push_back(newVec);
	}
}

template<class T> 
Matrix<T>::Matrix(const T nums[][4], int dim) {
	for (int i = 0; i < dim; i++) {
		std::vector<T> newVec;
		for (int j = 0; j < dim; j++) {
			newVec.push_back(nums[i][j]);
		}
		this->values.push_back(newVec);
	}
}

/*
 * DESTRUCTORS
 */
template<class T>
Matrix<T>::~Matrix() {

}

/*
 * DEV
 */
template<class T>
void Matrix<T>::print() {
	std::cout << "length: " << this->values.size() << std::endl;
	for (std::vector<T> v : this->values) {
		for (T t : v) {
			std::cout << t << " ";
		}
		std::cout << std::endl;
	}
}

/*
 * UTILITY
 */
template<class T>
std::vector<std::vector<T> > &Matrix<T>::getValues() {
	return this->values;
}

template<class T>
const std::vector<T> &Matrix<T>::getCol(int idx) {
	return this->values[idx];
}

int main(void) {
	std::vector<std::vector<float> > mat = 
	{
		{-1.0, 0.0, 0.0, 0.0}, 
		{0.0, 1.0, 0.0, 0.0}, 
		{0.0, 0.0, -1.0, 0.0}, 
		{0.0, -1.0, -1.0, 1.0}
	};

	Matrix<float> M1(IDENTITY_4D, 4);
	Matrix<float> M2(IDENTITY_4D, 4);

	Matrix<float> M3 = M1 + M2;
	M3.print();

	Matrix<float> M4 = M3 - M3;
	M4.print();

	M1.print();
	M2.print();

	Matrix<float> M6({
		{-1.0, 0.0,  0.0, 0.0}, 
		{ 0.0, 1.0,  0.0, 0.0}, 
		{ 0.0, 0.0, -1.0, 0.0}, 
		{ 0.0, 0.0,  0.0, 1.0}
	});

	Matrix<float> M7({
		{1.0, 0.0, 0.0, 0.0}, 
		{0.0, 1.0, 0.0, 0.0}, 
		{0.0, 0.0, 1.0, 0.0}, 
		{0.0, -1.0, -1.0, 1.0}
	});
	Matrix<float> M5 = M1 * M6;
	std::cout << "M5:" << std::endl;
	M5.print();

	Matrix<float> M8 = M6 * M7;
	std::cout << "M8:" << std::endl;
	M8.print();

	for (int i = 0; i < M8.getValues().size(); i++) {
		for (int j = 0; j < M8.getValues()[i].size(); j++) {
			assert(M8.getValues()[i][j] == mat[i][j]);
		}
	}

	Matrix<float> V0 = Matrix<float>({
		{9}, 
		{8}, 
		{7}
	});

	Matrix<float> M9 = Matrix<float>({
		{ 1, 2, 3},
		{ 4, 5, 6}
	});

	Matrix<float> matVecResult = M9 * V0;
	matVecResult.print();
	
	std::vector<std::vector<float> > matVecResultExpectedValue = {
		{46.0}, 
		{118.0}
	};
	for (int i = 0; i < matVecResult.getValues().size(); i++) {
		for (int j = 0; j < matVecResult.getValues()[i].size(); j++) {
			assert(matVecResult.getValues()[i][j] == matVecResultExpectedValue[i][j]);
		}
	}

	std::cout << "exiting" << std::endl;
	return 0;
}