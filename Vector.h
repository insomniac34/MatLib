//C++ Standard Template Library
#include <vector>
#include <string>

//C Standard Library
#include <cmath>

#include "Matrix.h"

template<class T>
class Vector : public Matrix<T> {
public:
	Vector();
	~Vector();

	Vector(T x, T y, T z);
	Vector(T x, T y, T z, T w);

	void normalize();

	T getX();
	T getY();
	T getZ();

	void setX(T);
	void setY(T);
	void setZ(T);
private:
	
};
