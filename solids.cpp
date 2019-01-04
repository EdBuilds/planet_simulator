//
// Created by tamas on 12/25/18.
//

#include "solids.h"
Solids::Solids(const unsigned short & _solid_type){
	solid_type=_solid_type;
}
Solids::Solids(){
	solid_type=1;
}
void Solids::draw(){
	switch(solid_type){
		case POINT:
		glBegin(GL_POINTS);
		glVertex3f(0,0,0);
		break;
		case DODECAHEDRON:
		glBegin(GL_LINES);
		for(int i=0; i<DODECAHEDRON_LINE_COUNT; ++i){
			for(int j=0;j<2;++j){
				unsigned short vertex=_dodecahedron_lines[i*2+j];
				glVertex3f(_dodecahedron_points[vertex*3+0],_dodecahedron_points[vertex*3+1],_dodecahedron_points[vertex*3+2]);	
			}
		}
		break;
		case ICOSAHEDRON:
		glBegin(GL_LINES);
			for(int i=0; i<ICOSAHEDRON_LINE_COUNT; ++i){
				for(int j=0;j<2;++j){
					unsigned short vertex=_icosahedron_lines[i*2+j];
				glVertex3f(_icosahedron_points[vertex*3+0],_icosahedron_points[vertex*3+1],_icosahedron_points[vertex*3+2]);	
			}
		}
		break;
		case HEXAHEDRON:
		glBegin(GL_LINES);
		for(int i=0; i<HEXAHEDRON_LINE_COUNT; ++i){
			for(int j=0;j<2;++j){
				unsigned short vertex=_hexahedron_lines[i*2+j];
				glVertex3f(_hexahedron_points[vertex*3+0],_hexahedron_points[vertex*3+1],_hexahedron_points[vertex*3+2]);	
			}
		}
		break;
		case OCTAHEDRON:
		glBegin(GL_LINES);
		for(int i=0; i<OCTAHEDRON_LINE_COUNT; ++i){
			for(int j=0;j<2;++j){
				unsigned short vertex=_octahedron_lines[i*2+j];
				glVertex3f(_octahedron_points[vertex*3+0],_octahedron_points[vertex*3+1],_octahedron_points[vertex*3+2]);	
			}
		}
		break;
		case TETRAHEDRON:
		glBegin(GL_LINES);
		for(int i=0; i<TETRAHEDRON_LINE_COUNT; ++i){
			for(int j=0;j<2;++j){
				unsigned short vertex=_tetrahedron_lines[i*2+j];
				glVertex3f(_tetrahedron_points[vertex*3+0],_tetrahedron_points[vertex*3+1],_tetrahedron_points[vertex*3+2]);	
			}
		}
		break;
	}
	glEnd();	
}
Solids::Solids(const Solids& solid){
	solid_type=solid.solid_type;
}
