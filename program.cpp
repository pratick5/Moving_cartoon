# Moving_cartoon
Moving  stickman in GLopen using keyboard event
#include<gl/glut.h>
#include<stdio.h>
#include<windows.h>
#include<math.h>
float tx=0,ty=0,l1=-0.2,l2=0.2;
int move =2,flag1=1,flag2=0;

void move_legs_arms(){
	if(l1<0.2 && flag1==1){
		l1+=0.01;
		if(l1>=0.2){
			flag1=0;
		}
	}
	
	else if(l1>-0.2 && flag1==0){
		l1-=0.01;
		if(l1<=-0.2){
			flag1=1;
		}
	}
		
	if(l2<0.2 && flag2==1){
		l2+=0.01;
		if(l2>=0.2){
			flag2=0;
		}
	}
	else if(l2>-0.2 && flag2==0){
		l2-=0.01;
		if(l2<=-0.2){
			flag2=1;
		}
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,1,0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(tx,ty,0.0);
	
	glutSolidSphere(0.15,50,50);
	
	glBegin(GL_LINES);
	glVertex2f(0.0,0.0);
	glVertex2f(0.0,-0.5);
	
	glVertex2f(0.0,-0.2);
	glVertex2f(l2,-0.4);
	
	glVertex2f(l2,-0.4);
	glVertex2f(-0.1,-0.5);	
	
	
	glVertex2f(0.0,-0.2);
	glVertex2f(l1,-0.4);

  	glVertex2f(l1,-0.4);
  	glVertex2f(-0.2,-0.3);
	
	glVertex2f(0.0,-0.5);
	glVertex2f(l1,-0.8);
	
	glVertex2f(0.0,-0.5);
	glVertex2f(l2,-0.8);
	

	
	glEnd();
	glFlush();
}
void xyz(int v)      
{
	if(move==3){
		tx+=0.01;
		if(tx>=1.0){
			tx=-1.0;
		}
		move_legs_arms();
	}
	
	if(move==1){
		tx-=0.01;
		if(tx<=-1.0){
			tx=1.0;
		}
		move_legs_arms();
	}
	
	glutPostRedisplay();
	glutTimerFunc(10,xyz,0);
}
void key(unsigned char k,int x,int y) // keyboard event
{
	if(k=='W'||k=='w')
		move=0;
	else if(k=='A'||k=='a')
		move=1;
	else if(k=='S'||k=='s')
		move=2;
	else if(k=='D'||k=='d')
		move=3;
}
int main(int argc,char ** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("display");
	glutDisplayFunc(display);
	glutKeyboardFunc(key);
	glutTimerFunc(100,xyz,0);
	glutMainLoop();
	return 0;
}

