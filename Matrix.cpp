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
	for (auto i = 0; i < M.values.size(); i++) {
		std::vector<T> newVec;
		for (auto j = 0; j < M.values[0].size(); j++) {
			newVec.push_back(0);
		}
		result.push_back(newVec);
	}

	Matrix<T>& left = (*this);
	const Matrix<T>& right = M; 
	for (auto lrow = 0; lrow < M.values[0].size(); lrow++) {
		for (auto rcol = 0; rcol < M.values.size(); rcol++) {
			for (auto i : {0, 1, 2, 3}) {
				result[i][rcol] += left.values[lrow][i] * right.values[i][rcol];
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
	for (auto i : {0.0, 1.0, 2.0, 3.0}) {
		std::vector<T> newVec;
		for (auto j : {0.0, 1.0, 2.0, 3.0}) {
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
const std::vector<T> &Matrix<T>::getCol(int idx) {
	return this->values[idx];
}

int main(void) {

	std::vector<std::vector<float> > mat = 
	{
		{2.4, 4.5, 0.0, 2.3}, 
		{1.0, 3.2, 3.5, 9.0}, 
		{4.3, 2.3, 4.1, 4.5}, 
		{4.8, 1.6, 6.2, 2.2}
	};
	// for (int f : {0, 1, 2, 3}) {
	// 	std::vector<float> col;
	// 	col.push_back(3.2);
	// 	col.push_back(3.1);
	// 	col.push_back(3.0);
	// 	col.push_back(2.9);
	// 	mat.push_back(col);
	// }

	Matrix<float> M1(IDENTITY_4D, 4);
	Matrix<float> M2(IDENTITY_4D, 4);

	Matrix<float> M3 = M1 + M2;
	M3.print();

	Matrix<float> M4 = M3 - M3;
	M4.print();

	M1.print();
	M2.print();

	Matrix<float> M6({
		{2.4, 4.5, 0.0, 2.3}, 
		{1.0, 3.2, 3.5, 9.0}, 
		{4.3, 2.3, 4.1, 4.5}, 
		{4.8, 1.6, 6.2, 2.2}
	});
	Matrix<float> M5 = M1 * M6;
	M5.print();

	std::cout << "exiting" << std::endl;
	return 0;
}