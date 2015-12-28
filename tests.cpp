#include "SimpleEngine.h"


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

	Vector<float> vec0(1, 1, 1);
	Matrix<float> id = Matrix<float>(IDENTITY_4D, 4);

	Matrix<float> res = id * vec0;
	res.print();


	std::cout << "exiting" << std::endl;
	return 0;
}
