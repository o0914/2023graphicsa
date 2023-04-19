#include <GL/glut.h>
#include "glm.h"
GLMmodel * pmodel = NULL;///有一個模型的指標，先是空的
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    if(pmodel==NULL)
    {
        pmodel = glmReadOBJ("Al.obj");
        glmUnitize(pmodel);
        glmFacetNormals(pmodel);
        glmVertexNormals(pmodel,90);
    }
	glmDraw(pmodel,GLM_MATERIAL);
	glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

	glutCreateWindow("GLUT Shapes");
	glutDisplayFunc(display);
	glutMainLoop();
}
