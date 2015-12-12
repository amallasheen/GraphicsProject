//
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
void drawFirstCube();
void drawSecondCube();
void drawThirdCube();
void drawAddlevel2();
void drawAddlevel1();
void drawMaze();
void drawHome(double x,double y,double z);
void drawBorders();
//Maze is drawn in the XZ plane and each wall height is 3 ie y = 3
void Key(unsigned char key, int x, int y);
int sign = 0;
char dir1 = ' ';
int dir2 = 0;
double eyeX = 2.0;
double eyeY = -1.0;
double eyeZ = 1.0;
double centerY = -1.0;
double centerX = -8.0;
double centerZ = 1.0;
double temp = 0.0;
int direction = 0;
int stop_walking = 0;
double temp_center = 0.0;
double temp_eye = 0.0;
int color_effect = 0;
double color_effect_counter = 0.0;
void drawSphere();
void handleRight();
void handleLeft();
double speed = 0.0003;
double speed_multiplier=1.5;
double drunk_var1 = 0.0; int drunk_check1 = 0;
double drunk_var2 = 0.0; int drunk_check2 = 0;
void Display() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.0f, 1000/1000, 0.01f, 300.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, drunk_var1, 1.0, drunk_var2);
    /*GLfloat  light_pos[4] = {eyeX, -1.0, eyeZ, 1.0f};
    GLfloat spotDir[3] = {centerX*10, -1.0, centerZ*10};
    GLfloat diffuse[4] = {0, 0, 1, 1.0};
    GLfloat ambient[4] = {1.0, 1.0, 1.0, 1.0};
    GLfloat specular[4] = {1.0, 1.0, 1.0, 1.0};*/
    /*glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glShadeModel(GL_SMOOTH);
    //glLightModelfv(GL_LIGHT_MODEL_AMBIENT, diffuse);
    glLightfv (GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv (GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
    glLightfv (GL_LIGHT0, GL_POSITION, light_pos);
    glLightfv (GL_LIGHT0, GL_SPOT_DIRECTION, spotDir);
    glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 20.0);
    glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 100);
    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION,1.0);
    */
    


    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //these spheres just to define the +ve x and +ve z directions
//        glPushMatrix();
//        glColor3f(0, 1, 0);
//        glutSolidSphere(0.5, 50, 50);
//        glPopMatrix();
//        glPushMatrix();
//        glTranslatef(3, 0, 0);
//        glColor3f(1, 1, 0);
//        glutSolidSphere(0.5, 50, 50);
//        glPopMatrix();
//        glPushMatrix();
//        glTranslatef(0, 0, 6.55);
//        glColor3f(0, 1, 1);
//        glutSolidSphere(0.5, 50, 50);
//        glPopMatrix();
    drawMaze();
    drawHome(-3.52,3.5,11);
    drawSphere();
    glFlush();
}
void drawSphere(){

    switch(color_effect){
    case 0: glColor3f(1, 1, 1);break;
    case 1: glColor3f(0, 1, 0);break;
    case 2: glColor3f(0, 0, 1);break;
    case 3: glColor3f(1, 0, 0);break;
    }
    
    glPushMatrix();
    glTranslatef(eyeX+((centerX-eyeX)/30.0), -1.0, eyeZ+((centerZ-eyeZ)/30.0));
    glutSolidSphere(0.01,8,10);
    glPopMatrix();


}
void drawMaze() {
    drawAddlevel2();
    drawAddlevel1();
    drawBorders();
    //1st level
    drawFirstCube();
    //2nd level
    drawSecondCube();
    //3rd level
    //drawThirdCube();
}
void drawHome(double x, double y, double z) {
    glColor3f(1, 0, 1);
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(5, 10, 1);
    glutSolidCube(1);
    glPopMatrix();
}
void drawAddlevel2() {
    //left
    glColor3f(1, 0, 0);
    glPushMatrix();
    glTranslatef(-11, 0, 0);
    glScaled(0.2, 3, 21);
    glutSolidCube(1);
    glPopMatrix();
    //right
    glPushMatrix();
    glTranslatef(11, 0, 0);
    glScaled(0.2, 3, 21);
    glutSolidCube(1);
    glPopMatrix();
    //top
    glPushMatrix();
    //glRotated(90, 0, 0, 1);
    glTranslatef(0, 0, -10.4);
    glRotated(-90, 0, 1, 0);
    glScaled(0.2, 3, 22);
    glutSolidCube(1);
    glPopMatrix();
    //floor left
    glPushMatrix();
    //glRotated(90, 0, 0, 1);
    glTranslatef(-8.5, 0, 10.45);
    glRotated(-90, 0, 1, 0);
    glScaled(0.2, 3, 5);
    glutSolidCube(1);
    glPopMatrix();
    //floor right
    glPushMatrix();
    //glRotated(90, 0, 0, 1);
    glTranslatef(5, 0, 10.45);
    glRotated(-90, 0, 1, 0);
    glScaled(0.2, 3, 12);
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
    //glColor3f(1, 0, 0);
    glPushMatrix();
    glTranslatef(7, 0, 0);
    glScaled(0.2, 3, 13);
    glutSolidCube(1);
    glPopMatrix();
    //top wall
    //glColor3f(1, 0, 0);
    glPushMatrix();
    //glRotated(90, 0, 0, 1);
    glTranslatef(0, 0, -6.4);
    glRotated(-90, 0, 1, 0);
    glScaled(0.2, 3, 13.8);
    glutSolidCube(1);
    glPopMatrix();
    //floor left
    //glColor3f(1, 0, 0);
    glPushMatrix();
    //glRotated(90, 0, 0, 1);
    glTranslatef(-4.63, 0, 6.45);
    glRotated(-90, 0, 1, 0);
    glScaled(0.2, 3, 5);
    glutSolidCube(1);
    glPopMatrix();
    //maze entrance coordinates are: x = 0 y = 0 z = 6.55
    //floor right
    //glColor3f(1, 0, 0);
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
    //glColor3f(1, 0, 0);
    glPushMatrix();
    glTranslatef(-3, 0, 2.1);
    glScaled(0.2, 3, 1);
    glutSolidCube(1);
    glPopMatrix();
    //bottom
    //glColor3f(1, 0, 0);
    glPushMatrix();
    //glRotated(90, 0, 0, 1);
    glTranslatef(0, 0, 2.5);
    glRotated(-90, 0, 1, 0);
    glScaled(0.2, 3, 6);
    glutSolidCube(1);
    glPopMatrix();
    //right
    //glColor3f(1, 0, 0);
    glPushMatrix();
    glTranslatef(3, 0, 0.1);
    glScaled(0.2, 3, 5);
    glutSolidCube(1);
    glPopMatrix();
    //glColor3f(1, 0, 0);
    glPushMatrix();
    //glRotated(90, 0, 0, 1);
    glTranslatef(0, 0, -2.3);
    glRotated(-90, 0, 1, 0);
    glScaled(0.2, 3, 6);
    glutSolidCube(1);
    glPopMatrix();
}
void drawThirdCube() {
    //bottom
    glColor3f(1, 0, 0);
    glPushMatrix();
    //glRotated(90, 0, 0, 1);
    glTranslatef(0, 0, 1.5);
    glRotated(-90, 0, 1, 0);
    glScaled(0.2, 3, 3);
    glutSolidCube(1);
    glPopMatrix();
    //left
    glColor3f(1, 0, 0);
    glPushMatrix();
    glTranslatef(-1.4, 0, 0.25);
    glScaled(0.2, 3, 2.5);
    glutSolidCube(1);
    glPopMatrix();
    //top
    glColor3f(1, 0, 0);
    glPushMatrix();
    //glRotated(90, 0, 0, 1);
    glTranslatef(0, 0, -1);
    glRotated(-90, 0, 1, 0);
    glScaled(0.2, 3, 3);
    glutSolidCube(1);
    glPopMatrix();
    //right
    glPushMatrix();
    glTranslatef(1.4, 0, -0.5);
    glScaled(0.2, 3, 1);
    glutSolidCube(1);
    glPopMatrix();
}
void drawAddlevel1() {
    glColor3f(1, 0, 0);
    //left
    glPushMatrix();
    glTranslatef(-9, 0, 0);
    glScaled(0.2, 3, 17);
    glutSolidCube(1);
    glPopMatrix();
    //right
    glPushMatrix();
    glTranslatef(9, 0, 0);
    glScaled(0.2, 3, 17);
    glutSolidCube(1);
    glPopMatrix();
    //top right
    glColor3f(1, 0, 0);
    glPushMatrix();
    //glRotated(90, 0, 0, 1);
    glTranslatef(7.5, 0, -8.4);
    glRotated(-90, 0, 1, 0);
    glScaled(0.2, 3, 3);
    glutSolidCube(1);
    glPopMatrix();
    //top left
    glColor3f(1, 0, 0);
    glPushMatrix();
    //glRotated(90, 0, 0, 1);
    glTranslatef(-4.1, 0, -8.5);
    glRotated(-90, 0, 1, 0);
    glScaled(0.2, 3, 10);
    glutSolidCube(1);
    glPopMatrix();
    //bottom
    glPushMatrix();
    //glRotated(90, 0, 0, 1);
    glTranslatef(0, 0, 8.4);
    glRotated(-90, 0, 1, 0);
    glScaled(0.2, 3, 17.75);
    glutSolidCube(1);
    glPopMatrix();
}
/*                                            Maze code ends here                             */
// Anim method here
void Anim() {
    if(drunk_var1 >= 0.3 || drunk_check1 == 1){
        drunk_check1 = 1;
        drunk_var1 -= 0.00002*speed_multiplier;
        if(drunk_var1 <= -0.3){
            drunk_check1 = 0;
        }
    }else{
        drunk_var1 += 0.00002*speed_multiplier;
    }
    if(drunk_var2 >= 0.3 || drunk_check2 == 1){
        drunk_check2 = 1;
        drunk_var2 -= 0.00002*speed_multiplier;
        if(drunk_var2 <= -0.3){
            drunk_check2 = 0;
        }
    }else{
        drunk_var2 += 0.00002*speed_multiplier;
    }
    
    
    color_effect_counter+=0.001*speed_multiplier;
    if(color_effect_counter >= 30){
        if(color_effect == 0)
            color_effect = (int)(rand() % 3)+1;
        else 
            color_effect = 0;
        color_effect_counter = 0.0;
    }
    switch(color_effect){
    case 0: speed = 0.0003;break;
    case 1: speed = 0.0003;break;
    case 2: speed = 0.0001;break;
    case 3: speed = 0.0006;break;
    }
    // MOVEMENT CODE START
    if(stop_walking == 0){
        switch(direction){
            case 0:centerX-=speed*speed_multiplier;eyeX-=speed*speed_multiplier;break;
            case 1:centerZ-=speed*speed_multiplier;eyeZ-=speed*speed_multiplier;break;
            case 2:centerX+=speed*speed_multiplier;eyeX+=speed*speed_multiplier;break;
            case 3:centerZ+=speed*speed_multiplier;eyeZ+=speed*speed_multiplier;break;
        }
        }else{
        if(sign == 1 && dir1=='x'){
            centerX+=0.01*speed_multiplier;
            if(dir2 == 1){
                centerZ-=0.01*speed_multiplier;
                }else{
                centerZ+=0.01*speed_multiplier;
            }
            if(centerX>=eyeX+10){
                stop_walking = 0;
                centerX = eyeX+10;
                centerZ = eyeZ;
            }
            }else{
            if(sign == -1 && dir1 == 'x'){
                centerX-=0.01*speed_multiplier;
                if(dir2 == 1){
                    centerZ+=0.01*speed_multiplier;
                    }else{
                    centerZ-=0.01*speed_multiplier;
                }
                if(centerX<=eyeX-10){
                    stop_walking = 0;
                    centerX = eyeX-10;
                    centerZ = eyeZ;
                }
                }else{
                if(sign == 1 && dir1 == 'z'){
                    centerZ+=0.01*speed_multiplier;
                    if(dir2 == 1){
                        centerX+=0.01*speed_multiplier;
                        }else{
                        centerX-=0.01*speed_multiplier;
                    }
                    if(centerZ>=eyeZ+10){
                        stop_walking = 0;
                        centerZ = eyeZ+10;
                        centerX = eyeX;
                    }
                    }else{
                    if(sign == -1 && dir1 == 'z'){
                        centerZ-=0.01*speed_multiplier;
                        if(dir2 == 1){
                            centerX-=0.01*speed_multiplier;
                            }else{
                            centerX+=0.01*speed_multiplier;
                        }
                        if(centerZ<=eyeZ-10){
                            stop_walking = 0;
                            centerZ = eyeZ-10;
                            centerX = eyeX;
                        }
                    }
                }
            }
        }
    }
    // MOVEMENT CODE END
    glutPostRedisplay();
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(250, 250);
    glutCreateWindow("Maze");
    
    glutDisplayFunc(Display);
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
    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    //gluPerspective(45.0f, 1000/1000, 0.1f, 300.0f);
    //glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();
    //gluLookAt(0.0f, 30.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f);
    
    
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

    if(key == 'd' || key == 'D'){
        if(color_effect == 1)
            handleLeft();
        else
            handleRight();
    }
    if(key == 'a' || key == 'A'){
        if(color_effect == 1)
            handleRight();
        else
            handleLeft();
    }
    glutPostRedisplay();
}
void handleRight(){
    switch(direction){
            case 0:
                stop_walking = 1;
                sign = -1;
                dir1 = 'z';
                dir2 = 0;
                direction = 1;
                break;
            case 1:
                stop_walking = 1;
                sign = 1;
                dir1 = 'x';
                dir2 = 0;
                direction = 2;
                break;
            case 2:
                stop_walking = 1;
                sign = 1;
                dir1 = 'z';
                dir2 = 0;
                direction = 3;
                break;
            case 3:
                stop_walking = 1;
                sign = -1;
                dir1 = 'x';
                dir2 = 0;
                direction = 0;
                break;
        }
}
void handleLeft(){
    switch(direction){
                case 0:
                stop_walking = 1;
                sign = 1;
                dir1 = 'z';
                dir2 = 1;
                direction = 3;
                break;
            case 1:
                stop_walking = 1;
                sign = -1;
                dir1 = 'x';
                dir2 = 1;
                direction = 0;
                break;
            case 2:
                stop_walking = 1;
                sign = -1;
                dir1 = 'z';
                dir2 = 1;
                direction = 1;
                break;
            case 3:
                stop_walking = 1;
                sign = 1;
                dir1 = 'x';
                dir2 = 1;
                direction = 2;
                break;
        }
}
