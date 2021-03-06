//
// Created by tamas on 12/25/18.
//

#ifndef UNTITLED_SOLIDS_H
#define UNTITLED_SOLIDS_H

#include <GL/glut.h>
#include <vector>
#include "glm/glm/glm.hpp"

#define TETRAHEDRON_POINT_COUNT 4
#define TETRAHEDRON_LINE_COUNT 6
#define TETRAHEDRON_FACE_COUNT 4

#define OCTAHEDRON_POINT_COUNT 6
#define OCTAHEDRON_LINE_COUNT 12
#define OCTAHEDRON_FACE_COUNT 8

#define HEXAHEDRON_POINT_COUNT 8
#define HEXAHEDRON_LINE_COUNT 12
#define HEXAHEDRON_FACE_COUNT 6
#define HEXAHEDRON_TRIANGLE_FACE_COUNT 12  // OpenGL ES can only render triangles

#define ICOSAHEDRON_POINT_COUNT 12
#define ICOSAHEDRON_LINE_COUNT 30
#define ICOSAHEDRON_FACE_COUNT 20

#define DODECAHEDRON_POINT_COUNT 20
#define DODECAHEDRON_LINE_COUNT 30
#define DODECAHEDRON_FACE_COUNT 12
#define DODECAHEDRON_TRIANGLE_FACE_COUNT 36

enum solid_types{
	POINT=0,
	TETRAHEDRON,
	OCTAHEDRON,
	HEXAHEDRON,
	ICOSAHEDRON,
	DODECAHEDRON
};

	static constexpr float _tetrahedron_points[TETRAHEDRON_POINT_COUNT*3] = { 
	1.0,                 0.0,               0.0,               
	-0.333333333333333, -0.942809041582063, 0.0,               
	-0.333333333333333,  0.471404520791032, 0.816496580927726, 
	-0.333333333333333,  0.471404520791032, -0.816496580927726};

	static constexpr unsigned short _tetrahedron_faces[TETRAHEDRON_FACE_COUNT*3] = {
	2, 1, 3,  
	2, 3, 0,  
	2, 0, 1,  
	3, 1, 0};

static constexpr unsigned short _tetrahedron_lines[TETRAHEDRON_LINE_COUNT*2] = {
	2, 3, 2, 0, 2, 1, 3, 0, 3, 1, 0, 1};

static constexpr float _octahedron_points[OCTAHEDRON_POINT_COUNT*3] = {
	1.0, 0.0, 0.0,
	0.0, 1.0, 0.0,
	0.0, 0.0, 1.0,
	-1.0, 0.0, 0.0,
	0.0, -1.0, 0.0,
	0.0, 0.0, -1.0};	
static constexpr unsigned short _octahedron_faces[OCTAHEDRON_FACE_COUNT*3] = {
	1, 0, 2,
	1, 5, 0,
	4, 0, 5,
	4, 2, 0,
	1, 2, 3,
	1, 3, 5,
	4, 5, 3,
	4, 3, 2};

static constexpr unsigned short _octahedron_lines[OCTAHEDRON_LINE_COUNT*2] = {
	1, 0, 1, 2, 1, 5, 1, 3, 3, 2, 2, 0, 0, 5, 5, 3, 4, 2, 4, 3, 4, 5, 4, 0};

static constexpr float _hexahedron_points[HEXAHEDRON_POINT_COUNT*3] = {
	0.57735026918963, 0.57735026918963, 0.57735026918963,
	0.57735026918963, 0.57735026918963, -0.57735026918963,
	0.57735026918963, -0.57735026918963, -0.57735026918963,
	0.57735026918963, -0.57735026918963, 0.57735026918963,
	-0.57735026918963, 0.57735026918963, 0.57735026918963,
	-0.57735026918963, 0.57735026918963, -0.57735026918963,
	-0.57735026918963, -0.57735026918963, -0.57735026918963,
	-0.57735026918963, -0.57735026918963, 0.57735026918963};

static constexpr unsigned short _hexahedron_triangle_faces[HEXAHEDRON_TRIANGLE_FACE_COUNT*3] = {
	0, 2, 3,
	2, 0, 1,
	4, 1, 0,
	1, 4, 5,
	0, 3, 7,
	7, 4, 0,
	7, 5, 4,
	5, 7, 6,
	3, 6, 7,
	6, 3, 2,
	1, 5, 6,
	6, 2, 1};

static constexpr unsigned short _hexahedron_lines[HEXAHEDRON_LINE_COUNT*2] = {
	0, 1, 1, 2, 2, 3, 3, 0, 0, 4, 1, 5, 2, 6, 3, 7, 4, 5, 5, 6, 6, 7, 7, 4};

static constexpr float _icosahedron_points[ICOSAHEDRON_POINT_COUNT*3] = {
	0.447213595499958, -0.276393202250021, 0.850650808352040,
	-0.447213595499958, 0.276393202250021, 0.850650808352040,
	-0.447213595499958, 0.276393202250021, -0.850650808352040,
	0.447213595499958, -0.276393202250021, -0.850650808352040,
	-0.447213595499958, -0.723606797749979, 0.525731112119134,
	0.447213595499958, 0.723606797749979, 0.525731112119134,
	0.447213595499958, 0.723606797749979, -0.525731112119134,
	-0.447213595499958, -0.723606797749979, -0.525731112119134,
	0.447213595499958, -0.894427190999916, 0.0,
	1.0,                0.0,               0.0,
	-0.447213595499958, 0.894427190999916, 0.0,
	-1.0,               0.0,               0.0};

static constexpr unsigned short _icosahedron_faces[ICOSAHEDRON_FACE_COUNT*3] = { 
	8, 7, 4, 
	7, 8, 3,    // pair 2 
	8, 4, 0, 
	8, 0, 9, 
	9, 3, 8, 
	9, 0, 5, 
	9, 5, 6, 
	9, 6, 3, 
	3, 2, 7,   // pair 2
	3, 6, 2, 
	0, 4, 1, 
	0, 1, 5, 
	11, 4, 7, 
	11, 7, 2, 
	11, 2, 10, 
	1, 11, 10,    // pair 1
	11, 1, 4, 
	10, 6, 5, 
	10, 5, 1,     // pair 1
	10, 2, 6};

static constexpr unsigned short _icosahedron_lines[ICOSAHEDRON_LINE_COUNT*2] = {
	0, 8, 0, 9, 0, 1, 0, 4, 0, 5, 8, 3, 8, 9, 8, 7, 8, 4, 9, 3,
	9, 6, 9, 5, 7, 4, 7, 3, 7, 2, 7, 11, 2, 10, 2, 11, 2, 3, 2, 6,
	10, 11, 10, 5, 10, 6, 10, 1, 11, 1, 11, 4, 4, 1, 5, 1, 5, 6, 6, 3};

static constexpr float _dodecahedron_points[DODECAHEDRON_POINT_COUNT * 3] = {
	-0.794655, 0.491123, 0.356822,
	-0.187593, 0.794654, -0.577350,
	-0.794655, 0.491123, -0.356822,
	-0.794654, -0.187593, -0.577350,
	0.187592, 0.303531, -0.934172,
	0.187592, 0.982247, 0.000000,
	0.187593, -0.794654, -0.577350,
	-0.187592, -0.303531, -0.934172,
	-0.187592, -0.982247, 0.000000,
	-0.794654, -0.607062, 0.000000,
	0.794655, -0.491123, -0.356822,
	0.187593, -0.794654, 0.577350,
	-0.187592, -0.303531, 0.934172,
	-0.794654, -0.187593, 0.577350,
	0.794655, -0.491123, 0.356822,
	-0.187593, 0.794654, 0.577350,
	0.187592, 0.303531, 0.934172,
	0.794654, 0.187593, 0.577350,
	0.794654, 0.607062, 0.000000,
	0.794654, 0.187593, -0.577350 };
static constexpr unsigned short _dodecahedron_triangle_faces[DODECAHEDRON_TRIANGLE_FACE_COUNT * 3] = {
	5, 2, 1,
	15, 0, 5,
	2, 5, 0,

	9, 2, 13,
	2, 0, 13,
	3, 2, 9,

	10, 17, 19,
	18, 19, 17,
	14, 17, 10,

	19, 1,  4,
	6, 9, 8,   
	1, 18, 5, 

	11, 14, 8, 
	18, 1, 19,
	8, 9, 11,

	10, 8, 14,
	8, 10, 6, 
	6, 7, 9,

	9, 7, 3,
	13, 12, 9,
	12, 11, 9,

	18, 15, 5,
	17, 15, 18,
	15, 17, 16,

	11, 12, 14,
	14, 12, 17,
	17, 12, 16,

	12, 13, 16,
	13, 0, 16,
	0,  15, 16,

	7, 2, 3,
	2, 7, 1,
	1, 7, 4,

	4, 7,  19,
	19, 7, 10,
	6, 10, 7 };

static constexpr unsigned short _dodecahedron_lines[DODECAHEDRON_LINE_COUNT * 2] = {
	19, 18,
	18, 17,
	17, 14,
	14, 10,
	10, 19,
	14, 11,
	11, 8,
	8, 6,
	6, 10,
	19, 4,
	4, 1,
	1, 5,
	5, 18,
	9, 3,
	3, 7,
	7, 6,
	8, 9,
	13, 9,
	3, 2,
	2, 0,
	0, 13,
	12, 11,
	12, 13,
	1, 2,
	5, 15,
	15, 0,
	15, 16,
	16, 17,
	16, 12,
	4, 7 };

class Solids {
	public:
unsigned short solid_type;
void draw();

Solids(const unsigned short &  _solid_type);
Solids();
Solids& operator=(Solids&&)=default;
Solids& operator=(const Solids&)=default;
Solids(const Solids& solid);
};


#endif //UNTITLED_SOLIDS_H
