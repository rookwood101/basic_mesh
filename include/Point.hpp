#ifndef Point_h
#define Point_h

#include <vector>

#include <GL/gl.h>

namespace mesh {
	class Point {
	public:
		Point(GLfloat x, GLfloat y);
		Point(GLfloat x, GLfloat y, GLfloat z);
		Point(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
		Point(std::vector<GLfloat> coordinates);

		typedef std::vector<GLfloat>::size_type size_type;
		typedef std::vector<GLfloat>::iterator iterator;
		typedef std::vector<GLfloat>::reverse_iterator reverse_iterator;

		GLfloat& operator[] (const std::vector<GLfloat>::size_type index);
		std::vector<GLfloat>::iterator begin();
		std::vector<GLfloat>::iterator end();
		std::vector<GLfloat>::reverse_iterator rbegin();
		std::vector<GLfloat>::reverse_iterator rend();
		std::vector<GLfloat>::size_type size();
		void push_back(const GLfloat& value);

		GLfloat& x();
		GLfloat& y();
		GLfloat& z();
		GLfloat& w();

		std::vector<GLfloat>::size_type dimensionCount();
		void addDimension(const GLfloat& value);
		std::vector<GLfloat> GLArray();
	private:
		std::vector<GLfloat> coordinates;
	};
}

#endif
