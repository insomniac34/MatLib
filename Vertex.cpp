#include "Vertex.h"

Vertex::Vertex() {
	this->point = Vector<float>({ 
		{0.0}, //X
		{0.0}, //Y
		{0.0}, //Z
		{1.0}  //W
	});
}

Vertex::Vertex(float x, float y, float z) {
	this->point = Vector<float>({
		{ x }, //X
		{ y }, //Y
		{ z }, //Z
		{ 1.0 }  //W
	});
}

Vertex::Vertex(float x, float y, float z, float w) {
	this->point = Vector<float>({
		{ x }, //X
		{ y }, //Y
		{ z }, //Z
		{ w }  //W
	});
}

Vertex::~Vertex() {

}

float Vertex::getX() {
	return this->point.getValues()[0][0];
}

float Vertex::getY() {
	return this->point.getValues()[1][0];
}

float Vertex::getZ() {
	return this->point.getValues()[2][0];
}

float Vertex::getW() {
	return this->point.getValues()[3][0];
}

