//C++ Standard Template Library
#include <deque>
#include <fstream>

#include "Vertex.h"

class SimpleShape {
public:
	SimpleShape();
	SimpleShape(std::deque<Vertex> vertices);
	SimpleShape(std::ifstream inputFileStream);
	~SimpleShape();

private:
	std::deque<Vertex> vertices;

};
