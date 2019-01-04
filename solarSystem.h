//
// Created by tamas on 12/31/18.
//

#ifndef UNTITLED_SOLARSYSTEM_H
#define UNTITLED_SOLARSYSTEM_H

#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include "glm/glm/glm.hpp"
#include "body.h"
#include <vector>

class solarSystem {
	glm::dvec3 CenterOfMass;
	std::vector<body> bodies;
	public:
	solarSystem(const int & seed);
	void draw();
	void update();	
	void drawCoM();
};


#endif //UNTITLED_SOLARSYSTEM_H
