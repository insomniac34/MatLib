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

template class Vector<float>;
template class Vector<double>;
//template class Vector<int>;

