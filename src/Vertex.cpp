#include <vector>
#include <map>

#include <GL/gl.h>

#include "../include/Vertex.hpp"
#include "../include/Point.hpp"

using namespace std;

namespace mesh {
	Vertex::Vertex(map<string, Point> properties) {
		this->properties = properties;
	}
	Vertex::Vertex(std::string property_name, Point property) {
		properties[property_name] = property;
	}
	
	Point& Vertex::operator[] (const std::string index) {
		return properties[index];
	}
	map<string, Point>::iterator Vertex::begin() {
		return properties.begin();
	}
	map<string, Point>::iterator Vertex::end() {
		return properties.end();
	}
	map<string, Point>::reverse_iterator Vertex::rbegin() {
		return properties.rbegin();
	}
	map<string, Point>::reverse_iterator Vertex::rend() {
		return properties.rend();
	}
	map<string, Point>::size_type Vertex::size() {
		return properties.size();
	}
	void Vertex::push_back(const string& property_name, const Point& property) {
		properties[property_name] = property;
	}

	map<string, Point>::size_type Vertex::propertiesCount() {
		return size();
	}
	void Vertex::addProperty(const string& property_name, const Point& property) {
		push_back(property_name, property);
	}
	map< string, vector<GLfloat> > Vertex::GLArrays() {
		map< string, vector<GLfloat> > gl_arrays;
		for(auto property : properties) {
			gl_arrays[property.first] = property.second.GLArray();
		}
		return gl_arrays;
	}
}
