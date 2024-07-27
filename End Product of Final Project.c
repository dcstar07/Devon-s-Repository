//Final Project for c snake game I was able to create this project with the help form lectures and geeks for geeks has a code that I was able to base mine off of 

#include <conio.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <stdbool.h>
int a,b, height =30, width =30, YouLose, score, i, j, flya, flyb, flag; // creating variables for later height and width will be determining the size

//creating a function that will generate the fly and setting the bounds for the game

void setup()
{
	YouLose = 0; 
	
	// This will store the height and width for the game
	
	i = height / 3;
	j = width / 3; 
	
	label1: 
	flya = rand() % height;// Using rand so that it generates random numbers 
	if (flya == 0)
		goto label1;
	label2:
	flyb = rand() % width;// 
	if	(flyb == 0)
		goto label2;
	score = 0; 
}



// Function to take the input

void input() // using a case system for when each flag is hit it will determine what do next 
{
	if (kbhit()) { // kbhit standing for when the keyboard is hit it will do something 
	switch(getch()) {
		case 'i': // the case standing for what letter is hit  later I will probide a function for what it does 
			flag =1;
			break;
		case 'l':
			flag = 2;
			break;
		case 'k':
			flag = 3;
			break;
		case 'j' :
			flag = 4;
			break;
		case 'z':
			YouLose =1;
			break; 
			
	               }	           	
	            }
}

// Function for the movement of i,j,k,l,z

void movement()
{
	usleep(1000); // delay for control of snake 
	switch(flag){ // here it looks at whats above for the flag to see if there is an option
		case 1:
			i--; // move up
			break;
		case 2:
			j++; // move right 
			break;
		case 3:
			i++; // move down 
			break;
		case 4:
			j--; // move left 
			break;
		default: 
		break;			
	}
	// heres what happens if you lose
	if (i < 0 || i > height || j < 0 || j > width)
	YouLose =1; 
//if the snake eats a fly 
if (i == flya && j == flyb){
	label3:
		flya = rand() %20; 
		if (flya == 0)
		goto label3; 

	// generating a new fly
	label4: 
	flyb = rand() %30;
	if (flyb == 0)
	goto label4;
	score += 10; 
}
}
// Now this will be a function for creating the boundaries that way it's not a infinite void

void bounds()
{
	system("cls"); // clears the console screen before drawing the updated game board 
	for ( a =0; a < height; a ++){ // using an outer loop for a and inner loop for b 
		for (b = 0; b< width; b++){
			if ( a == 0 || a == width -1	|| b == 0	|| b == height -1){
				printf("#"); // checks if a or b is at the edge it will print yippee for the edges
			}
			else {
				if (a == i && b == j)
				printf("0"); // checks wether or not if the head of the snake hits the wall 
				else if ( a == flya && b == flyb)
				printf("*");
				else
				printf(" ");
				
			}
		}
		printf("\n");
	}
// score of game
printf("Here's your score =%d", score);
printf("\n");
printf("Press Z if you would like to quit the game ");

}
// menu for the code that gives you the instructions and option to start
void menu()
{
char choice; // creating a character for when they type an answer later
system("cls");// clears the console screen
printf("Welcome to the Snake Game Friend!\n");
printf("Here are the rules they may be simple but the game is harder than it appears\n");
printf("Catch the fly as many times as you can \n");
printf("The following instructions are for buttons on your keyboard\n");
printf("(i) is to go up\n");
printf("(j) is to go left\n");
printf("(k) is to go down\n");
printf("(l) is to go right\n"); 
printf("If you wanna be cool and have a good time say yes to the following choice\n");
printf("Shall you play the game? (y/n):");
choice = getch();
if (choice == 'y' || choice == 'Y'){
	setup(); //will display the bounds 
} else{
	printf("Fine I guess you don't want to have fun\n");
	printf("If youre not playing me you better be productive\n");
	printf("Or not I don't really care\n");
	printf("adios");
	exit(0);
}
}
// finally the code for the main fn

int main()
{
	
	menu();
	
	while (!YouLose) {
		bounds();
		input();
		movement();
		
	}
	printf("Game Over Friend Your Final Score: %d\n", score);
	return 0;
}
