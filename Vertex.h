#include "Vector.h"

class Vertex {
public:
	Vertex();
	Vertex(float x, float y, float z);
	Vertex(float x, float y, float z, float w);
	~Vertex();

	float getX();
	float getY();
	float getZ();
	float getW();

private:
	Vector<float> point;

};
