#include "SimpleShape.h"


/*
 * Constructors
 */
SimpleShape::SimpleShape() {

}

SimpleShape::SimpleShape(std::deque<Vertex> vertices) {
	this->vertices = vertices;
}

SimpleShape::SimpleShape(std::ifstream inputFileStream) {
	
}


/*
 * Destructors
 */
SimpleShape::~SimpleShape() {

}


/*
 * Operations
 */
void SimpleShape::rotate(float degrees, char axis) {

}

void SimpleShape::rotateInPlace(float degrees, char axis) {

}

void SimpleShape::translate(float THETA, float x, float y, float z) {

}

void SimpleShape::scale(float x, float y, float z) {

}
