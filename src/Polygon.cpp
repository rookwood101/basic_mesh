#include <vector>
#include <map>
#include <algorithm>
#include <iterator>

#include <GL/gl.h>

#include "../include/Polygon.hpp"
#include "../include/Vertex.hpp"

using namespace std;


namespace mesh {
	Polygon::Polygon(vector<Vertex> vertices) {
		this->vertices = vertices;
	}
	Polygon::Polygon(Vertex vertex_1, Vertex vertex_2, Vertex vertex_3) {
		vertices.push_back(vertex_1);
		vertices.push_back(vertex_2);
		vertices.push_back(vertex_3);
	}

	Vertex& Polygon::operator[] (const vector<Vertex>::size_type index) {
		return vertices[index];
	}

	vector<Vertex>::iterator Polygon::begin() {
		return vertices.begin();
	}
	vector<Vertex>::iterator Polygon::end() {
		return vertices.end();
	}
	vector<Vertex>::reverse_iterator Polygon::rbegin() {
		return vertices.rbegin();
	}
	vector<Vertex>::reverse_iterator Polygon::rend() {
		return vertices.rend();
	}
	vector<Vertex>::size_type Polygon::size() {
		return vertices.size();
	}
	void Polygon::push_back(const Vertex& value) {
		vertices.push_back(value);
	}

	vector<Vertex>::size_type Polygon::vertexCount() {
		return size();
	}
	void Polygon::addVertex(const Vertex& value) {
		push_back(value);
	}
	vector< vector<GLfloat> > Polygon::GLArrays() {
		vector< vector<GLfloat> > gl_arrays;
		for(auto vertex : vertices) {
			vector< vector<GLfloat> > vertex_gl_arrays = vertex.GLArrays();
			for(size_type i=0; i<vertex.propertiesCount(); ++i) {
				if(gl_arrays.size() <= i) {
					gl_arrays.push_back(vector<GLfloat>());
				}
				copy(vertex_gl_arrays[i].begin(), vertex_gl_arrays[i].end(), back_inserter(gl_arrays[i]));
			}
		}

		return gl_arrays;
	}
}
