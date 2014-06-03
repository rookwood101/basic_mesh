#ifndef Polyhedron_h
#define Polyhedron_h

#include <vector>
#include <map>

#include <GL/gl.h>

#include "Polygon.hpp"

namespace mesh {
	class Polyhedron {
	public:
		Polyhedron(std::vector<Polygon> faces);

		typedef std::vector<Polygon>::size_type size_type;
		typedef std::vector<Polygon>::iterator iterator;
		typedef std::vector<Polygon>::reverse_iterator reverse_iterator;

		Polygon& operator[] (const std::vector<Polygon>::size_type index);
		std::vector<Polygon>::iterator begin();
		std::vector<Polygon>::iterator end();
		std::vector<Polygon>::reverse_iterator rbegin();
		std::vector<Polygon>::reverse_iterator rend();
		std::vector<Polygon>::size_type size();
		void push_back(const Polygon& value);

		std::vector<Polygon>::size_type faceCount();
		void addFace(const Polygon& value);
		std::map< int, std::vector<GLfloat> > GLArrays();
	private:
		std::vector<Polygon> faces;
	};
}

#endif
