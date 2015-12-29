#include "Vector.h"

template<class T>
Vector<T>::Vector() {
	this->values = { 
		{0.0}, 
		{0.0}, 
		{0.0}, 
		{1.0} 
	};
}

template<class T>
Vector<T>::Vector(T x, T y, T z) {
	this->values = { 
		{x}, 
		{y}, 
		{z},
		{1.0}
	};
}

template<class T>
Vector<T>::Vector(T x, T y, T z, T w) {
	this->values = { 
		{x},
		{y}, 
		{z},
		{w}
	};
}

template<class T>
Vector<T>::~Vector() {

}

template<class T>
T Vector<T>::getX() {
	return this->values[0][0];
}

template<class T>
T Vector<T>::getY() {
	return this->values[1][0];
}

template<class T>
T Vector<T>::getZ() {
	return this->values[2][0];
}

template<class T>
void Vector<T>::setX(T val) {
	this->values[0][0] = val;
}

template<class T>
void Vector<T>::setY(T val) {
	this->values[1][0] = val;
}

template<class T>
void Vector<T>::setZ(T val) {
	this->values[2][0] = val;
}

template<class T>
void Vector<T>::normalize() {
	T length = sqrt(
		pow(getX(), 2) + 
		pow(getY(), 2) + 
		pow(getZ(), 2)
	);

	setX(getX() / length);
	setY(getY() / length);
	setZ(getZ() / length);
}

template class Vector<float>;
template class Vector<double>;
//template class Vector<int>;

