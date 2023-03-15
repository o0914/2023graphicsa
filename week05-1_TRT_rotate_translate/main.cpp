#include <GL/glut.h>
float angle=0;///宣告global全域變數angle
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glColor3f(0,1,0);///綠色
    glPushMatrix();
        glTranslatef(0.8,0,0);///最後是綠色的移動
        glRotatef(angle,0,0,1);///改對z軸轉
        glutSolidTeapot(0.3);
    glPopMatrix();

    glColor3f(1,0,0);///紅色
    glPushMatrix();
        glRotatef(angle,0,0,1);///改對z軸轉///最後是紅色的轉動
        glTranslatef(0.8,0,0);
        glutSolidTeapot(0.3);
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
