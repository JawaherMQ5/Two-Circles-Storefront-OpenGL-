#include <iostream>
#include <windows.h>
#include <GL/glut.h>
#include <cmath>


const int width = 800;
const int height = 600;

// Shop sign settings
const float signWidth = 687.0 - 117.0;
const float signCenterX = 117.0 + (signWidth / 2.0);
const float signCenterY = 469.0 + (578.0 - 469.0) / 2.0;
//Taif
void drawFilledCircle(int xc, int yc, int r, float red, float green, float blue) {
    glColor3f(red, green, blue);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xc, yc);

    for (int i = 0; i <= 360; i += 10) {
        float theta = i * 3.14159f / 180.0f;
        float x = xc + cosf(theta) * r;
        float y = yc + sinf(theta) * r;
        glVertex2f(x, y);
    }
    glEnd();
    glFlush();
}

void drawCircles() {
    drawFilledCircle(225, 328, 50, 1.0f, 0.0f, 0.0f);
    drawFilledCircle(585, 328, 50, 1.0f, 0.8f, 0.0f);
}

//jawaher
bool isTextVisible = true;
float Timer = 0.0;
const float BlinkTimer = 1.0;
void DrawingText(const char* text, float x, float y, float scale) {
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(scale, scale, 1.0);
    glLineWidth(6.0);

    if (isTextVisible) {
        glColor3f(1.0f, 1.0f, 1.0f);
    }
    else {
        glColor3f(0.5f, 0.5f, 0.5f);
    }

    const char* p = text;
    while (*p) {
        glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, *p);
        ++p;
    }
    glLineWidth(1.0);

    glPopMatrix();
}
void drawSignText() {
    const char* text = "Two Circles";
    float textWidth = glutStrokeLength(GLUT_STROKE_MONO_ROMAN, (unsigned char*)text);
    float desiredTextWidth = signWidth * 0.9;
    float scale = desiredTextWidth / textWidth;
    float textHeight = 100.0 * scale;
    float x = signCenterX - (textWidth * scale / 2.0);
    float y = signCenterY - (textHeight / 2.0);

    Timer += 0.016;
    if (Timer >= BlinkTimer) {
        isTextVisible = !isTextVisible;
        Timer = 0.0;
    }
    DrawingText(text, x, y, scale);
}

//rahaf
void drawStorefront() {
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_QUADS);
    glVertex2f(120, 130); glVertex2f(680, 130);glVertex2f(680, 500); glVertex2f(120, 500);
    glEnd();

    glColor3f(1.0, 1.0, 0.9);
    glBegin(GL_QUADS);
    glVertex2f(140, 150); glVertex2f(660, 150); glVertex2f(660, 480); glVertex2f(140, 480);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(117, 469); glVertex2f(687, 469); glVertex2f(687, 578);    glVertex2f(117, 578);
    glEnd();

    glColor3f(1.0, 1.0, 0.9);
    glBegin(GL_QUADS);
    glVertex2f(160, 200); glVertex2f(280, 200);glVertex2f(280, 380); glVertex2f(160, 380);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(520, 200); glVertex2f(640, 200); glVertex2f(640, 380); glVertex2f(520, 380);
    glEnd();

    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_QUADS);
    glVertex2f(140, 130); glVertex2f(660, 130); glVertex2f(660, 150); glVertex2f(140, 150);
    glEnd();
}

void drawSideRectangles() {

    glColor3f(0.6, 0.6, 0.6);


    glBegin(GL_QUADS);
    glVertex2f(142, 150);
    glVertex2f(302, 150);
    glVertex2f(302, 470);
    glVertex2f(142, 470);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2f(500, 150);
    glVertex2f(660, 150);
    glVertex2f(660, 470);
    glVertex2f(500, 470);
    glEnd();

    glFlush();
}

//The door
//Tahani
void drawDoor() {
    glColor3f(0.2f, 0.2f, 0.2f);
    glRectf(310, 150, 490, 440);


    glColor3f(0.1f, 0.1f, 0.1f);
    glRectf(320, 160, 480, 430);


    glColor3f(1.0f, 1.0f, 1.0f);
    glRectf(395, 160, 405, 430);


    glColor3f(1.0f, 1.0f, 0.9f);
    glRectf(337, 190, 375, 405);

    glRectf(425, 190, 463, 405);


    glColor3f(0.4f, 0.4f, 0.4f);
    glRectf(375, 250, 384, 310);

    glRectf(415, 250, 425, 310);
}
// reham
void drawFloor() {
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_LINES);

    for (int i = 0; i < 7; i++) {
        float y = 50.0 + 30.0 * i;
        float x1 = 50.0 + 20.0 * i;
        float x2 = 750.0 - 20.0 * i;
        glVertex2f(x1, y);
        glVertex2f(x2, y);
    }

    for (int i = 0; i < 8; i++) {
        float x = 50.0 + 100.0 * i;
        glVertex2f(x, 50.0);
        glVertex2f(400.0, 230.0);
    }
    glEnd();
}
//Rana
//  Signboard
void drawSignBoard() {

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glColor3f(0.7, 0.5, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(550, 220); glVertex2f(545, 100);glVertex2f(695, 100); glVertex2f(700, 220);
    glEnd();


    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glColor3f(0.9, 0.7, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(560, 210); glVertex2f(555, 110);glVertex2f(685, 110); glVertex2f(690, 210);
    glEnd();


    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glColor3f(0.5, 0.4, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(700, 220); glVertex2f(695, 100); glVertex2f(730, 100);
    glEnd();

    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_QUADS);
    glVertex2i(555, 70); glVertex2i(565, 70); glVertex2i(565, 100); glVertex2i(555, 100);
    glVertex2i(680, 70); glVertex2i(690, 70); glVertex2i(690, 100); glVertex2i(680, 100);

    glVertex2i(570, 85); glVertex2i(580, 85); glVertex2i(580, 100); glVertex2i(570, 100);
    glVertex2i(700, 85); glVertex2i(710, 85); glVertex2i(710, 100); glVertex2i(700, 100);
    glEnd();


    //Text
      //https://youtu.be/5DAGJtW-PsU?si=k4zSuMqgj1dYJaJ5 
    glColor3f(0.1, 0.1, 0.1);

    glRasterPos2f(595, 180);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'T');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'W');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'O');


    glRasterPos2f(580, 150);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'C');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'I');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'R');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'C');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'L');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'S');
}
// Chair
void drawRectangle()
{
    glColor3f(0.6, 0.4, 0.2);
    glBegin(GL_QUADS);
    glVertex2i(80, 155); glVertex2i(340, 155); glVertex2i(340, 180);glVertex2i(80, 180);
    glEnd();
}
void drawScaledRectangle()
{
    glPushMatrix();
    glScalef(0.8, 0.8, 1);
    glTranslatef(50, 100, 0.0);
    drawRectangle();
    glPushMatrix();
}
void drawSca() {
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_QUADS);
    glVertex2i(245, 125); glVertex2i(260, 125); glVertex2i(260, 155); glVertex2i(245, 155);
    glVertex2i(155, 125); glVertex2i(170, 125); glVertex2i(170, 155); glVertex2i(155, 155);

    glVertex2i(135, 30); glVertex2i(150, 30); glVertex2i(150, 95); glVertex2i(135, 95);
    glVertex2i(265, 30); glVertex2i(280, 30); glVertex2i(280, 95); glVertex2i(265, 95);
    glVertex2i(155, 50); glVertex2i(170, 50); glVertex2i(170, 95); glVertex2i(155, 95);
    glVertex2i(245, 50); glVertex2i(260, 50); glVertex2i(260, 95); glVertex2i(245, 95);
    glEnd();
}

///wejdan
float antX = 50;
bool movingRight = true;
void drawAnt() {
    //Call of drawFilledCircle
    drawFilledCircle((int)antX, 50, 6, 0.0f, 0.0f, 0.0f);         // Back part
    drawFilledCircle((int)(antX + 10), 50, 5, 0.0f, 0.0f, 0.0f);  // Middle part
    drawFilledCircle((int)(antX + 18), 50, 4, 0.0f, 0.0f, 0.0f);  // Head
    // Legs
    glBegin(GL_LINES);
    glVertex2f(antX - 3, 48); glVertex2f(antX - 7, 42);
    glVertex2f(antX + 3, 48); glVertex2f(antX + 7, 42);
    glVertex2f(antX + 10, 48); glVertex2f(antX + 7, 42);
    glVertex2f(antX + 14, 48); glVertex2f(antX + 17, 42);
    glVertex2f(antX + 20, 48); glVertex2f(antX + 23, 42);
    glVertex2f(antX + 24, 48); glVertex2f(antX + 27, 42);
    glEnd();
}
void update(int value) {
    antX += 2.0f;
    if (antX > 800)
        antX = -50;
    glutPostRedisplay();
    glutTimerFunc(30, update, 0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    drawFloor();
    drawStorefront();
    drawSideRectangles();
    drawDoor();
    drawSignBoard();                // Draw the store signboard 
    drawCircles();
    drawAnt();                      // Draw the moving ant
    drawSignText();                 // Draw the text on the signboard
    drawRectangle();
    drawScaledRectangle();          // Draw a scaled (shrunk or enlarged) rectangle
    drawSca();                      // Draw an additional effect or element
    glutSwapBuffers();              // Swap the buffers to display the updated image
}

void initOpenGL() {
    glClearColor(1.0f, 1.0f, 0.9f, 1.0f);
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 800, 0, 600);
    glMatrixMode(GL_MODELVIEW);
}

// main
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutCreateWindow("GROUPS 9");
    glutTimerFunc(30, update, 0); // Start periodic updates every 30 milliseconds

    initOpenGL();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}