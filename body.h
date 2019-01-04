//
// Created by tamas on 12/24/18.
//

#ifndef UNTITLED_BODY_H
#define UNTITLED_BODY_H

#include "solids.h"
#include <vector>
#include "glm/glm/glm.hpp" // glm::vec3

static const int TRAIL_LENGHT=200;
class body {
	public:
glm::dvec3 position;
glm::dvec3 velocity;
glm::dvec3 orientation;
glm::dvec3 rate;
double mass;
double scale;
glm::dvec3 acceleration;
Solids solid;
glm::dvec3 trail[TRAIL_LENGHT];
int trail_head;
body(glm::dvec3 _position,glm::dvec3 _velocity, glm::dvec3 _orientation,glm::dvec3 _rate,double _mass, unsigned short _solid_type);
body();
body& operator=(body&&)=default;
body(const body& bod);
void updateForces( std::vector<body> bodies);
void updateStates(double dt);
void draw();
void merge(const body & other);
};


#endif //UNTITLED_BODY_H
