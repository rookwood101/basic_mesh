#ifndef Vertex_h
#define Vertex_h

#include <vector>
#include <map>

#include <GL/gl.h>

#include "Point.hpp"


namespace mesh {
	class Vertex {
	public:
		Vertex();
		Vertex(std::map<std::string, Point> properties);
		Vertex(std::string property_name, Point property);

		typedef std::map<std::string, Point>::size_type size_type;
		typedef std::map<std::string, Point>::iterator iterator;
		typedef std::map<std::string, Point>::reverse_iterator reverse_iterator;
		
		Point& operator[] (const std::string index);
		std::map<std::string, Point>::iterator begin();
		std::map<std::string, Point>::iterator end();
		std::map<std::string, Point>::reverse_iterator rbegin();
		std::map<std::string, Point>::reverse_iterator rend();
		std::map<std::string, Point>::size_type size();
		void push_back(const std::string& property_name, const Point& value);

		std::map<std::string, Point>::size_type propertiesCount();
		void addProperty(const std::string& property_name, const Point& property);
		std::map< std::string, std::vector<GLfloat> > GLArrays();
	private:
		std::map<std::string, Point> properties;
	};
}

#endif
