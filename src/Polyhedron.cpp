#include <vector>
#include <map>
#include <algorithm>
#include <iterator>

#include <GL/gl.h>

#include "../include/Polyhedron.hpp"
#include "../include/Polygon.hpp"

using namespace std;


namespace mesh {
	Polyhedron::Polyhedron(vector<Polygon> faces) {
		this->faces = faces;
	}

	Polygon& Polyhedron::operator[] (const vector<Polygon>::size_type index) {
		return faces[index];
	}

	vector<Polygon>::iterator Polyhedron::begin() {
		return faces.begin();
	}
	vector<Polygon>::iterator Polyhedron::end() {
		return faces.end();
	}
	vector<Polygon>::reverse_iterator Polyhedron::rbegin() {
		return faces.rbegin();
	}
	vector<Polygon>::reverse_iterator Polyhedron::rend() {
		return faces.rend();
	}
	vector<Polygon>::size_type Polyhedron::size() {
		return faces.size();
	}
	void Polyhedron::push_back(const Polygon& value) {
		faces.push_back(value);
	}

	void Polyhedron::addFace(const Polygon& value) {
		push_back(value);
	}

	vector<Polygon>::size_type Polyhedron::faceCount() {
		return size();
	}
	map< string, vector<GLfloat> > Polyhedron::GLArrays() {
		map< string, vector<GLfloat> > gl_arrays;
		for(auto face: faces) {
			map< string, vector<GLfloat> > face_gl_arrays = face.GLArrays();
			for(auto face_gl_array : face_gl_arrays) {
				copy(face_gl_array.second.begin(), face_gl_array.second.end(), back_inserter(gl_arrays[face_gl_array.first]));
			}
		}

		return gl_arrays;
	}
}
