//#include<windows.h>
#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
void man ();
void bus();
void road();
void signal();
void car();
void mydisplay();
void display();
void frontsreen();
void drawstring();
void setFont();
void myMouse();
void update();
void moveMan();
void helpscreen();
void reshape(int,int);
bool front = true;
GLfloat gx = -100, gy =0;
GLint a=300,b=-300,flag=0,traffic_regulator=1;
int x1=300,x2=-300;
GLfloat red=0,blue=1,green=.3;
GLfloat p=0,q=0,r=0;

void *currentfont;
void setFont(void *font)
{
    currentfont=font;
}
void init()
{
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
}
void printtext(char s[], int x, int y, int l, int state = 1)
{
    glRasterPos2i(x,y);
    for(int i = 0;i<l;i++)
    {
        if(state == 1)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s[i]);
        else if(state == 2)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, s[i]);
        else if(state == 3)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[i]);
    }
}
void frontpage()
{
    init();
    //GLuint mmm = LoadTexture("cse.bmp");
    //glBindTexture (GL_TEXTURE_2D, mmm);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-90, 90);
    glVertex2f(-90, -90);
    glVertex2f(90, -90);
    glVertex2f(90, 90);
    glEnd();
    glColor3f(1,1,1);
    glColor3f(0,1,1);
    printtext("VISVESVARAYA TECHNOLOGICAL UNIVERSITY",-60,80,37);
    printtext("BELGAVI, KARNATAKA - 590018",-40,70,27);
    glColor3f(1,1,1);
    printtext("A Minor Project on",-22,60,18);
    glColor3f(1,0,0);
    printtext("SIMULATION OF STACK",-40,48,19,3);
    glColor3f(0.76470588235,0.06274509803,0.93725490196);
    printtext("Submitted in partial fulfullment for the Computer Graphics and Visualization",-58,33,76,2);
    printtext(" Laboratory course of Sixth Semester of Bachelor of Engineering in Computer",-60,29,75,2);
    printtext("Science & Engineering during the academic year 2018-19",-47,25,54,2);
    glColor3f(1,1,1);
    printtext("By",-1,12,2);
    glColor3f(1,0,0);
    printtext("Sudharshan V     4MN16CS040",-35,0,27);
    printtext("Punith Nayaka K  4MN16CS040",-35,-8,27);
    glColor3f(0.929411764,0.56862745,0.027450980);
    printtext("||Under the Guidance of||",-27,-20,25);
    printtext("Prof. Bharath Bharadwaj B S",-31,-30,27);
    printtext("Assistant Professor",-12,-34,19,2);
    printtext(" Dept. of CS&E",-9,-38,14,2);
    printtext("MIT Thandavpura",-11,-42,15,2);
    printtext("2018-19",-7,-50,7);
    glColor3f(0,1,1);
    printtext("DEPARTMENT OF COMPUTER SCIENCE & ENGINEERING",-70,-60,44);
    printtext("MAHARAJA INSTITUTE OF TECHNOLOGY THANDAVAPURA",-73,-70,45);
    printtext("NH 766, Nanjangud Taluk, Mysuru - 571302",-50,-80,40);
    glColor3f(1,1,1);
    glBegin(GL_LINES);
    glVertex2f(-40,46);
    glVertex2f(39,46);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2f(-40,7);
    glVertex2f(-40,-12);
    glVertex2f(43,-12);
    glVertex2f(43,7);
    glVertex2f(-40,7);
    glEnd();
    glutSwapBuffers();
}

void drawstring(float x,float y,float z,char *string)
{
    char *c;
    glRasterPos3f(x,y,z);
    for(c=string; *c!='\0'; c++)
    {
        glColor3f(0.0,0.0,0.0);
        glutBitmapCharacter(currentfont,*c);
    }
}
void frontscreen(void)
{
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glClearColor(0.15,0.1,0.01,0);/*background for cover page*/
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);

    drawstring(543,100,0.0,"PRESS ENTER TO START");
    glFlush();
}
void helpscreen()
{
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glClearColor(0,0,0,0);/*background for cover page*/
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,1,0);
    drawstring(550.0,700.0,0.0,"TIPS");
    glColor3f(1,0,0);
    drawstring(650.0,700.0,0.0,"AND");
    glColor3f(0,0,1);
    drawstring(750.0,700.0,0.0,"TRICKS");
    glColor3f(0.5,0.1,0.2);
    drawstring(350.0,640.0,0.0,"Stop the traffic (Red Light) MOUSE LEFT CLICK");
    glColor3f(0.5,0.1,0.3);
    drawstring(350.0,540.0,0.0,"Yellow Signal MOUSE RIGHT BUTTON (HOLD ON)");
    glColor3f(0.5,0.1,0.4);
    drawstring(350.0,440.0,0.0,"Green Signal MOUSE RIGHT BUTTON (RELEASE)");
    glColor3f(0.4,0.1,0.5);
    drawstring(350.0,140.0,0.0,"Speed up the vehicles PRESS 'S'");
    glColor3f(0.5,0.1,0.8);
    drawstring(350.0,90.0,0.0,"Help PRESS 'H'");
    glColor3f(0.5,0.1,0.9);
    drawstring(350.0,40.0,0.0,"Escape PRESS 'ENTER'");
    glFlush();
}
void myKeyboard( unsigned char key, int x, int y )
{
    if(front)
    {
        if(int(key) == 13)
        {
            front = false;
            glutReshapeWindow(1346,728);
        glutDisplayFunc(mydisplay);
        glutReshapeFunc(reshape);
        glutPostRedisplay();
        //glutInitWindowSize(1346,728);
        }
    }
    switch(key)
    {
    case 13:
        if(flag==1)
        {
            flag=2;
            mydisplay();
        }
        if(flag==0) //Ascii of 'enter' key is 13
        {
            flag=1;
            mydisplay();
        }
        break;
    case 's':
        mydisplay();
        break;
    case 'h':
        flag=1;
        mydisplay();
        break;
    default:
        break;
    }
}
void myMouse(int button,int state,int x,int y)
{
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        traffic_regulator=0;
        p=1;
        q=0;
        r=0;
    }
    if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
    {
        traffic_regulator=0;
        p=0;
        q=1;
        r=0;
    }
    if(button==GLUT_RIGHT_BUTTON && state==GLUT_UP)
    {
        traffic_regulator=1;
        p=0;
        q=0;
        r=1;
    }
    glutPostRedisplay();
}
void mydisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    if(flag==0)
        frontscreen ();
    if(flag==1)
        helpscreen();
    if(flag==2)
        display();
    glutSwapBuffers();
}
void update(int value)
{
    a=a-6;
    b=b+6;
    glutPostRedisplay();
}
void moveMan(int value)
{
    x1=x1-6;
    x2=x2+6;
    glutPostRedisplay();
}

void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(red,green,blue,0);
    road();
    signal();
    man();
    if(traffic_regulator)
        glutTimerFunc(50,update,0);
    bus();
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(red,green,blue,0);
    road();
    bus();

    man();
    car();
    signal();
    if(p)
        glutTimerFunc(50,moveMan,0);
    man();
    glFlush();

}
void man()
{
    glPushMatrix();
    glTranslated(50.0,-x1,0.0);
    glScaled(40.0,40.0,0.0);
    glColor3f(1,0.7,0.6);
//body
    glBegin(GL_POLYGON);
    glVertex2f(26.0,2);
    glVertex2f(26.3,2);
    glVertex2f(26.3,5);
    glVertex2f(26,5);
    glEnd();
//lleg
    glBegin(GL_POLYGON);
    glVertex2f(25,1);
    glVertex2f(25.2,1);
    glVertex2f(26.2,2);
    glVertex2f(26,2);
    glEnd();
//rleg
    glBegin(GL_POLYGON);
    glVertex2f(27.1,1);
    glVertex2f(27.3,1);
    glVertex2f(26.3,2);
    glVertex2f(26.1,2);
    glEnd();
//lhand
    glBegin(GL_POLYGON);
    glVertex2f(25,2.9);
    glVertex2f(25.2,2.9);
    glVertex2f(26.2,3.9);
    glVertex2f(26,3.9);
    glEnd();
//rhand
    glBegin(GL_POLYGON);
    glVertex2f(27,3);
    glVertex2f(27.2,3);
    glVertex2f(26.2,4);
    glVertex2f(26,4);
    glEnd();
    glPopMatrix();
    glPushMatrix();//face
    glTranslated(50.0,-x1,0.0);
    glScaled(20.0,20.0,0.0);
    glBegin(GL_POLYGON);
    float thb;
    int ib;
    for ( ib = 0; ib < 360; ib ++)
    {
        thb=ib*3.142/180;
        glVertex2f(52.3+1.4*cos(thb),10+1.4*sin(thb));
    }
    glEnd();
    glPopMatrix();
    glFlush();
    glPopMatrix();
}

void road()
{
    glPushMatrix();
    glScaled(40.0,40.0,0.0);
    glColor3f(0.1,0.1,0.1);
    glBegin(GL_POLYGON);
//straight road
    glVertex2f(0,5);
    glVertex2f(40,5);
    glVertex2f(40,10);
    glVertex2f(0,10);
    glEnd();
//cross road
    glBegin(GL_POLYGON);
    glColor3f(0.1,0.1,0.1);
    glVertex2f(10,0);
    glVertex2f(20,0);
    glVertex2f(25,10);
    glVertex2f(15,10);
    glEnd();
//front road
    glBegin(GL_POLYGON);
    glColor3f(0.1,0.1,0.1);
    glVertex2f(26,10);
    glVertex2f(29,10);
    glVertex2f(29,30);
    glVertex2f(26,30);
    glEnd();
//green edge
    glBegin(GL_POLYGON);
    glColor3f(0.1,0.2,0.1);
    glVertex2f(0,5);
    glVertex2f(40,5);
    glVertex2f(40,4);
    glVertex2f(0,4);
    glEnd();
//building 1
    glBegin(GL_POLYGON);
    glColor3f(0.7,0,0);
    glVertex2f(0,10);
    glVertex2f(5,10);
    glVertex2f(5,20);
    glVertex2f(0,20);
    glEnd();
//door 1
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(1,10);
    glVertex2f(3,10);
    glVertex2f(3,12);
    glVertex2f(1,12);
    glEnd();
//building 2
    glBegin(GL_POLYGON);
    glColor3f(0.7,1,0.7);
    glVertex2f(5.5,10);
    glVertex2f(10.5,10);
    glVertex2f(10.5,15);
    glVertex2f(5.5,15);
    glEnd();
//door 2
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(6.5,10);
    glVertex2f(8.5,10);
    glVertex2f(8.5,12);
    glVertex2f(6.5,12);
    glEnd();
//building 3
    glBegin(GL_POLYGON);
    glColor3f(0.9,0,0.3);
    glVertex2f(11,10);
    glVertex2f(14,10);
    glVertex2f(14,18);
    glVertex2f(11,18);
    glEnd();
//door 3
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(12,10);
    glVertex2f(13,10);
    glVertex2f(13,12);
    glVertex2f(12,12);
    glEnd();
//building 4
    glBegin(GL_POLYGON);
    glColor3f(0.1,6,0.9);
    glVertex2f(15,10);
    glVertex2f(20,10);
    glVertex2f(20,25);
    glVertex2f(15,25);
    glEnd();
//door 4
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(16,10);
    glVertex2f(17,10);
    glVertex2f(17,12);
    glVertex2f(16,12);
    glEnd();
//building 5
    glBegin(GL_POLYGON);
    glColor3f(0.9,0.5,0);
    glVertex2f(21,10);
    glVertex2f(25,10);
    glVertex2f(25,15);
    glVertex2f(21,15);
    glEnd();
//door 5
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(22,10);
    glVertex2f(24,10);
    glVertex2f(24,12);
    glVertex2f(22,12);
    glEnd();
//strip 1
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2f(0,7.5);
    glVertex2f(5,7.5);
    glVertex2f(5,8);
    glVertex2f(0,8);
    glEnd();
//strip 2
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2f(10,7.5);
    glVertex2f(15,7.5);
    glVertex2f(15,8);
    glVertex2f(10,8);
    glEnd();
//strip 3
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2f(20,7.5);
    glVertex2f(25,7.5);
    glVertex2f(25,8);
    glVertex2f(20,8);
    glEnd();
//strip 4
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2f(30,7.5);
    glVertex2f(35,7.5);
    glVertex2f(35,8);
    glVertex2f(30,8);
    glEnd();
//zstrip
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2f(26,7);
    glVertex2f(29,7);
    glVertex2f(29,7.5);
    glVertex2f(26,7.5);
    glEnd();
//zstrip
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2f(26,6);
    glVertex2f(29,6);
    glVertex2f(29,6.5);
    glVertex2f(26,6.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2f(26,5);
    glVertex2f(29,5);
    glVertex2f(29,5.5);
    glVertex2f(26,5.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2f(26,8);
    glVertex2f(29,8);
    glVertex2f(29,8.5);
    glVertex2f(26,8.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2f(26,9);
    glVertex2f(29,9);
    glVertex2f(29,9.5);
    glVertex2f(26,9.5);
    glEnd();
    glPopMatrix();
}
void signal()
{
    glPushMatrix();
    glScaled(40.0,40.0,0.0);
//stand
    glColor3f(0.4,0.5,0.5);
    glBegin(GL_POLYGON);
    glVertex2f(30,3);
    glVertex2f(30,4);
    glVertex2f(33,4);
    glVertex2f(33,3);
    glEnd();
//pole
    glBegin(GL_POLYGON);
    glVertex2f(31,3);
    glVertex2f(32,4);
    glVertex2f(32,11);
    glVertex2f(31,11);
    glEnd();
//board
    glBegin(GL_POLYGON);
    glVertex2f(30.5,11);
    glVertex2f(32.5,11);
    glVertex2f(32.5,6);
    glVertex2f(30.5,6);
    glEnd();
//red
    glColor3f(p,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(31,10.5);
    glVertex2f(32,10.5);
    glVertex2f(32,10);
    glVertex2f(31,10);
    glEnd();
//yellow
    glColor3f(q,q,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(31,9.5);
    glVertex2f(32,9.5);
    glVertex2f(32,9);
    glVertex2f(31,9);
    glEnd();
//green
    glColor3f(0.0,r,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(31,8.5);
    glVertex2f(32,8.5);
    glVertex2f(32,8);
    glVertex2f(31,8);
    glEnd();
    glPopMatrix();
}
void bus()
{
    glPushMatrix();
    glTranslated(b,60.0,0.0);
    glScaled(40.0,40.0,0.0);
    glColor3f(0.5,0.0,0.0);
//bus out line
    glBegin(GL_POLYGON);
    glVertex2f(5,8);
    glVertex2f(5,11);
    glVertex2f(13,11);
    glVertex2f(14,9.5);
    glVertex2f(14,8);
    glEnd();
//window frame
    glColor3f(0,0.1,1);
    glBegin(GL_POLYGON);
    glVertex2f(6.1,9.5);
    glVertex2f(6.1,10.5);
    glVertex2f(11.8,10.5);
    glVertex2f(11.8,9.5);
    glEnd();

//Doors
    glColor3f(0,0.8,1);
    glBegin(GL_POLYGON);
    glVertex2f(6.2,9);
    glVertex2f(6.2,10.4);
    glVertex2f(7.7,10.4);
    glVertex2f(7.7,9);
    glEnd();
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(7,8.4);
    glVertex2f(7,10.4);
    glVertex2f(7.7,10.4);
    glVertex2f(7.7,8.4);
    glEnd();
//small windows
    glColor3f(0,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(7.8,9.6);
    glVertex2f(7.8,10.4);
    glVertex2f(9,10.4);
    glVertex2f(9,9.6);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(9.1,9.6);
    glVertex2f(9.1,10.4);
    glVertex2f(10.2,10.4);
    glVertex2f(10.2,9.6);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(10.3,9.6);
    glVertex2f(10.3,10.4);
    glVertex2f(11.7,10.4);
    glVertex2f(11.7,9.6);
    glEnd();
//driver window
    glColor3f(0,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(13,9.5);
    glVertex2f(13,10.5);
    glVertex2f(13.3,10.5);
    glVertex2f(14,9.5);
    glEnd();
    glPopMatrix();
//tyre
    glPushMatrix();//front tyre
    glTranslated(b+970,320,0.0);
    glScaled(20.0,20.0,0.0);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-35,2.5);
    glVertex2f(-35.0,2.6);
    glVertex2f(-35.15,3.1);
    glVertex2f(-35.2,3.2);
    glVertex2f(-35.3,3.35);
    glVertex2f(-35.4,3.4);
    glVertex2f(-35.5,3.45);
    glVertex2f(-35.6,3.55);
    glVertex2f(-35.7,3.6);
    glVertex2f(-35.8,3.63);
    glVertex2f(-36.0,3.65);
    glVertex2f(-36.2,3.7);
    glVertex2f(-36.4,3.7);
    glVertex2f(-36.6,3.65);
    glVertex2f(-36.8,3.55);
    glVertex2f(-37.0,3.45);
    glVertex2f(-37.1,3.4);
    glVertex2f(-37.2,3.25);
    glVertex2f(-37.3,3.2);
    glVertex2f(-37.4,3.0);
    glVertex2f(-37.5,2.5);
    glVertex2f(-37.45,2.15);
    glVertex2f(-37.4,1.9);
    glVertex2f(-37.35,1.8);
    glVertex2f(-37.2,1.6);
    glVertex2f(-37.0,1.5);
    glVertex2f(-36.9,1.4);
    glVertex2f(-36.7,1.3);
    glVertex2f(-36.6,1.27);
    glVertex2f(-36.4,1.25);
    glVertex2f(-36.0,1.25);
    glVertex2f(-35.9,1.3);
    glVertex2f(-35.75,1.35);
    glVertex2f(-35.6,1.4);
    glVertex2f(-35.45,1.55);
    glVertex2f(-35.3,1.7);
    glVertex2f(-35.2,1.8);
    glVertex2f(-35.1,2.2);
    glEnd();
    glPopMatrix();
    glPushMatrix();//back tyre
    glTranslated(b+1140,320,0.0);
    glScaled(20.0,20.0,0.0);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-30.0,2.5);
    glVertex2f(-30.0,2.6);
    glVertex2f(-30.15,3.1);
    glVertex2f(-30.2,3.2);
    glVertex2f(-30.3,3.35);
    glVertex2f(-30.4,3.4);
    glVertex2f(-30.5,3.45);
    glVertex2f(-30.6,3.55);
    glVertex2f(-30.7,3.6);
    glVertex2f(-30.8,3.63);
    glVertex2f(-31.0,3.65);
    glVertex2f(-31.2,3.7);
    glVertex2f(-31.4,3.7);
    glVertex2f(-31.6,3.65);
    glVertex2f(-31.8,3.55);
    glVertex2f(-32.0,3.45);
    glVertex2f(-32.1,3.4);
    glVertex2f(-32.2,3.25);
    glVertex2f(-32.3,3.2);
    glVertex2f(-32.4,3.0);
    glVertex2f(-32.5,2.5);
    glVertex2f(-32.45,2.15);
    glVertex2f(-32.4,1.9);
    glVertex2f(-32.35,1.8);
    glVertex2f(-32.2,1.6);
    glVertex2f(-32.0,1.5);
    glVertex2f(-31.9,1.4);
    glVertex2f(-31.7,1.3);
    glVertex2f(-31.6,1.27);
    glVertex2f(-31.4,1.25);
    glVertex2f(-31.0,1.25);
    glVertex2f(-30.9,1.3);
    glVertex2f(-30.75,1.35);
    glVertex2f(-30.6,1.4);
    glVertex2f(-30.45,1.55);
    glVertex2f(-30.3,1.7);
    glVertex2f(-30.2,1.8);
    glVertex2f(-30.1,2.2);
    glEnd();
    glPopMatrix();
}
void car()
{
    glPushMatrix(); //making color for outer line
    glTranslated(b,190.0,0.0);
    glScaled(20.0,20.0,0.0);
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(2.5,2.5);
    glVertex2f(3.0,3.5);
    glVertex2f(3.5,3.75);
    glVertex2f(4.0,4.0);
    glVertex2f(4.5,4.0);
    glVertex2f(5.0,3.75);
    glVertex2f(5.5,3.5);
    glVertex2f(5.75,3.0);
    glVertex2f(6.0,2.5);
    glVertex2f(16.5,2.5);
    glVertex2f(16.75,3.0);
    glVertex2f(17.0,3.5);
    glVertex2f(17.5,3.75);
    glVertex2f(18.0,4.0);
    glVertex2f(18.5,4.0);
    glVertex2f(19.0,3.75);
    glVertex2f(19.5,3.5);
    glVertex2f(19.75,3.0);
    glVertex2f(20.0,2.5);
    glVertex2f(21.0,2.5);
    glVertex2f(21.0,4.0);
    glVertex2f(21.5,4.0);
    glVertex2f(21.0,4.5);
    glVertex2f(20.0,5.0);
    glVertex2f(15.0,5.0);
    glVertex2f(14.0,5.5);
    glVertex2f(13.0,6.0);
    glVertex2f(12.0,6.5);
    glVertex2f(11.0,7.0);
    glVertex2f(6.0,7.0);
    glVertex2f(5.0,6.5);
    glVertex2f(4.5,6.25);
    glVertex2f(4.25,6.0);
    glVertex2f(4.0,5.75);
    glVertex2f(3.5,5.5);
    glVertex2f(3.0,5.5);
    glVertex2f(1.9,5.45);
    glVertex2f(1.8,5.4);
    glVertex2f(1.7,5.35);
    glVertex2f(1.6,5.3);
    glVertex2f(1.5,5.25);
    glVertex2f(1.4,5.15);
    glVertex2f(1.3,5.0);
    glVertex2f(1.2,4.85);
    glVertex2f(1.1,4.7);
    glVertex2f(1.0,4.3);
    glVertex2f(1.0,3.2);
    glVertex2f(1.1,3.05);
    glVertex2f(1.2,2.9);
    glVertex2f(1.3,2.9);
    glVertex2f(1.4,2.75);
    glVertex2f(1.5,2.65);
    glVertex2f(1.6,2.6);
    glVertex2f(1.7,2.55);
    glVertex2f(1.8,2.5);
    glVertex2f(1.9,2.45);
    glVertex2f(2.0,2.5);
    glEnd();
    glColor3f(1.0,1.0,1.0); //color for outer window
    glBegin(GL_POLYGON);
    glVertex2f(5.0,5.0);
    glVertex2f(14.0,5.0);
    glVertex2f(11.5,6.5);
    glVertex2f(10.5,6.75);
    glVertex2f(7.0,6.75);
    glEnd();
    glColor3f(0.0,0.0,0.0); //making outer line for car
    glBegin(GL_LINE_LOOP);
    glVertex2f(2.5,2.5);
    glVertex2f(3.0,3.5);
    glVertex2f(3.5,3.75);
    glVertex2f(4.0,4.0);
    glVertex2f(4.5,4.0);
    glVertex2f(5.0,3.75);
    glVertex2f(5.5,3.5);
    glVertex2f(5.75,3.0);
    glVertex2f(6.0,2.5);
    glVertex2f(16.5,2.5);
    glVertex2f(16.75,3.0);
    glVertex2f(17.0,3.5);
    glVertex2f(17.5,3.75);
    glVertex2f(18.0,4.0);
    glVertex2f(18.5,4.0);
    glVertex2f(19.0,3.75);
    glVertex2f(19.5,3.5);
    glVertex2f(19.75,3.0);
    glVertex2f(20.0,2.5);
    glVertex2f(21.0,2.5);
    glVertex2f(21.0,4.0);
    glVertex2f(21.5,4.0);
    glVertex2f(21.0,4.5);
    glVertex2f(20.0,5.0);
    glVertex2f(15.0,5.0);
    glVertex2f(14.0,5.5);
    glVertex2f(13.0,6.0);
    glVertex2f(12.0,6.5);
    glVertex2f(11.0,7.0);
    glVertex2f(6.0,7.0);
    glVertex2f(5.0,6.5);
    glVertex2f(4.5,6.25);
    glVertex2f(4.25,6.0);
    glVertex2f(4.0,5.75);
    glVertex2f(3.5,5.5);
    glVertex2f(3.0,5.5);
    glVertex2f(1.9,5.45);
    glVertex2f(1.8,5.4);
    glVertex2f(1.7,5.35);
    glVertex2f(1.6,5.3);
    glVertex2f(1.5,5.25);
    glVertex2f(1.4,5.15);
    glVertex2f(1.3,5.0);
    glVertex2f(1.2,4.85);
    glVertex2f(1.1,4.7);
    glVertex2f(1.0,4.3);
    glVertex2f(1.0,3.2);
    glVertex2f(1.1,3.05);
    glVertex2f(1.2,2.9);
    glVertex2f(1.3,2.9);
    glVertex2f(1.4,2.75);
    glVertex2f(1.5,2.65);
    glVertex2f(1.6,2.6);
    glVertex2f(1.7,2.55);
    glVertex2f(1.8,2.5);
    glVertex2f(1.9,2.45);
    glVertex2f(2.0,2.5);
    glEnd();
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP); //outer line for design a car
    glVertex2f(8.0,3.0);
    glVertex2f(16.0,3.0);
    glVertex2f(16.5,3.5);
    glVertex2f(17.0,4.0);
    glVertex2f(16.5,4.25);
    glVertex2f(16.0,4.5);
    glVertex2f(15.0,4.5);
    glVertex2f(15.0,5.0);
    glVertex2f(14.0,5.0);
    glVertex2f(11.5,6.5);
    glVertex2f(10.5,6.75);
    glVertex2f(7.0,6.75);
    glVertex2f(5.0,5.0);
    glVertex2f(7.0,5.0);
    glVertex2f(6.5,4.5);
    glEnd();
    glBegin(GL_LINES); //connecting outer line
    glVertex2d(7.0,5.0);
    glVertex2d(15.0,5.0);
    glEnd();
    glColor3f(0.0,0.0,0.0); //connecting outer line
    glBegin(GL_LINES);
    glVertex2d(15.0,4.0);
    glVertex2d(17.0,4.0);
    glEnd();
    glColor3f(0.0,0.0,0.0); //connecting outer line
    glBegin(GL_LINES);
    glVertex2d(15.0,3.5);
    glVertex2d(16.5,3.5);
    glEnd();
    glColor3f(0.0,0.0,0.0); //connecting outer line
    glBegin(GL_LINES);
    glVertex2d(15.0,5.0);
    glVertex2d(14.0,3.0);
    glEnd();
    glColor3f(0.0,0.0,0.0); //connecting outer line
    glBegin(GL_LINES);
    glVertex2d(12.0,5.0);
    glVertex2d(12.0,6.2);
    glEnd();
    glColor3f(0.0,0.0,0.0); //connecting outer line
    glBegin(GL_LINES);
    glVertex2d(7.0,5.0);
    glVertex2d(7.0,6.7);
    glEnd();
    glBegin(GL_POLYGON); //drawing a back tyre
    glVertex2f(3.0,2.5);
    glVertex2f(3.0,2.6);
    glVertex2f(3.15,3.1);
    glVertex2f(3.2,3.2);
    glVertex2f(3.3,3.35);
    glVertex2f(3.4,3.4);
    glVertex2f(3.5,3.45);
    glVertex2f(3.6,3.55);
    glVertex2f(3.7,3.6);
    glVertex2f(3.8,3.63);
    glVertex2f(4.0,3.65);
    glVertex2f(4.2,3.7);
    glVertex2f(4.4,3.7);
    glVertex2f(4.6,3.65);
    glVertex2f(4.8,3.55);
    glVertex2f(5.0,3.45);
    glVertex2f(5.1,3.4);
    glVertex2f(5.2,3.25);
    glVertex2f(5.3,3.2);
    glVertex2f(5.4,3.0);
    glVertex2f(5.5,2.5);
    glVertex2f(5.45,2.15);
    glVertex2f(5.4,1.9);
    glVertex2f(5.35,1.8);
    glVertex2f(5.2,1.6);
    glVertex2f(5.0,1.5);
    glVertex2f(4.9,1.4);
    glVertex2f(4.7,1.3);
    glVertex2f(4.6,1.27);
    glVertex2f(4.4,1.25);
    glVertex2f(4.0,1.25);
    glVertex2f(3.9,1.3);
    glVertex2f(3.75,1.35);
    glVertex2f(3.6,1.4);
    glVertex2f(3.45,1.55);
    glVertex2f(3.3,1.7);
    glVertex2f(3.2,1.8);
    glVertex2f(3.1,2.2);
    glEnd();
    glBegin(GL_POLYGON); //drawing front tyre
    glVertex2f(17.0,2.5);
    glVertex2f(17.0,2.6);
    glVertex2f(17.15,3.1);
    glVertex2f(17.2,3.2);
    glVertex2f(17.3,3.35);
    glVertex2f(17.4,3.4);
    glVertex2f(17.5,3.45);
    glVertex2f(17.6,3.55);
    glVertex2f(17.7,3.6);
    glVertex2f(17.8,3.63);
    glVertex2f(18.0,3.65);
    glVertex2f(18.2,3.7);
    glVertex2f(18.4,3.7);
    glVertex2f(18.6,3.65);
    glVertex2f(18.8,3.55);
    glVertex2f(19.0,3.45);
    glVertex2f(19.1,3.4);
    glVertex2f(19.2,3.25);
    glVertex2f(19.3,3.2);
    glVertex2f(19.4,3.0);
    glVertex2f(19.5,2.5);
    glVertex2f(19.45,2.15);
    glVertex2f(19.4,1.9);
    glVertex2f(19.35,1.8);
    glVertex2f(19.2,1.6);
    glVertex2f(19.0,1.5);
    glVertex2f(18.9,1.4);
    glVertex2f(18.7,1.3);
    glVertex2f(18.6,1.27);
    glVertex2f(18.4,1.25);
    glVertex2f(18.0,1.25);
    glVertex2f(17.9,1.3);
    glVertex2f(17.75,1.35);
    glVertex2f(17.6,1.4);
    glVertex2f(17.45,1.55);
    glVertex2f(17.3,1.7);
    glVertex2f(17.2,1.8);
    glVertex2f(17.1,2.2);
    glEnd();
    glPopMatrix();
}
void reshapefront(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,100,-100,100);
    glMatrixMode(GL_MODELVIEW);
}


void myinit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,1346.0,0.0,728.0);
}
void reshape(int w, int h)
{
    myinit();
}
int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700,700);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Traffic signal");
    glutDisplayFunc(frontpage);
    glutReshapeFunc(reshapefront);
    glutKeyboardFunc(myKeyboard);
    glutMouseFunc(myMouse);
    myinit();
    glutMainLoop();
}
