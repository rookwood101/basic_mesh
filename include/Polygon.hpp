#ifndef Polygon_h
#define Polygon_h

#include <vector>
#include <map>

#include <GL/gl.h>

#include "Vertex.hpp"

namespace mesh {
	class Polygon {
	public:
		Polygon(std::vector<Vertex> vertices);
		Polygon(Vertex vertex_1, Vertex vertex_2, Vertex vertex_3);

		typedef std::vector<Vertex>::size_type size_type;
		typedef std::vector<Vertex>::iterator iterator;
		typedef std::vector<Vertex>::reverse_iterator reverse_iterator;

		Vertex& operator[] (const std::vector<Vertex>::size_type index);
		std::vector<Vertex>::iterator begin();
		std::vector<Vertex>::iterator end();
		std::vector<Vertex>::reverse_iterator rbegin();
		std::vector<Vertex>::reverse_iterator rend();
		std::vector<Vertex>::size_type size();
		void push_back(const Vertex& value);

		std::vector<Vertex>::size_type vertexCount();
		void addVertex(const Vertex& value);
		std::map< int, std::vector<GLfloat> > GLArrays();
	private:
		std::vector<Vertex> vertices;
	};
}

#endif
