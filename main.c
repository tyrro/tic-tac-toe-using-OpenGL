#include <math.h>
#include <string.h>
#include <GL/glut.h>
/* if we use GLUT to handle the window-managing operations,
we do not need to include gl.h and glu.h */


#define PI 3.1415926535897932384626433832795

char matrix[3][3];
char done =' ';
int first_move = 0, gameover = 0, computer_move = -1;
																		
void init_matrix();																//initializing the matrix
void player_move();																	//player's move
void computer_move_3X3();							


//initializing the matrix

void init_matrix()																	
{
	int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			matrix[i][j]=' ';														//initially all indices are made empty

}

void computer_move_3X3()
{
	int i,j;

    //row checking for computer win

	//if 1st & 2nd elements are 'O', we make 3rd 'O'

	for(i=0;i<3;i++){

		if((matrix[i][0]=='O'&& matrix[i][1]=='O')){									
			if(matrix[i][2]==' '){
				matrix[i][2]='O';
				return;
			}
		}
	}

	//if 1st & 3rd elements are 'O', we make 2nd 'O'

	for(i=0;i<3;i++){
		if((matrix[i][0]=='O'&& matrix[i][2]=='O')){									
			if(matrix[i][1]==' '){
				matrix[i][1]='O';
				return;
			}
		}
	}
	//if 2nd & 3rd elements are 'O', we make 1st 'O'

	for(i=0;i<3;i++){
		if((matrix[i][1]=='O'&& matrix[i][2]=='O')){									
			if(matrix[i][0]==' '){
				matrix[i][0]='O';
				return;
			}
		}
	}

	//column checking for computer win

	//if 1st & 2nd elements are 'O', we make 3rd 'O'
	for(i=0;i<3;i++){
		if((matrix[0][i]=='O'&& matrix[1][i]=='O')){									
			if(matrix[2][i]==' '){
				matrix[2][i]='O';
				return;
			}
		}
	}
	//if 1st & 3rd elements are 'O', we make 2nd 'O'

	for(i=0;i<3;i++){
		if((matrix[0][i]=='O'&& matrix[2][i]=='O')){								
			if(matrix[1][i]==' '){
				matrix[1][i]='O';
				return;
			}
		}
	}
	//if 2nd & 3rd elements are 'O', we make 1st 'O'

	for(i=0;i<3;i++){
		if((matrix[2][i]=='O'&& matrix[1][i]=='O')){									
			if(matrix[0][i]==' '){
				matrix[0][i]='O';
				return;
			}
		}
	}

	//row checking for blocking user win

	//if 1st & 2nd elements are 'X', we make 3rd 'O'

	for(i=0;i<3;i++){

		if((matrix[i][0]=='X'&& matrix[i][1]=='X')){									
			if(matrix[i][2]==' '){
				matrix[i][2]='O';
				return;
			}
		}
	}

	//if 1st & 3rd elements are 'X', we make 2nd 'O'

	for(i=0;i<3;i++){
		if((matrix[i][0]=='X'&& matrix[i][2]=='X')){									
			if(matrix[i][1]==' '){
				matrix[i][1]='O';
				return;
			}
		}
	}
	//if 2nd & 3rd elements are 'X', we make 1st 'O'

	for(i=0;i<3;i++){
		if((matrix[i][1]=='X'&& matrix[i][2]=='X')){									
			if(matrix[i][0]==' '){
				matrix[i][0]='O';
				return;
			}
		}
	}

	//column checking for blocking win

	//if 1st & 2nd elements are 'X', we make 3rd 'O'
	for(i=0;i<3;i++){
		if((matrix[0][i]=='X'&& matrix[1][i]=='X')){									
			if(matrix[2][i]==' '){
				matrix[2][i]='O';
				return;
			}
		}
	}
	//if 1st & 3rd elements are 'X', we make 2nd 'O'

	for(i=0;i<3;i++){
		if((matrix[0][i]=='X'&& matrix[2][i]=='X')){								
			if(matrix[1][i]==' '){
				matrix[1][i]='O';
				return;
			}
		}
	}
	//if 2nd & 3rd elements are 'O', we make 1st 'O'

	for(i=0;i<3;i++){
		if((matrix[2][i]=='X'&& matrix[1][i]=='X')){									
			if(matrix[0][i]==' '){
				matrix[0][i]='O';
				return;
			}
		}
	}

	//diagonal checking

	//if (1,1) & (2,2) is 'O'or'X',we make (3,3)th index 'O'

	if((matrix[0][0]=='O'&&matrix[1][1]=='O')||(matrix[0][0]=='X'&&matrix[1][1]=='X')){										
		if(matrix[2][2]==' '){
				matrix[2][2]='O';
				return;
			}
	}
	//if (1,1) & (3,3) is 'O'or'X',we make (2,2)th index 'O'

	if((matrix[0][0]=='O'&&matrix[2][2]=='O')||(matrix[0][0]=='X'&&matrix[2][2]=='X')){
		if(matrix[1][1]==' '){
				matrix[1][1]='O';
				return;
			}
	}
	//if (3,3) & (2,2) is 'O'or 'X',we make (1,1)th index 'O'

	if((matrix[1][1]=='O'&&matrix[2][2]=='O')||(matrix[1][1]=='X'&&matrix[2][2]=='X')){										
		if(matrix[0][0]==' '){
				matrix[0][0]='O';
				return;
			}
	}
	//if (1,3) & (2,2) is 'O'or'X',we make (3,1)th index 'O'

	if((matrix[0][2]=='O'&&matrix[1][1]=='O')||(matrix[0][2]=='X'&&matrix[1][1]=='X')){					
		if(matrix[2][0]==' '){
				matrix[2][0]='O';
				return;
			}
	}
	//if (1,3) & (3,1) is 'O'or'X',we make (2,2)th index 'O'

	if((matrix[0][2]=='O'&&matrix[2][0]=='O')||(matrix[0][2]=='X'&&matrix[2][0]=='X')){										
		if(matrix[1][1]==' '){
				matrix[1][1]='O';
				return;
			}
	}
	//if (3,1) & (2,2) is 'O'or'X',we make (1,3)th index 'O'

	if((matrix[1][1]=='O'&&matrix[2][0]=='O')||(matrix[1][1]=='X'&&matrix[2][0]=='X')){										
		if(matrix[0][2]==' '){
				matrix[0][2]='O';
				return;
			}
	}

	//blocking tactic(1st move)

	if(matrix[1][1]==' '){
		matrix[1][1]='O';															
		return;
	}

	if (matrix [1][1] == 'O') {

		if (matrix [0][0] == 'X') {

			if (matrix [2][2] == ' ') {
				matrix [2][2] = 'O';
				return;
			}
		}

		if (matrix [0][2] == 'X') {

			if (matrix [2][0] == ' ') {
				matrix [2][0] = 'O';
				return;
			}
		}

		if (matrix [2][0] == 'X') {

			if (matrix [0][2] == ' ') {
				matrix [0][2] = 'O';
				return;
			}	
		}

		if (matrix [2][2] == 'X') {

			if (matrix [0][0] == ' '){
				matrix [0][0] = 'O';
				return;
			}	
		}
	}

	if(matrix[1][1]=='X'){
		if(matrix[0][0]==' '){
			matrix[0][0]='O';
			return;
		}
	}

	//blocking tactic(2nd move)

	if((matrix[0][0]=='X'&&matrix[2][2]=='X') || (matrix[0][2]=='X'&&matrix[2][0]=='X')){
		if(matrix[0][1]==' '){
			matrix[0][1]='O';
			return;
		}
	}

	if(matrix[1][1]=='X'&&matrix[2][2]=='X'){
		if(matrix[0][2]==' '){
			matrix[0][2]='O';
			return;
		}
	}

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)

			if (matrix [i][j] == ' ') {

				matrix [i][j] = 'O';
				return;
			}
		
}

char check_3X3()
{
	int i,j;

	//row checking

	for(i=0;i<3;i++)
		if(matrix[i][0]==matrix[i][1]&&matrix[i][0]==matrix[i][2])							//checking if the elements of rows are identical
			return matrix[i][0];

	//column checking

	for(i=0;i<3;i++)
		if(matrix[0][i]==matrix[1][i]&&matrix[0][i]==matrix[2][i])							//checking if the elements of columns are identical
			return matrix[0][i];

	//diagonal checking

	if(matrix[0][0]==matrix[1][1]&&matrix[0][0]==matrix[2][2])								//checking if (1,1),(2,2) & (3,3) are identical
		return matrix[0][0];

	if(matrix[0][2]==matrix[1][1]&&matrix[0][2]==matrix[2][0])								//checking if (1,3),(2,2) & (3,1) are identical
			return matrix[0][2];

	//if there is no identical rows,columns or diagonals,we then check if there is any empty index left

	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(matrix[i][j]==' ')
				return ' ';																	//if we find any empty index,we simply return it
		}
	}

	//there is no identical rows,columns or diagonals,there is no empty indices left means the match is drawn and we return 'D'

	return 'D';
}

void init (void)
/* all initialization and related one-time parameter settings */
{
	glClearColor (1.0, 1.0, 1.0, 0.0);
	/* the arguments refer to red, green, blue and alpha value respectively,
	assigns a colour to the display window */

	glMatrixMode (GL_PROJECTION);
	/* how we want to project our picture onto the display window */

	gluOrtho2D (0, 200, 0, 300);
	/* gluOrtho2D(xmin, xmax, ymin, ymax),coordinates reference frame 
	within the display window to be (0, 0) and (200, 150) refers the 
	lower-left and the upper-right window corner respectively */
}

//this function is called when keyboard button is pressed 
void KeyPress(unsigned char key, int x, int y )
{
    switch (key){

    	case 'm':
    		if (gameover == 0) {

    			first_move = 1;
    			computer_move = 0;
    		}

    		break;

    	case 'c':
    		if (gameover == 0) {
    			first_move = 1;
    			computer_move = 1;
    		}

    		break;

    	case ' ':
    		gameover = 0;
			computer_move = -1;
			first_move = 0;
			init_matrix();
			break;

		case 'y':
			if (gameover == 1) {

				gameover = 0;
				computer_move = -1;
				first_move = 0;
				init_matrix();
			}
			break;
			

		case 'n':
			if (gameover == 1)
				exit(0);
			break;

		case 27:
			exit(0);
            
	} 
}

//This function is called when the mouse button is pressed and this function puts the x or o on the blank box 
void click(int button, int state, int x, int y)
{
	if(gameover == 0 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){

		if (computer_move == 0) {

			if (matrix[(y - 50) / 100][x / 100] == ' '){
 
				matrix[(y - 50) / 100][x / 100] = 'X';
				computer_move = 1;
			}
		}
	}
}

//Used to write text in the opengl window
void drawString (void *font, char *s, float x, float y)
{
    unsigned int i;
    glColor3f (0.0, 0.0, 1.0);
    glRasterPos2f(x, y);
   
	/* colour scheme (RGB) for the object we want to display on screen,
	we have set red = 1.0, green = blue = 0.0 */

    for (i = 0; i < strlen(s); i++)
        glutBitmapCharacter (font, s[i]);
}

//This function is used to draw the 4 lines 2 vertical and 2 horizontal
void drawlines()
{
	glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    //2 vertical lines
    glVertex2f(100, 50);
    glVertex2f(100, 340);
    glVertex2f(200, 340);
    glVertex2f(200, 50);
    //2 horizontal lines
    glVertex2f(0, 150);
    glVertex2f(300, 150);
    glVertex2f(0, 250);
    glVertex2f(300, 250);
	glEnd();
}

//This Function Draw the x and o's
void drawxo()
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			glColor3f (0.0, 0.0, 0.0);
			/* colour scheme (RGB) for the object we want to display on screen,
			we have set red = 1.0, green = blue = 0.0 */
			if(matrix[i][j] == 'X') //if it is 1 then draw x 
			{
				glBegin(GL_LINES);
                glVertex2f(50 + j * 100 - 25, 100 + i * 100 - 25);
                glVertex2f(50 + j * 100 + 25, 100 + i * 100 + 25);
                glVertex2f(50 + j * 100 - 25, 100 + i * 100 + 25);
                glVertex2f(50 + j * 100 + 25, 100 + i * 100 - 25);
				glEnd();
			}

			else if(matrix[i][j] == 'O') //if it is 2 then draw o
			{
				glBegin (GL_LINE_LOOP);

				double xc = 50 + j * 100, yc = 100 + i * 100, r = 30;

				for (double i = 0; i <= 2 * PI; i += PI/12)
					glVertex2f (xc + r * cos(i), yc + r * sin(i));


				glEnd ();
			}
		}
	}
}

void display (void)
/* geometric description of the picture we want to display */
{
	glClear (GL_COLOR_BUFFER_BIT);
	/* glClearColor does not put the display window on the screen, this 
	one is to get the assigned window colour displayed */

	glColor3f (1.0, 0.0, 0.0);
	/* colour scheme (RGB) for the object we want to display on screen,
	we have set red = 1.0, green = blue = 0.0 */

	drawlines();

	drawxo();																			//displaying the current matrix
	
	if (first_move == 0)
		drawString(GLUT_BITMAP_HELVETICA_18, "First move!You(m) or Computer(c)?", 5, 30);
		

	done=check_3X3();															//checking the matrix

	if(done != ' ') {

		gameover = 1;

		if(done=='X')																	//if the return is 'X',user won
			drawString(GLUT_BITMAP_HELVETICA_18, "You won!", 50, 30);

		else if(done=='O')																//if the return is 'O',computer won
			drawString(GLUT_BITMAP_HELVETICA_18, "Computer won!", 15, 30);

		else if(done=='D')																//if the return is 'D',match drawn
			drawString(GLUT_BITMAP_HELVETICA_18, "It's a draw!", 50, 30);

		drawString(GLUT_BITMAP_HELVETICA_18, "Rematch? (y/n)", 150, 30);

	}

	if (done != 'O' && done != 'D' && computer_move == 0)
		drawString(GLUT_BITMAP_HELVETICA_18, "Your turn", 100, 30);

	if (done != 'X' && done != 'D' && computer_move == 1) {
		
		computer_move_3X3 ();
		computer_move = 0;
	}

	//glFlush();
	glutSwapBuffers();
}

//This function is called on windows resize
void reshape(int x, int y)
{
	glViewport(0, 0, x, y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, x, y, 0, 0, 1);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char *argv[])
{
	glutInit (&argc, argv);
	/* GLUT initialization */

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	/* buffering and choice of colour modes, single buffering and RGB
	colour modes are the default options actually */

	glutInitWindowPosition (100, 100);
	/* initial location for the top-left corner of the display window */

	glutInitWindowSize (300, 350);
	/* initial pixel width and height of the display window */

	glutCreateWindow ("Tic Tac Toe");
	/* for the display window title */

	init();

	init_matrix();

	glutReshapeFunc(reshape);

	glutDisplayFunc (display);
	/* specifying what the display window will contain */

	glutKeyboardFunc(KeyPress);
	glutMouseFunc(click);
	glutIdleFunc(display);

	glutMainLoop ();
	/* this one must be the last one, display window including their contents
	are now activated and puts the program into an infinite loop*/

	

	return 0;
}
