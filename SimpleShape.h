//C++ Standard Template Library
#include <deque>
#include <fstream>

#include "Vertex.h"

class SimpleShape {
public:
	/*
	 * Default Constructor
	 */
	SimpleShape();

	/*
	 * Constructors
	 */
	SimpleShape(std::deque<Vertex> vertices);
	SimpleShape(std::ifstream inputFileStream);
	

	/*
	 * Default Destructor
	 */	
	~SimpleShape();

	/*
	 * Operations
	 */
	virtual void rotate(float degrees, char axis);
	virtual void rotateInPlace(float degrees, char axis);
	virtual void translate(float THETA, float x, float y, float z);
	virtual void scale(float x, float y, float z);

protected:
	std::deque<Vertex> vertices;

};
