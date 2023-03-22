#include <GL/glut.h>
float angle=0;///宣告global全域變數angle
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    ///glutSolidSphere(0.02,30,30); 正中心的圓球

    glutSolidTeapot(0.3);///身體

    glPushMatrix();///右手臂
        ///先註解 glTranslatef(-0.5,0.5,0);
        glTranslatef(0.49,0.13,0);
        glRotatef(angle,0,0,1);///就可以轉動
        glTranslatef(0.46,-0.05,0);///把轉動的中心 放在中心
        glutSolidTeapot(0.3);

        glPushMatrix();///右手肘
        ///先註解 glTranslatef(-0.5,0.5,0);
            glTranslatef(0.49,0.13,0);
            glRotatef(angle,0,0,1);///就可以轉動
            glTranslatef(0.46,-0.05,0);///把轉動的中心 放在中心
            glutSolidTeapot(0.3);
        glPopMatrix();

    glPopMatrix();


    glutSwapBuffers();
    angle++;///角度++
}


int main(int argc,char* argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week04");

    glutDisplayFunc(display);
    glutIdleFunc(display);///有空idle時,就重畫畫面
    glutMainLoop();
}

