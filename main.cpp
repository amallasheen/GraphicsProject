﻿//
//  main.cpp
//  GraphicsProject
//
//  Created by Amal Lasheen  on 11/27/15.
//  Copyright © 2015 Amal Lasheen . All rights reserved.
//

#include <iostream>
#include <glut.h>
#include <math.h>
void Display();
void Anim();
void drawWall(double,double,double);
void drawFirstCube();
void drawSecondCube();
void drawBorders();
double value = 10;
double xl = cos(value/60)*8;
double zl = sin(value/60)*8;
double yl = 3;
double eyeX = 0.0;
double eyeY = 20.0;
double eyeZ = 0.0;
double centerY = 0.0;
double centerX = 0.0;
double centerZ = 0.0;

void Key(unsigned char key, int x, int y);
void Display() {
     glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, 1000/1000, 0.1f, 300.0f);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
		gluLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, 0.0, 0.0, -1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glPushMatrix();
//    glColor3f(0, 1, 0);
//    glutSolidSphere(0.5, 50, 50);
//    glPopMatrix();
//    glPushMatrix();
//    glTranslatef(3, 0, 0);
//    glColor3f(1, 1, 0);
//    glutSolidSphere(0.5, 50, 50);
//    glPopMatrix();
//    glPushMatrix();
//    glTranslatef(0, 0, 6.55);
//    glColor3f(0, 1, 1);
//    glutSolidSphere(0.5, 50, 50);
//    glPopMatrix();
    
    glColor3f(1, 0, 0);
    drawBorders();
    
    //1st level
    drawFirstCube();
    //2nd level
    drawSecondCube();
    
   glFlush();
}

void Anim() {
    value+=1;
}
void drawWall(double x,double y,double z) {
    glColor3f(1, 0, 0);
    glPushMatrix();
    glTranslatef(x, y, z);
    //glRotated(-90, 0, 0, 1);
    glScaled(1.5, 2, 0.2);
    glutSolidCube(1);
    glPopMatrix();
}
void drawBorders() {
    //left wall
    glColor3f(1, 0, 0);
    glPushMatrix();
    glTranslatef(-7, 0, 0);
    glScaled(0.2, 3, 13);
    glutSolidCube(1);
    glPopMatrix();
    //right wall
    glColor3f(1, 0, 0);
    glPushMatrix();
    glTranslatef(7, 0, 0);
    glScaled(0.2, 3, 13);
    glutSolidCube(1);
    glPopMatrix();
    
    //top wall
    glColor3f(1, 0, 0);
    glPushMatrix();
    //glRotated(90, 0, 0, 1);
    glTranslatef(0, 0, -6.4);
    glRotated(-90, 0, 1, 0);
    glScaled(0.2, 3, 13.8);
    glutSolidCube(1);
    glPopMatrix();
    
    //floor left
    glColor3f(1, 0, 0);
    glPushMatrix();
    //glRotated(90, 0, 0, 1);
    glTranslatef(-4.63, 0, 6.45);
    glRotated(-90, 0, 1, 0);
    glScaled(0.2, 3, 5);
    glutSolidCube(1);
    glPopMatrix();
    
    //maze entrance coordinates are: x = 0 y = 0 z = 6.55
    //floor right
    glColor3f(1, 0, 0);
    glPushMatrix();
    //glRotated(90, 0, 0, 1);
    glTranslatef(4.63, 0, 6.55);
    glRotated(-90, 0, 1, 0);
    glScaled(0.2, 3, 5);
    glutSolidCube(1);
    glPopMatrix();

}
void drawFirstCube() {
    //left
    glColor3f(1, 0, 0);
    glPushMatrix();
    glTranslatef(-5, 0, 0);
    glScaled(0.2, 3, 8);
    glutSolidCube(1);
    glPopMatrix();
    //right
    glColor3f(1, 0, 0);
    glPushMatrix();
    glTranslatef(5, 0, 0);
    glScaled(0.2, 3, 8);
    glutSolidCube(1);
    glPopMatrix();
    //top right
    glColor3f(1, 0, 0);
    glPushMatrix();
    //glRotated(90, 0, 0, 1);
    glTranslatef(3.5, 0, -3.9);
    glRotated(-90, 0, 1, 0);
    glScaled(0.2, 3, 3);
    glutSolidCube(1);
    glPopMatrix();
    //top left
    glColor3f(1, 0, 0);
    glPushMatrix();
    //glRotated(90, 0, 0, 1);
    glTranslatef(-3.5, 0, -3.9);
    glRotated(-90, 0, 1, 0);
    glScaled(0.2, 3, 3);
    glutSolidCube(1);
    glPopMatrix();
    
    //bottom
    glColor3f(1, 0, 0);
    glPushMatrix();
    //glRotated(90, 0, 0, 1);
    glTranslatef(0, 0, 3.9);
    glRotated(-90, 0, 1, 0);
    glScaled(0.2, 3, 10);
    glutSolidCube(1);
    glPopMatrix();


}

void drawSecondCube() {
    // left up
    glColor3f(1, 0, 0);
    glPushMatrix();
    glTranslatef(-3, 0, -0.9);
    glScaled(0.2, 3, 3);
    glutSolidCube(1);
    glPopMatrix();
    
    // left down
    glColor3f(1, 0, 0);
    glPushMatrix();
    glTranslatef(-3, 0, 2.1);
    glScaled(0.2, 3, 1);
    glutSolidCube(1);
    glPopMatrix();
    
    //bottom
    glColor3f(1, 0, 0);
    glPushMatrix();
    //glRotated(90, 0, 0, 1);
    glTranslatef(0, 0, 2.5);
    glRotated(-90, 0, 1, 0);
    glScaled(0.2, 3, 6);
    glutSolidCube(1);
    glPopMatrix();
    
    //right
    glColor3f(1, 0, 0);
    glPushMatrix();
    glTranslatef(3, 0, 0.1);
    glScaled(0.2, 3, 5);
    glutSolidCube(1);
    glPopMatrix();
    
    glColor3f(1, 0, 0);
    glPushMatrix();
    //glRotated(90, 0, 0, 1);
    glTranslatef(0, 0, -2.3);
    glRotated(-90, 0, 1, 0);
    glScaled(0.2, 3, 6);
    glutSolidCube(1);
    glPopMatrix();

}


int main(int argc, char** argv) {
  
    glutInit(&argc, argv);
    
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(250, 250);
    
    glutCreateWindow("Maze");
    
    glutIdleFunc(Anim);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glutKeyboardFunc(Key);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glShadeModel(GL_SMOOTH);
    
	glutDisplayFunc(Display);
   // gluLookAt(0.0f, 20.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f);
	
//
//     glEnable(GL_LIGHTING);
//     glEnable(GL_LIGHT0);
//     
//     glLightf(GL_LIGHT0, GL_POSITION, 1.0f);
//     glLightf(GL_LIGHT0, GL_DIFFUSE, 1.0f);
//     glLightf(GL_LIGHT0, GL_AMBIENT, 1.0f);
//     glEnable(GL_NORMALIZE);
    
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

void Key(unsigned char key, int x, int y) {
if(key == 'k'){
eyeX = eyeX+0.01;
eyeY = eyeX;
eyeZ = eyeX;
}
if(key == 'l'){
eyeX = eyeX-0.01;
eyeY = eyeX;
eyeZ = eyeX;
}
if(key == 'w'){
centerY = centerY+0.05;
}
if(key == 's'){
centerY = centerY-0.05;
}
if(key == 'd'){
centerX = centerX+0.05;
}
if(key == 'a'){
centerX = centerX-0.05;
}
if(key == 't'){
centerY = centerY+0.05;
eyeY = eyeY+0.05;
}
if(key == 'g'){
centerY = centerY-0.05;
eyeY = eyeY-0.05;
}
if(key == 'h'){
centerX = centerX+0.05;
eyeX = eyeX+0.05;
centerZ = centerZ-0.05;
eyeZ = eyeZ-0.05;
}
if(key == 'f'){
centerX = centerX-0.05;
eyeX = eyeX-0.05;
centerZ = centerZ+0.05;
eyeZ = eyeZ+0.05;
}
// ask OpenGL to recall the display function to reflect the changes on the window
glutPostRedisplay();
}