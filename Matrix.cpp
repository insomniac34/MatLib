#include "Matrix.h"

template<class T>
Matrix<T>& Matrix<T>::operator+(const Matrix<T> &M) {
	// std::vector<std::vector<T> > result;
	// for (auto i = 0; i < M.values.size(); i++) {
	// 	std::vector<T> newVec;
	// 	for (auto j = 0; j < M.values[0].size(); j++) {
	// 		newVec.push_back(0);
	// 	}
	// 	result.push_back(newVec);
	// }

	for (typename std::vector<std::vector<T> >::iterator iter = this->values.begin(); iter != this->values.end(); iter++) {
			
		std::cout << iter->size() << std::endl;

		for (typename std::vector<T>::iterator _iter = (*iter).begin(); _iter != (*iter).end(); _iter++) {
			auto outerDistance = std::distance<typename std::vector<std::vector<T> >::const_iterator>(iter, this->values.end()) - 1;
			auto innerDistance = std::distance(_iter, (*iter).end()) - 1;
			//std::cout << "outerDistance: " << outerDistance << std::endl;
			//std::cout << "innerDistance: " << innerDistance << std::endl;
			//std::cout << M.values[outerDistance][innerDistance] << innerDistance << std::endl;
			//std::cout << M.values[0][1] << std::endl;
			(*_iter) += M.values[outerDistance][innerDistance];
			//result[outerDistance][innerDistance] = *_iter + M.values[outerDistance][innerDistance];
		}
	}
	//return Matrix<T>(result);
	return (*this);
}

/*
 * CONSTRUCTORS
 */
template<class T>
Matrix<T>::Matrix() {
	for (auto i : {0.0, 1.0, 2.0, 3.0}) {
		std::vector<T> newVec;
		for (auto j : {0.0, 1.0, 2.0, 3.0}) {
			newVec.push_back(j);
		}
		this->values.push_back(newVec);
	}
}

template<class T>
Matrix<T>::Matrix(std::vector<std::vector<T> > &nums) {
	memcpy((void*)(&this->values), (void*)&nums, sizeof(std::vector<std::vector<T> >));
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

	std::vector<std::vector<float> > mat;
	for (int f : {0, 1, 2, 3}) {
		std::vector<float> col;
		col.push_back(3.2);
		col.push_back(3.1);
		col.push_back(3.0);
		col.push_back(2.9);
		mat.push_back(col);
	}

	Matrix<float> M1(IDENTITY_4D, 4);
	Matrix<float> M2(IDENTITY_4D, 4);
	//M2.print();

	Matrix<float> M3 = M1 + M2;
	M3.print();

	M1.print();
	M2.print();

	//Matrix<float> M2;
	//memcpy((void*)&M2, (void*)M, sizeof(Matrix<float>));
	//M->print();
	//M2.print();



	//delete M;
	return 0;
}