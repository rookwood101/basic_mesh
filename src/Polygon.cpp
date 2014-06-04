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
	map< string, vector<GLfloat> > Polygon::GLArrays() {
		map< string, vector<GLfloat> > gl_arrays;
		for(auto vertex : vertices) {
			map< string, vector<GLfloat> > vertex_gl_arrays = vertex.GLArrays();
			for(auto vertex_gl_array : vertex_gl_arrays) {
				copy(vertex_gl_array.second.begin(), vertex_gl_array.second.end(), back_inserter(gl_arrays[vertex_gl_array.first]));
			}
		}

		return gl_arrays;
	}
}
