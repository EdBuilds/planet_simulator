//
// Created by tamas on 12/24/18.
//

#ifndef UNTITLED_BODY_H
#define UNTITLED_BODY_H

#include "solids.h"
#include <vector>
#include "glm/glm/glm.hpp" // glm::vec3

class body {
	public:
glm::dvec3 position;
glm::dvec3 velocity;
glm::dvec3 orientation;
glm::dvec3 rate;
double mass;
glm::dvec3 acceleration;

body(glm::dvec3 _position,glm::dvec3 _velocity, glm::dvec3 _orientation,glm::dvec3 _rate,double _mass);
void updateForces( std::vector<body> bodies);
void updateStates(double dt);
void draw();

};


#endif //UNTITLED_BODY_H
