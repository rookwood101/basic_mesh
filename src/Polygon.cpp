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
	map< int, vector<GLfloat> > Polygon::GLArrays() {
		map< int, vector<GLfloat> > gl_arrays;
		for(auto vertex : vertices) {
			map< int, vector<GLfloat> > vertex_gl_arrays = vertex.GLArrays();
			for(auto property : vertex_gl_arrays) {
				copy(property.second.begin(), property.second.end(), back_inserter(gl_arrays[property.first]));
			}
		}

		return gl_arrays;
	}
}
