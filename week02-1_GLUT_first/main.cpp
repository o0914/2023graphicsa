#include <GL/glut.h>
void display()
{
    ///glColor3f(0,1,0);///綠色
    ///glutSolidTeapot(0.5);///畫出一個實心茶壺,它的大小0.5

    glBegin(GL_POLYGON);///開始畫多邊形
        glColor3f(1,0,0);  glVertex2f(0,1);///紅色頂點
        glColor3f(0,1,0);  glVertex2f(-1,-1);///綠色頂點
        glColor3f(0,0,1);  glVertex2f(+1,-1);///藍色頂點
    glEnd();///結束畫


    glColor3f(1,1,0);///黃色
    glutSolidTeapot(0.3);///畫出一個實心茶壺,它的大小0.3
    glutSwapBuffers();///請GLUT把畫面swap送到顯示的地方
}

int main(int argc, char *argv[])
{///上面是特別的main()函式 有很多參數
	glutInit(&argc, argv);///把GLUT開起來
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///顯示設定
    glutCreateWindow("GLUT Shapes");///要開視窗
	glutDisplayFunc(display);///要顯示對應的函式
	glutMainLoop();///最後用main迴圈,壓在最後面
}
