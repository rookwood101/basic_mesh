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
	vector< vector<GLfloat> > Polyhedron::GLArrays() {
		vector< vector<GLfloat> > gl_arrays;
		for(auto face : faces) {
			vector< vector<GLfloat> > face_gl_arrays = face.GLArrays();
			for(size_type i=0; i<face.vertexCount(); ++i) {
				if(gl_arrays.size() <= i) {
					gl_arrays.push_back(vector<GLfloat>());
				}
				copy(face_gl_arrays[i].begin(), face_gl_arrays[i].end(), back_inserter(gl_arrays[i]));
			}
		}

		return gl_arrays;
	}
}
