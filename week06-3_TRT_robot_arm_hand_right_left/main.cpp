#include <GL/glut.h>
float angle=0;///�ŧiglobal�����ܼ�angle
void drawHand()
{
    glPushMatrix();
        glScalef(1,0.3,0.3);
        glutSolidCube(0.5);
    glPopMatrix();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glPushMatrix();///�k�W���u
        glTranslatef(0.25,0,0);///�n���W�h
        glRotatef(angle,0,0,1);///���
        glTranslatef(0.25,0,0);///�⤤�� ��b������
        drawHand();///�k�W���u

        glPushMatrix();///�k�U��y
            glTranslatef(0.25,0,0);
            glRotatef(angle,0,0,1);
            glTranslatef(0.25,0,0);
            drawHand();///�k�U��y
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();///���W���u
        glTranslatef(-0.25,0,0);///�n���W�h
        glRotatef(angle,0,0,1);///���
        glTranslatef(-0.25,0,0);///�⤤�� ��b������
        drawHand();///���W���u

        glPushMatrix();///���U��y
            glTranslatef(-0.25,0,0);
            glRotatef(angle,0,0,1);
            glTranslatef(-0.25,0,0);
            drawHand();///���U��y
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
    angle++;///����++
}


int main(int argc,char* argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week04");

    glutDisplayFunc(display);
    glutIdleFunc(display);///����idle��,�N���e�e��
    glutMainLoop();
}
