#ifndef Vertex_h
#define Vertex_h

#include <vector>
#include <map>

#include <GL/gl.h>

#include "Point.hpp"


namespace mesh {
	class Vertex {
	public:
		Vertex(std::vector<Point> properties);
		Vertex(Point property);
		Vertex(GLfloat x, GLfloat y);
		Vertex(GLfloat x, GLfloat y, GLfloat z);

		typedef std::vector<Point>::size_type size_type;
		typedef std::vector<Point>::iterator iterator;
		typedef std::vector<Point>::reverse_iterator reverse_iterator;
		
		Point& operator[] (const std::vector<Point>::size_type index);
		std::vector<Point>::iterator begin();
		std::vector<Point>::iterator end();
		std::vector<Point>::reverse_iterator rbegin();
		std::vector<Point>::reverse_iterator rend();
		std::vector<Point>::size_type size();
		void push_back(const Point& value);

		std::vector<Point>::size_type propertiesCount();
		void addProperty(const Point& property);
		std::vector< std::vector<GLfloat> > GLArrays();
	private:
		std::vector<Point> properties;
	};
}

#endif
