#include <vector>

#include <GL/gl.h>

#include "../include/Point.hpp"

using namespace std;


namespace mesh {
	Point::Point(GLfloat x, GLfloat y) {
		coordinates.push_back(x);
		coordinates.push_back(y);
	}
	Point::Point(GLfloat x, GLfloat y, GLfloat z) {
		Point(x, y);
		coordinates.push_back(z);
	}
	Point::Point(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
		Point(x, y, z);
		coordinates.push_back(w);
	}
	Point::Point(vector<GLfloat> coordinates) {
		this->coordinates = coordinates;
	}

	GLfloat& Point::operator[] (const vector<GLfloat>::size_type index) {
		return coordinates[index];
	}

	vector<GLfloat>::iterator Point::begin() {
		return coordinates.begin();
	}
	vector<GLfloat>::iterator Point::end() {
		return coordinates.end();
	}
	vector<GLfloat>::reverse_iterator Point::rbegin() {
		return coordinates.rbegin();
	}
	vector<GLfloat>::reverse_iterator Point::rend() {
		return coordinates.rend();
	}
	vector<GLfloat>::size_type Point::size() {
		return coordinates.size();
	}
	void Point::push_back(const GLfloat& value) {
		coordinates.push_back(value);
	}

	GLfloat& Point::x() {
		return coordinates[0];
	}
	GLfloat& Point::y() {
		return coordinates[1];
	}
	GLfloat& Point::z() {
		return coordinates[2];
	}
	GLfloat& Point::w() {
		return coordinates[3];
	}

	vector<GLfloat>::size_type Point::dimensionCount() {
		return size();
	}
	void Point::addDimension(const GLfloat& value) {
		push_back(value);
	}
	vector<GLfloat> Point::GLArray() {
		return coordinates;
	}
}
