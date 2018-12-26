//
// Created by tamas on 12/24/18.
//

#include "body.h"
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <iostream>
static const double G= 6.6740831E-11;
static const double MinCollDist= 1E-20;

void body::updateForces( std::vector<body>  bodies){
	acceleration=glm::dvec3(0);
	for(auto currentBody:bodies){
		double distance=glm::distance(this->position,currentBody.position);
		if(distance>MinCollDist){
		acceleration-=glm::normalize(this->position-currentBody.position)*(G*currentBody.mass/distance/distance);
		}
	}
}

void body::updateStates(double dt){
	velocity+=dt*acceleration;
	position+=dt*velocity;
	orientation+=dt*rate;
}

body::body(glm::dvec3 _position, glm::dvec3 _velocity,glm::dvec3 _orientation, glm::dvec3 _rate,double _mass){
	position=_position;
	velocity=_velocity;
	orientation=_orientation;
	rate=_rate;
	mass=_mass;
acceleration=glm::dvec3(0);
velocity=_velocity;
}

void body::draw() {
   // Render a color-cube consisting of 6 quads with different colors
   glLoadIdentity();                 // Reset the model-view matrix
   glTranslated(position.x,position.y,position.z);  // Move right and into the screen
   glRotated(orientation.x,1,0,0);
   glRotated(orientation.y,0,1,0);
   glRotated(orientation.z,0,0,1);
  glScalef(0.1,0.1,0.1); 

   glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
   // Top face (y = 1.0f)
   // Define vertices in counter-clockwise (CCW) order with normal pointing out
   glColor3f(0.0f, 1.0f, 0.0f);     // Green
   glVertex3f(1.0f, 1.0f, -1.0f);
   glVertex3f(-1.0f, 1.0f, -1.0f);
   glVertex3f(-1.0f, 1.0f, 1.0f);
   glVertex3f(1.0f, 1.0f, 1.0f);

   // Bottom face (y = -1.0f)
   glColor3f(1.0f, 0.5f, 0.0f);     // Orange
   glVertex3f(1.0f, -1.0f, 1.0f);
   glVertex3f(-1.0f, -1.0f, 1.0f);
   glVertex3f(-1.0f, -1.0f, -1.0f);
   glVertex3f(1.0f, -1.0f, -1.0f);

   // Front face  (z = 1.0f)
   glColor3f(1.0f, 0.0f, 0.0f);     // Red
   glVertex3f(1.0f, 1.0f, 1.0f);
   glVertex3f(-1.0f, 1.0f, 1.0f);
   glVertex3f(-1.0f, -1.0f, 1.0f);
   glVertex3f(1.0f, -1.0f, 1.0f);

   // Back face (z = -1.0f)
   glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
   glVertex3f(1.0f, -1.0f, -1.0f);
   glVertex3f(-1.0f, -1.0f, -1.0f);
   glVertex3f(-1.0f, 1.0f, -1.0f);
   glVertex3f(1.0f, 1.0f, -1.0f);

   // Left face (x = -1.0f)
   glColor3f(0.0f, 0.0f, 1.0f);     // Blue
   glVertex3f(-1.0f, 1.0f, 1.0f);
   glVertex3f(-1.0f, 1.0f, -1.0f);
   glVertex3f(-1.0f, -1.0f, -1.0f);
   glVertex3f(-1.0f, -1.0f, 1.0f);

   // Right face (x = 1.0f)
   glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
   glVertex3f(1.0f, 1.0f, -1.0f);
   glVertex3f(1.0f, 1.0f, 1.0f);
   glVertex3f(1.0f, -1.0f, 1.0f);
   glVertex3f(1.0f, -1.0f, -1.0f);
   glEnd();  // End of drawing color-cube
}
