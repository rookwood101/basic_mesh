#include <vector>
#include <map>

#include <GL/gl.h>

#include "../include/Vertex.hpp"
#include "../include/Point.hpp"

using namespace std;

namespace mesh {
	Vertex::Vertex(vector<Point> properties) {
		this->properties = properties;
	}
	Vertex::Vertex(Point property) {
		properties.push_back(property);
	}
	Vertex::Vertex(GLfloat x, GLfloat y) {
		properties.push_back(Point(x, y));
	}
	Vertex::Vertex(GLfloat x, GLfloat y, GLfloat z) {
		properties.push_back(Point(x, y, z));
	}
	
	Point& Vertex::operator[] (const vector<Point>::size_type index) {
		return properties[index];
	}
	vector<Point>::iterator Vertex::begin() {
		return properties.begin();
	}
	vector<Point>::iterator Vertex::end() {
		return properties.end();
	}
	vector<Point>::reverse_iterator Vertex::rbegin() {
		return properties.rbegin();
	}
	vector<Point>::reverse_iterator Vertex::rend() {
		return properties.rend();
	}
	vector<Point>::size_type Vertex::size() {
		return properties.size();
	}
	void Vertex::push_back(const Point& value) {
		properties.push_back(value);
	}

	vector<Point>::size_type Vertex::propertiesCount() {
		return size();
	}
	void Vertex::addProperty(const Point& property) {
		push_back(property);
	}
	vector< vector<GLfloat> > Vertex::GLArrays() {
		vector< vector<GLfloat> > gl_arrays;
		for(auto property : properties) {
			gl_arrays.push_back(property.GLArray());
		}
		return gl_arrays;
	}
}
