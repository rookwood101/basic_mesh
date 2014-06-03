libbasic_mesh
=============

Summary
-------
A library for representing simple meshes, of any dimension in any dimension.

Features
--------
* Various Primitives
	- Point
	- Vertex (A collection of points representing vertex properties, for example you could have a vertex with one point for the position and one for the normal)
	- Polygon (A collection of vertices)
	- Polyhedron (A collection of Polygons, although the name is a bit misleading in that these polygons do not have to connect)
* Compile to library for easy usage
* Vertex properties
* N-gons
* Easy Conversion to opengl compatible arrays
* Only header needed is opengl

Usage
-----
This is setup to work with linux, you'll need to figure out windows on your own (I recommend using mingw to make it similar to linux)

* Set environment settings (e.g. CXXFLAGS) in main.mk
* make
* copy includes to relevant directory for your environment
* copy libbasic_mesh.a to relevant directory
