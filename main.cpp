/*
 * OGL01Shape3D.cpp: 3D Shapes
 */
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include "glm/glm/glm.hpp"
#include "body.h" 
#include <vector>
#include "solarSystem.h"
/* Global variables */
char title[] = "3D Shapes";
std::vector<body> bodies;
solarSystem *celestials;
/* Initialize OpenGL Graphics */
void initGL() {
   glClearColor(0.15625f, 0.15625f,0.15625f, 1.0f); // Set background color to black and opaque
   glClearDepth(1.0f);                   // Set background depth to farthest
   glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
   glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
   glShadeModel(GL_SMOOTH);   // Enable smooth shading
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
   glPolygonMode( GL_FRONT_AND_BACK ,GL_LINE );
   glEnable( GL_BLEND );
   glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
 
/* Handler for window-repaint event. Called back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
   glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
   celestials->update();
   celestials->draw();
   glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}
 
/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
 
   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);
 
   // Set the aspect ratio of the clipping volume to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset
   // Enable perspective projection with fovy, aspect, zNear and zFar
   gluPerspective(45.0f, aspect, 0.1f, 1000.0f);
}

void timer(int value) {
   glutPostRedisplay();      // Post re-paint request to activate display()
   glutTimerFunc(10, timer, 0); // next timer call milliseconds later
}
/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
//	bodies.push_back(body(glm::dvec3(0,1,-3),glm::dvec3(0,3,-1),glm::dvec3(0),glm::dvec3(10),1E12));
//gluLookAt()
   celestials=new solarSystem(9);
   glutInit(&argc, argv);            // Initialize GLUT
   glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
   glutInitWindowSize(640, 480);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutCreateWindow(title);          // Create window with the given title
   glutDisplayFunc(display);       // Register callback handler for window re-paint event
   glutReshapeFunc(reshape);       // Register callback handler for window re-size event
   glutTimerFunc(0, timer, 0);     // First timer call immediately [NEW]
   initGL();                       // Our own OpenGL initialization
   glutMainLoop();                 // Enter the infinite event-processing loop
   return 0;
}
