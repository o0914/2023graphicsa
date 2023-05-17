#include <stdio.h>
#include <GL/glut.h>
#include "glm.h"
GLMmodel * head = NULL;
GLMmodel * body = NULL;
GLMmodel * uparmR = NULL;
GLMmodel * lowarmR = NULL;
int show[4]={1,1,1,1};///用show[i]來決定要不要顯示
int ID=0;///0:頭 1:身體 2:上手臂 3:下手臂
void keyboard(unsigned char key,int x,int y)
{
    if(key=='0') ID=0;
    if(key=='1') ID=1;
    if(key=='2') ID=2;
    if(key=='3') ID=3;
    ///if(key=='0')show[0]=!show[0];
    ///if(key=='1')show[1]=!show[1];
    ///if(key=='2')show[2]=!show[2];
    ///if(key=='3')show[3]=!show[3];
    glutPostRedisplay();
}///原來的keyboard先註解、不要用
FILE * fout = NULL;
FILE * fin = NULL;
float teapotX=0, teapotY=0;
float angle=0, angle2=0,angle3=0;
void display()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glScalef(0.2,0.2,0.2);
        if(body==NULL)
        {
            head=glmReadOBJ("model/head.obj");
            body=glmReadOBJ("model/body.obj");
            uparmR=glmReadOBJ("model/uparmR.obj");
            lowarmR=glmReadOBJ("model/lowarmR.obj");
            ///glmUnitize(body);
        }
        if(ID==0)glColor3f(1,0,0);///選定的,設紅色
        else glColor3f(1,1,1);///沒選定,設白色
        if(show[0]) glmDraw(head,GLM_MATERIAL);

        if(ID==1)glColor3f(1,0,0);///選定的,設紅色
        else glColor3f(1,1,1);///沒選定,設白色
        if(show[1]) glmDraw(body,GLM_MATERIAL);

        glPushMatrix();
            glTranslatef(teapotX,teapotY,0);

            if(ID==2)glColor3f(1,0,0);///選定的,設紅色
            else glColor3f(1,1,1);///沒選定,設白色
            if(show[2]) glmDraw(uparmR,GLM_MATERIAL);
        glPopMatrix();

        if(ID==3)glColor3f(1,0,0);///選定的,設紅色
        else glColor3f(1,1,1);///沒選定,設白色
        if(show[3]) glmDraw(lowarmR,GLM_MATERIAL);
    glPopMatrix();
    glutSwapBuffers();

}
int oldX=0,oldY=0;
void motion(int x,int y)
{
    teapotX += (x - oldX)/150.0;
    teapotY -= (y - oldY)/150.0;
    oldX = x;
    oldY = y;
    printf("glTranslatef(%f,%f,0)\n",teapotX,teapotY);
    glutPostRedisplay();
}
void mouse(int button, int state, int x, int y)
{
    if(state==GLUT_DOWN){
        oldX = x;///teapotX = (x-150)/150.0;
        oldY = y;///teapotY = (150-y)/150.0;
        angle = x;
        ///if(fout==NULL) fout = fopen("file4.txt","w");
        ///fprintf(fout, "%f %f\n", teapotX, teapotY);
    }
    display();
}
/*void keyboard(unsigned char key,int x, int y)
{
    if(fin==NULL){
        fclose(fout);
        fin = fopen("file4.txt","r");
    }
    fscanf(fin, "%f %f", &teapotX, &teapotY);
    display();
}*/
int main(int argc, char *argv[])
{

    glutInit(&argc,argv);///把參數送給glutInit初始化

    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///雙緩衝區+3D深度功能

    glutCreateWindow("week12");///開GLUT視窗



    glutDisplayFunc(display);///顯示用的函式
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);



    glutMainLoop();

}
