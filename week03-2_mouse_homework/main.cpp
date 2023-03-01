#include <GL/glut.h>
#include <stdio.h>
float X=0,Y=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///備份矩陣
        glTranslatef(X,Y,0);///移動
        glutSolidTeapot(0.3);
    glPopMatrix();///還原矩陣
    glutSwapBuffers();
}
void mouse(int button,int state,int x,int y)
{
    float X=(x-250)/250.0;
    float Y=-(y-250)/250.0;///減一半,除一半
    if(state==GLUT_DOWN)
    {
        printf("    glVertex2f(%.3f,%.3f);\n", X, Y);
    }
}

int main(int argc,char* argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutCreateWindow("week03");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);

    glutMainLoop();
}
