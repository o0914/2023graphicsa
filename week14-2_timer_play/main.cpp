#include <GL/glut.h>
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotated(angle,0,0,1);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
void timer(int t)
{
    glutTimerFunc(500,timer,t+1);///�]�w�U�@�Ӿx��
    angle+=90;///�W�[90��
    glutPostRedisplay();///���e�e��
}
void keyboard(unsigned char key,int x,int y)
{
    glutTimerFunc(0,timer,0);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week14");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    ///glutTimerFunc(2000,timer,0);

    glutMainLoop();
}
