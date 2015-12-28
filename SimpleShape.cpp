#include "SimpleShape.h"

SimpleShape::SimpleShape() {

}

SimpleShape::SimpleShape(std::deque<Vertex> vertices) {
	this->vertices = vertices;
}

SimpleShape::SimpleShape(std::ifstream inputFileStream) {
	
}

SimpleShape::~SimpleShape() {

}
