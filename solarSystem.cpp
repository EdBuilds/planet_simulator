//
// Created by tamas on 12/31/18.
//

#include "solarSystem.h"
#include <iostream>
solarSystem::solarSystem(const int & seed){
	srand(seed);
	for(int i=0;i<20;++i){
		glm::dvec3 position(rand()%20000/1000.0-10.0,rand()%20000/1000.0-10.0,rand()%20000/1000.0-10.0);
		glm::dvec3 velocity(rand()%20000/1000.0-10.0,rand()%20000/1000.0-10.0,rand()%20000/1000.0-10.0);
		glm::dvec3 rate(rand()%20000/100.0-100.0,rand()%20000/100.0-100.0,rand()%20000/100.0-100.0);
		
	bodies.push_back(body(position,velocity,glm::dvec3(0),rate,1E11, rand()%5+1));
	
	}
	bodies.push_back(body(glm::dvec3(0),glm::dvec3(0),glm::dvec3(0),glm::dvec3(0),1E13, 5));
}
void solarSystem::draw(){
   for(auto&& currentBody:bodies){
   glLoadIdentity();                 // Reset the model-view matrix
   gluLookAt(CenterOfMass.x,CenterOfMass.y,CenterOfMass.z-20,CenterOfMass.x,CenterOfMass.y,CenterOfMass.z,0,1,0);
      currentBody.draw();
   }
   glLoadIdentity();                 // Reset the model-view matrix
   gluLookAt(CenterOfMass.x,CenterOfMass.y,CenterOfMass.z-20,CenterOfMass.x,CenterOfMass.y,CenterOfMass.z,0,1,0);
	drawCoM();
}
void solarSystem::drawCoM(){

   glTranslated(CenterOfMass.x,CenterOfMass.y,CenterOfMass.z);  // Move right and into the screen
   glScalef(0.5,0.5,0.5); 
   glBegin(GL_LINES);
   glVertex3f(1,0,0);
   glVertex3f(-1,0,0);
   
   glVertex3f(0,1,0);
   glVertex3f(0,-1,0);

   glVertex3f(0,0,1);
   glVertex3f(0,0,-1);
   glEnd();	
}
void solarSystem::update(){
	for(int i=0; i<bodies.size()-1;++i){
		for(int j=i+1;j<bodies.size();++j){
		double distance=glm::distance(bodies[i].position,bodies[j].position);
		if(distance<0.1){
			bodies[i].merge(bodies[j]);
	                bodies.erase(bodies.begin()+j);
		}

		}
	}
	double smallestacc=500;
   for(int i=0; i<bodies.size()-1;++i){
      bodies[i].updateForces(bodies);
      if(0.01>glm::length(bodies[i].acceleration)){
	bodies.erase(bodies.begin()+i);
	std::cout<<"too far!"<<std::endl;
      }
   }
   
   for(auto&& currentBody:bodies){
      currentBody.updateStates(0.01);
   }
   double all_mass=0;
   CenterOfMass=glm::dvec3(0);
   for(auto&& currentBody:bodies){
	all_mass+=currentBody.mass;
	CenterOfMass+=currentBody.position*currentBody.mass;
   }
   CenterOfMass=CenterOfMass/all_mass;
}
