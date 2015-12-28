//C++ Standard Template Library
#include <vector>
#include <string>

#include "Matrix.h"

template<class T>
class Vector : public Matrix<T> {
public:
	Vector();
	~Vector();

	Vector(T x, T y, T z);
	Vector(T x, T y, T z, T w);
private:
	
};
