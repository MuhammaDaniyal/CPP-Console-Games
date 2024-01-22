#include <iostream>
using namespace std;

void draw( int arr[150][100] ,int n, int m );
void play( int arr[150][100] ,int n, int m );
void output( int score , int jump );

int main()
{

/*
Your friend came to you for spending his/her holidays and has some idea in a mind of game and
he/she knows you are doing CS degree so interested in development of that game. The game
name is "Gain and Win" game. Your task is to create that game for your friend which should
include three functions: draw , play , and showOutput . The objective is to move through a grid and
accumulate points, but if you land on a cell with a value of 0, your score resets to zero and the
game ends when score reaches to 100.
Here are the specific requirements for each function:
1. Function draw
• Arguments: n (number of rows) and m (number of columns) where 1 < n < 100 and 1 <
m < 150.
• Output: Generate n x m game board filled with random values between 0 and m. You
can use standard C++ randomization functions to generate these values. The board
should be displayed on the console.
2. Function play
Argument: s , where s is between 0 and n.
• Execution: Start the game at cell (s, 0). The player picks the value from this cell, denoted
as 'q'.
• Move to cell (k, q), where 'k' starts at 0 and increments with each jump.
• If 'q' reaches n, reset it to 0.
• If the cell value at (k, q) is 0, reset the player's score to zero.
• Otherwise, add the cell value to the player's score.
• Exit Condition: The game ends when the player's score crosses 100.
3. Function showOutput
•
•
Output: At the end of the game display the final score and the number of jumps made
during the game.
Your program should allow the user to input the values for 'n' and 'm' at the start of the
program. It should also prompt the user for the initial value 's'.
Note:
•
You may use standard C++ libraries for generating random numbers.•
The program should handle inputs within the specified ranges gracefully and report any invalid
inputs.
Your task is to write the C++ program that implements these three functions and fulfills the
requirements. Ensure that your code is well-documented and organized.
Important: Remember to follow C++ coding conventions and best practices in your solution.
*/


	int n,m;	
	do{	cout << "Enter number of rows: "  ;	cin >> n;	}while( n<1 );	
	do{	cout << "Enter number of column: ";	cin >> m;	}while( m<1 );	
	
	int arr[150][100];

	for ( int i=0 ; i<n ; ++i )		//if we make box in the function every time we call, we will get diff values bc of rand()
		for ( int j=0 ; j<m ; ++j )
			arr[i][j] = rand()%m ;						//Random values bw 0 & m

//	Function calling	
	draw( arr , n, m );
	play( arr , n, m );
	
	return 0;
}

void draw( int arr[150][100] ,int n, int m )
{
	for ( int i=0 ; i<n ; ++i )		
	{	for ( int j=0 ; j<m ; ++j )
		{	
			if ( arr[i][j] < 10 )		cout << "00" << arr[i][j] << " " ;	
			else if( arr[i][j] <100 )	cout << "0" << arr[i][j] << " ";
		}
		cout << endl;
	}	

}

void play( int arr[150][100] ,int n, int m )
{
	int s , score=0 ;
	cout << "Enter value of s ( 0<s<n ): ";	cin >> s;
	
	int q,k=0,jump=0;
	score += arr[s][0];						//As we want to initialize addition at some point
	q=arr[s][0];							//q is actually [j]
	while ( score<=100 )						//keeps on going till score < 100
	{
		if ( k=n )	k=0;					// if k=n then it resets to 0
		
		if ( arr[k][q] == 0 )		score = 0;		//If value at that cell is 0, then score will reset to 0
		else				score+=arr[k][q];	//addition
		
		q = arr[k][q];						//As value of cell becomes [j] i.e q
		k++;
		jump++;
	}
	
	output( score , jump );
}

void output( int score , int jump )
{
	//							OUTPUT						
	cout << "Player score is: " << score << endl;
	cout << "Jumps are: " << jump << endl;
}

