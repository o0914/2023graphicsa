///week12-4_keyboard_mouse �n�� keyboard mouse �Ӿޱ�����, �ӥB�i�s�ɡB�|�ۤv��
///�b��mosue��,���F�� teapotX, teapotY �y��, �í��e, �٭n�A�s�y��
///�s�ɮ�,�|�b�u�@����ؿ� working_dir
///�bCodeBlocks Project-Properties �̭����ĤG��Build targets �U���i�H�]�w
///�⥦�q C:\Users\Administrator\Desktop\freeglut\bin �令 . (�p���I,�{�b�ؿ����N��)
/// �O�o, Debug �M Release ��ӳ��n��
/// �ӥB�n File-Save Everything (Ctrl-Shift-S�����s��)�~�|�N .cbp �M���ɦs��
#include <stdio.h>
#include <GL/glut.h>
FILE * fout = NULL; ///step02-2 �@�}�l,�ɮרS���}, NULL
FILE * fin = NULL; ///step02-2 �nŪ�ɥΪ�����, �@�}�l�]�O NULL
float teapotX=0, teapotY=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef(teapotX, teapotY, 0);
        glutSolidTeapot( 0.3 );
    glPopMatrix();
    glutSwapBuffers();
}
void mouse(int button, int state, int x, int y)
{
    if(state==GLUT_DOWN){
        teapotX = (x-150)/150.0;
        teapotY = (150-y)/150.0;
        if(fout==NULL) fout = fopen("file4.txt", "w"); ///step02-2 �S�}��,�N�}
        fprintf(fout, "%f %f\n", teapotX, teapotY); ///step02-2 �n�A�s�y��
    }
    display();
}
void keyboard(unsigned char key, int x, int y) ///step02-2 keyboard�禡
{
    if(fin==NULL){ ///step02-2 �p�G�ɮ��٨S fopen(), �N�}��
        fclose(fout); ///�e��mouse�|�}fout����, �ҥH�n����
        fin = fopen("file4.txt", "r"); ///step02-2 �S�}��,�N�}
    }
    fscanf(fin, "%f %f", &teapotX, &teapotY); ///step02-2 �u��Ū��
    display(); ///step02-2 ���e�e��
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard); ///step02-2 keyboard�n�����o(�}�ɡBŪ��)

    glutMainLoop();
}
