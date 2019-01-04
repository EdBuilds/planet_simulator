//
// Created by tamas on 12/24/18.
//

#include "body.h"
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <iostream>
#include <math.h>
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
	trail[trail_head]=position;
	trail_head=(trail_head+1)%TRAIL_LENGHT;
}

body::body(glm::dvec3 _position, glm::dvec3 _velocity,glm::dvec3 _orientation, glm::dvec3 _rate,double _mass, unsigned short _solid_type){
	position=_position;
	velocity=_velocity;
	orientation=_orientation;
	rate=_rate;
	mass=_mass;
acceleration=glm::dvec3(0);
velocity=_velocity;
solid.solid_type=_solid_type;
scale=0.5;
for(int i=0;i<TRAIL_LENGHT;++i){
	trail[i]=_position;
}
trail_head=0;
}
body::body(){
acceleration=glm::dvec3(0);
scale=0.5;
};

void body::draw() {
glBegin(GL_LINES);
float alpha=0.0;
for(int i=(trail_head+1)%TRAIL_LENGHT;i!=trail_head;i=(i+1)%TRAIL_LENGHT){
	   glColor4f(1,1,1,alpha);
	glVertex3f(trail[i].x,trail[i].y,trail[i].z);	
	alpha+=1.0/TRAIL_LENGHT;
}
glEnd();

   glTranslated(position.x,position.y,position.z);  // Move right and into the screen
   glRotated(orientation.x,1,0,0);
   glRotated(orientation.y,0,1,0);
   glRotated(orientation.z,0,0,1);
   glScaled(scale,scale,scale); 
	   glColor4f(1,1,1,1);
   solid.draw();
   
}
void body::merge(const body &other){
	velocity=(velocity*mass+other.velocity*other.mass)/(mass+other.mass);
	rate=(rate*mass+other.rate*other.mass)/(mass+other.mass);
	mass+=other.mass;
//	scale=cbrt(mass)/100000;
	solid.solid_type=rand()%4+1;	
	std::cout<<"collision! scale"<<scale<<" type:"<<solid.solid_type<<std::endl;	
}

body::body(const body& bod){
position=bod.position;
velocity=bod.velocity;
orientation=bod.orientation;
rate=bod.rate;
mass=bod.mass;
acceleration=bod.acceleration;
solid.solid_type=bod.solid.solid_type;
scale=bod.scale;
for(int i=0;i<TRAIL_LENGHT;++i){
	trail[i]=bod.trail[i];
}
trail_head=bod.trail_head;
}

