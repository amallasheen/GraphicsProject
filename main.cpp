//
//  main.cpp
//  GraphicsProject
//
//  Created by Amal Lasheen  on 11/27/15.
//  Copyright © 2015 Amal Lasheen . All rights reserved.
//

#include <iostream>
#include <GLUT/glut.h>
void Display();
void Anim();

void Display() {
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glFlush();
}

void Anim() {
    
}

int main(int argc, char** argv) {
  
    glutInit(&argc, argv);
    
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(250, 250);
    
    glutCreateWindow("Maze");
    glutDisplayFunc(Display);
    glutIdleFunc(Anim);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    
    glEnable(GL_DEPTH_TEST);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, 800 / 600, 0.1f, 300.0f);
    
     glEnable(GL_LIGHTING);
     glEnable(GL_LIGHT0);
     
     glLightf(GL_LIGHT0, GL_POSITION, 1.0f);
     glLightf(GL_LIGHT0, GL_DIFFUSE, 1.0f);
     glLightf(GL_LIGHT0, GL_AMBIENT, 1.0f);
     glEnable(GL_NORMALIZE);
    
    // Enable Lighting for this OpenGL Program
    //  glEnable(GL_LIGHTING);
    // Enable Light Source number 0
    // OpengL has 8 light sources
    //glEnable(GL_LIGHT0);
    // Define Light source 0 ambient light
    //GLfloat ambient[]={0.1f, 0.1f, 0.1, 1.0f};
    //glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    // Define Light source 0 diffuse light
    //GLfloat diffuse[]={0.7f, 0.7f, 0.7f, 1.0f};
    //glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    // Define Light source 0 Specular light
    //GLfloat specular[]={1.0f, 1.0f, 1.0f, 1.0f};
    //glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
    // Finally, define light source 0 position in World Space
    //GLfloat light_position[] = {8.0f, 8.0f, 8.0f, 0.0f};
    //glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    //glShadeModel(GL_SMOOTH);
    
    
    glutMainLoop();
}
