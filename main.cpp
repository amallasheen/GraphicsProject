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
void drawHome(double x, double y, double z);
void drawBorders();
void renderBitmapString(float x, float y, void *font, char *string);
bool win = false;
bool gameOver = false; int timer = 1000;
void renderBitmapString(float x, float y, void *font, char *string) ///to write the time 
{
	char *c;
	glRasterPos2f(x, y);
	for (c = string; *c != '\0'; c++)
	{
		glutBitmapCharacter(font, *c);
	}
}

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
double drunk_var1 = 0.0; int drunk_check1 = 0;
double drunk_var2 = 0.0; int drunk_check2 = 0;
double speed_multiplier = 10.5;
void Display() {
	if (!win&&!gameOver){
		if (GLUT_ELAPSED_TIME % 100000 == 0){
			timer--;
			if (timer == 0){
				gameOver = true;
			}

		}
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(90.0f, 1000 / 1000, 0.01f, 300.0f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, drunk_var1, 1.0, drunk_var2);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		drawMaze();
		drawHome(-3.52, 3.5, 11);
		drawSphere();
	}
	else if (win) {
		//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45.0f, 1000 / 1000, 0.1f, 300.0f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(0.0f, 30.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
		glDisable(GL_DEPTH_TEST);
		glDepthMask(0);
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
		glClearColor(0.0f, 0.0f, 102.5 / 255.0f, 0.0f);

		glColor3f(0, 1, 0);
		glDepthMask(0);
		char buffer[255];
		sprintf_s(buffer, "%s", "Congratulations You Win"); //%d is for integers 
		renderBitmapString(5.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, buffer);
		//glEnable(GL_DEPTH_TEST);
		//glDepthMask(1);
		//glFlush();
	}
	else if (gameOver){
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45.0f, 1000 / 1000, 0.1f, 300.0f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(0.0f, 30.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
		glDisable(GL_DEPTH_TEST);
		glDepthMask(0);
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
		glClearColor(0.0f, 0.0f, 102.5 / 255.0f, 0.0f);

		glColor3f(1, 0, 0);
		glDepthMask(0);
		char buffer[255];
		sprintf_s(buffer, "%s", "Game Over :Bara YA Kalb"); //%d is for integers 
		renderBitmapString(5.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, buffer);

	}
	glFlush();

}
void drawSphere(){

	switch (color_effect){
	case 0: glColor3f(1, 1, 1); break;
	case 1: glColor3f(0, 1, 0); break;
	case 2: glColor3f(0, 0, 1); break;
	case 3: glColor3f(1, 0, 0); break;
	}

	glPushMatrix();
	glTranslatef(eyeX + ((centerX - eyeX) / 30.0), -1.0, eyeZ + ((centerZ - eyeZ) / 30.0));
	glutSolidSphere(0.01, 8, 10);
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
	if (!gameOver&&!win){
		if (drunk_var1 >= 0.3 || drunk_check1 == 1){
			drunk_check1 = 1;
			drunk_var1 -= 0.00002*speed_multiplier;
			if (drunk_var1 <= -0.3){
				drunk_check1 = 0;
			}
		}
		else{
			drunk_var1 += 0.00002*speed_multiplier;
		}
		if (drunk_var2 >= 0.3 || drunk_check2 == 1){
			drunk_check2 = 1;
			drunk_var2 -= 0.00002*speed_multiplier;
			if (drunk_var2 <= -0.3){
				drunk_check2 = 0;
			}
		}
		else{
			drunk_var2 += 0.00002*speed_multiplier;
		}
		color_effect_counter += 0.001*speed_multiplier;
		if (color_effect_counter >= 30){
			if (color_effect == 0)
				color_effect = (int)(rand() % 3) + 1;
			else
				color_effect = 0;
			color_effect_counter = 0.0;
		}
		switch (color_effect){
		case 0: speed = 0.0003; break;
		case 1: speed = 0.0003; break;
		case 2: speed = 0.0001; break;
		case 3: speed = 0.0006; break;
		}
		// MOVEMENT CODE START
		if (stop_walking == 0){
			switch (direction){
			case 0:centerX -= speed*speed_multiplier; eyeX -= speed*speed_multiplier; break;
			case 1:centerZ -= speed*speed_multiplier; eyeZ -= speed*speed_multiplier; break;
			case 2:centerX += speed*speed_multiplier; eyeX += speed*speed_multiplier; break;
			case 3:centerZ += speed*speed_multiplier; eyeZ += speed*speed_multiplier; break;
			}
		}
		else{
			if (sign == 1 && dir1 == 'x'){
				centerX += 0.01*speed_multiplier;
				if (dir2 == 1){
					centerZ -= 0.01*speed_multiplier;
				}
				else{
					centerZ += 0.01*speed_multiplier;
				}
				if (centerX >= eyeX + 10){
					stop_walking = 0;
					centerX = eyeX + 10;
					centerZ = eyeZ;
				}
			}
			else{
				if (sign == -1 && dir1 == 'x'){
					centerX -= 0.01*speed_multiplier;
					if (dir2 == 1){
						centerZ += 0.01*speed_multiplier;
					}
					else{
						centerZ -= 0.01*speed_multiplier;
					}
					if (centerX <= eyeX - 10){
						stop_walking = 0;
						centerX = eyeX - 10;
						centerZ = eyeZ;
					}
				}
				else{
					if (sign == 1 && dir1 == 'z'){
						centerZ += 0.01*speed_multiplier;
						if (dir2 == 1){
							centerX += 0.01*speed_multiplier;
						}
						else{
							centerX -= 0.01*speed_multiplier;
						}
						if (centerZ >= eyeZ + 10){
							stop_walking = 0;
							centerZ = eyeZ + 10;
							centerX = eyeX;
						}
					}
					else{
						if (sign == -1 && dir1 == 'z'){
							centerZ -= 0.01*speed_multiplier;
							if (dir2 == 1){
								centerX -= 0.01*speed_multiplier;
							}
							else{
								centerX += 0.01*speed_multiplier;
							}
							if (centerZ <= eyeZ - 10){
								stop_walking = 0;
								centerZ = eyeZ - 10;
								centerX = eyeX;
							}
						}
					}
				}
			}
		}
		// MOVEMENT CODE END

		//collision detection start 
		//glTranslatef(eyeX + ((centerX - eyeX) / 30.0), -1.0, eyeZ + ((centerZ - eyeZ) / 30.0));
		if (eyeX < 3.5 && eyeX > -3 && eyeZ <= 3 && eyeZ >= -2.5){//asgher cube
			if (eyeX < -2.2 && eyeZ<1.7&&eyeZ>0.7){// el fahaa
				printf_s("%s", "   now i am here  ");
				glutPostRedisplay();
				return;
			}
			if (eyeX > 2.2){//right wall
				eyeX -= 1;
			}
			else if (eyeX < -2.2){ // left wall 
				eyeX += 1;
			}
			if (eyeZ < -1.5){//fo2
				eyeZ += 1;
			}
			if (eyeZ > 1.7){//tht
				eyeZ -= 1;
			}
		}
		///////////////////////////////////////////////////////////////////////////////////end  of asgher cube (done)
		else if (eyeX > -5 && eyeX < 5 && eyeZ<3.9&&eyeZ>-3.9){//first cube ba3d el soghnn
			if (eyeZ < -3.1){//up //hina feh fathaa //it was 3.8 then 3.3 
				if (eyeX >= -1.6&&eyeX <= 2.2){
					//hasibo y3ady el fatha
					printf_s("%s", "   ana fel fathaa  ");   ///--->de
				}
				else {
					eyeZ += 1.2;
				}


			}
			else if (eyeZ>3){ //tht  //was 3.8 -->d
				eyeZ -= 1.1;

			}

			if (eyeX<-4.3){//left wall it was 4.7  -->d
				eyeX += 1;
			}
			else if (eyeX>4.2){//right wall/it was  4.98  -->d
				eyeX -= 0.7;
			}
			else if (eyeX <3.8 && eyeX > -3.3 && eyeZ<3.9&&eyeZ>2.6){//kan tht wi hab ytl3 --->d
				printf_s("%s", "   hhh  ");
				if (eyeZ <= 3){ //it was 3 

					eyeZ += 0.5;
				}
			}
			else if (eyeX <3.9 && eyeX > -3.3 && eyeZ<-2 && eyeZ>-3.9){//kan fo2 wi hynzl ykhbt fel soghnn //was eyeZ<-2.6 -->d

				if (eyeZ >= -3.4){ //-->d

					eyeZ -= 1;
				}

			}
			else if (eyeX > 3.2&&eyeZ > -2.5&&eyeZ < 3){//mashy shmal wi hykhbt fel soghnn eyex>3.2 -->d
				printf_s("%s", " yes yes ");
				if (eyeX<3.8){//it was 3.4
					printf_s("%s", "ana hinaa");
					eyeX += 1.2;
				}

			}
			else if (eyeX>-3.9 && ((eyeZ > -2.3&&eyeZ<0.7) || (eyeZ>1.7&&eyeZ < 2.98))){//mashy ymeen wi hakhbt fel sogher //eyex>3.2 -->d

				//left up 
				eyeX -= 0.7;
			}




		}///////end2  done
		////////////////////////////////////////////////////////////////////Borders
		else if (eyeX > -7 && eyeX < 7.3 && eyeZ <= 6.45&&eyeZ >= -6.40)
		{
			if (eyeZ<-5.5){//up //was 6.3   -->d
				eyeZ += 1;
			}
			else if (eyeZ>5.8){//tht khali balk mn el fatha //it was 6.3   --->d
				if (eyeX >= -1.8&&eyeX <= 2.5){

				}
				else {
					eyeZ -= 1;
				}

				//eyeX = eyeX;

			}

			if (eyeX<-6.3){//left wall  --->d
				eyeX += 1;
			}
			else if (eyeX>6.2){//right wall //was 7.1 -->d
				eyeX -= 1;
			}
			else if (eyeX <5.6 && eyeX > -5.3 && eyeZ<7 && eyeZ>3.9){//kan tht wi hab ytl3s fmmkn ykhbt fel soghnn  -->d
				printf_s("%s", "   cocococo  ");
				if (eyeZ < 5){ //it was 4.59

					eyeZ += 1;
				}
			}


			else if ((eyeZ<-3.9&&eyeZ>-6.4) && ((eyeX>-5.5&&eyeX < 0) || (eyeX<6 && eyeX>2.3))){//kan fo2 wi hynzl ykhbt fel soghnn -->d
				//printf_s("%s", "   kikikik  ");
				if (eyeZ > -4.8){ //it was4.5

					eyeZ -= 1;
				}

			}
			else if (eyeX > -7 && eyeX < -5 && eyeZ <= 4.6&&eyeZ >= -3.9){///mash ymeen ----->d
				//printf_s("%s", "ana hinaa");
				if (eyeX > -6)eyeX -= 0.65; //it was -5.5

			}
			else if (eyeX > 5 && eyeX < 7 && eyeZ <= 4.6&&eyeZ >= -3.9){//masha shmal w hakhbt fel soghnn  --->d
				if (eyeX <6)eyeX += 0.7; //it was 6.2

			}
		}
		//////////////////////////////////////////////////////////////////////////////////////////end 3 (done)
		///////////////////////////////////////////////////////////////////start of level 1
		else if (eyeX > -9 && eyeX < 9.3 && eyeZ <= 8.5&&eyeZ >= -8.5)
		{
			if (eyeZ<-7.8){//up  tht khali balk mn el fatha --khleet baly  //was 8.3 -->d
				//eyeX = eyeX;
				if (eyeX >= 1.2&&eyeX <= 6.2){

				}
				else {
					eyeZ += 1.2;
				}
			}
			else if (eyeZ>7.7){// tht was 8.3 tht ---->d
				eyeZ -= 1;

			}

			if (eyeX<-8.3){//left wall //eyex<-8.6  --->d
				eyeX += 0.7;
			}
			else if (eyeX>8.2){//right wall ///was 9.1   --->d
				eyeX -= 0.09;
			}
			else if (eyeX <8.3 && eyeX > -7.5 && eyeZ<8.5 && eyeZ>6.5){//kan tht wi hab ytl3s fmmkn ykhbt fel soghnn
				printf_s("%s", "   cocococo  ");//still lazm akhod baly mn el fatha

				if (eyeZ < 7.55){ //it was 7.59   ---->d
					//eyeX = eyeX;
					if (eyeX <= 2.4&&eyeX >= -1.8){}
					else {
						eyeZ += 0.8;
					}
				}
			}

			else if ((eyeZ<-6.5&&eyeZ>-8.5) && ((eyeX>-7.5&&eyeX < 0) || (eyeX<7.8 && eyeX>5.3))){//kan fo2 wi hynzl ykhbt fel soghnn  ---->d //was eyeX<8
				//printf_s("%s", "   kikikik  ");
				if (eyeZ > -7.5){

					eyeZ -= 1;
				}

			}
			else if (eyeX > -9 && eyeX < -7 && eyeZ <= 7.3&&eyeZ >= -7.4){///mash ymeen  --->d
				//printf_s("%s", "ana hinaa");
				if (eyeX > -8)eyeX -= 0.5; //was7.7

			}
			else if (eyeX > 7 && eyeX < 9 && eyeZ <= 7.3&&eyeZ >= -7.4){//masha shmal w hakhbt fel soghnn --->d  
				if (eyeX <8.3)eyeX += 0.09;  //it was 8.3  //////////////////////////////////////////////////////////moshkla hina ma3 el shmal

			}
		}
		/////////////////////////////////////////////////////////////////////////////////////end of level1 (done)
		/////////////////////////////////////////////////start of level 2 akher leve

		else if (eyeX > -11 && eyeX < 11.3 && eyeZ <= 10.45&&eyeZ >= -10.45)
		{
			if (eyeZ<-9.6){//up  tht khali balk mn el fatha //was 10.2 -->d
				eyeZ += 1;
			}
			else if (eyeZ>9.4){// down  //was -10.2  --->d
				if (eyeZ<10.5 && eyeZ>8.5&&eyeX>-6 && eyeX < 1){   //-3.52, 3.5
					//gluLookAt(0.0f, 30.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
					win = true;

				}
				eyeZ -= 0.7;

			}

			if (eyeX<-10.2){//left wall //was eyex<-10.6    --->d
				eyeX += 0.7;
			}
			else if (eyeX>10.6){//right wall  //was eyex>11.1 10.4
				eyeX -= 0.2;
			}
			else if (eyeX <10.4 && eyeX > -9.5 && eyeZ<10.5 && eyeZ>8.5){//kan tht wi hab ytl3s fmmkn ykhbt fel soghnneyex>-10 /eyex<10.5/
				printf_s("%s", "   cocococo  ");//still lazm akhod baly mn el fatha ---->d
				if (eyeZ < 9.7){

					eyeZ += 0.7;
				}
			}

			else if ((eyeZ<-8.3&&eyeZ>-10.5) && eyeX >= -9.8&& eyeX <= 10){//kan fo2 wi hynzl ykhbt fel soghnn
				if (eyeX >= 1.4&&eyeX <= 7){//was 7.8   ------------>d

				}
				else if (eyeZ>-9) { //it was -9.6
					eyeZ -= 1;
				}

			}
			else if (eyeX > -11 && eyeX < -9 && eyeZ <= 9.6&&eyeZ >= -9.6){///mash ymeen ---->d

				//printf_s("%s", "ana hinaa");
				if (eyeX > -9.6)eyeX -= 0.7;  //was -10  
			}
			else if (eyeX > 9 && eyeX < 11 && eyeZ <= 9.6&&eyeZ >= -9.6){//masha shmal w hakhbt fel soghnn 
				if (eyeX < 9.7)eyeX += 0.1; //was 10.5

			}
		}




		//collision detection end 
		glutPostRedisplay();
	}
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
	/* glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, 1000/1000, 0.1f, 300.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0f, 30.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f);
	*/

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

	if (key == 'd' || key == 'D'){
		if (color_effect == 1)
			handleLeft();
		else
			handleRight();
	}
	if (key == 'a' || key == 'A'){
		if (color_effect == 1)
			handleRight();
		else
			handleLeft();
	}
	glutPostRedisplay();
}
void handleRight(){
	switch (direction){
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
	switch (direction){
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