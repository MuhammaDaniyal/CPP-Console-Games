#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
using namespace std;
int main() {

/*
You are required to simulate a two-player dice rolling game using a C++ program. The program will
start and ask for the Complete Names and Roll Numbers of the two players playing the game. The
game has following rules.
The players roll two 6-sided dice each and get points depending on what they roll. There are 5
rounds in a game. In each round, each player rolled the dice twice.
1. The points rolled on each player’s dice are added to their score.
2. If the total matches with the sum of last 2 digit of a player then the player gets additional n
points where n is the last digit of the Roll Number.
3. If the total matches with m where m is index of the last alphabet of the name of the player
then player gets additional 5 points. (Index of A is 1, B is 2, C is 3 and so on. Index is not case
sensitive)4. If a player rolls a double and when the sum of the roll is used as “a” in the following
equation and the equation gets a single solution then the player gets an extra roll.
𝑥 ' − 𝑎𝑥 + 𝑎 = 0
5. The person with the highest score at the end of the 5 rounds wins.
6. If both players have the same score at the end of the 5 rounds, they each roll 1 die and
whoever gets the highest score wins (this repeats until someone wins).
*/

	int sum=1,sum_=1;

	int score1_p1 = 0, score2_p1 = 0 ,score1_p2 = 0, score2_p2 = 0 ;
	string player1_name, player2_name;
	int player1_roll, player2_roll,
		dice_roll;
	int	sum1 = 0 , sum2 = 0;
	char ch1='q' , ch2='q';
	
	do{		cout << "What is the name of player 1: ";			getline(cin,player1_name);
			ch1 = player1_name.at(player1_name.length()-1);	} while( !(ch1 >= 65 && ch1 <= 122) );	//Last char p1
	
	do{		cout << "What is the name of player 2: ";			getline(cin,player2_name);
			ch2 = player2_name.at(player2_name.length()-1);	} while( !(ch2 >= 65 && ch2 <= 122) );//Last char p2	

	do{cout << "What is the roll number of player 1: ";	cin >> player1_roll;               	}  while( player1_roll<0 );

	do{		cout << "What is the roll number of player 2: ";	cin >> player2_roll;}  while( player2_roll<0 );
	
	cout << endl;
	
int sum_roll_p1 , sum_roll_p2;
	sum_roll_p1 =(player1_roll%10) + ((player1_roll/10)%10);			//sum of roll of player 1
	sum_roll_p2 =(player2_roll%10) + ((player2_roll/10)%10);			//sum of roll of player 2

int	extra1, extra2 , index1 , index2;				

	if( ch1<=96 )		index1 = ch1 - 64;								//Indexing capital letters
	else			index1 = ch1 - 96;
	
	if( ch2<=96 )		index2 = ch2 - 64;
	else			index2 = ch2 - 96;								//Indexing small letters
		
	srand(time(0));

	int k=5;

for( int i=1 ; i<2 ; ++i ){

	
	for ( int j=1 ; j<=k ; ++j ){
			
		//For player 1
		
		score1_p1 = (rand()%6)+1;
		score2_p1 = (rand()%6)+1;
		
		sum1 = sum1 + score1_p1 + score2_p1;
		
		if( index1 == ( score1_p1 + score2_p1 ) ){
			sum1 = sum1 + 5;
			cout << "Yess! Index matched sum of scores of player 1" << endl; }
		
		if( sum_roll_p1 == ( score1_p1 + score2_p1) ){
			sum1 = sum1 + sum_roll_p1;
			cout << "Hahaha! sum of last digits of roll number matched sum of scores for player 1" << endl;}
		
		if( sum_roll_p1 == 4 ){
			cout << "Wohooo! Extra turn for player 1" << endl;
			extra1 = (rand()%6)+1;
			sum1 = sum1 + extra1;	
			
			while( extra1 == 4 )	{
				extra1 = (rand()%6)+1;
				sum1= sum1 + extra1;
				cout << "Oh! Miracle got another extra turn for player 1" << endl;}			
		}
		cout << "Sum of scores of player 1 is: " << sum1 << endl << endl;
		
		//For player 2
		
		score1_p2 = (rand()%6)+1;
		score2_p2 = (rand()%6)+1;
		
		sum2 = sum2 + score1_p2 + score2_p2;
		
		if( index2 == ( score1_p2 + score2_p2 ) ){
			sum2 = sum2 + 5; 
			cout << "Yess! Index matched sum of scores of player 2" << endl; }
		
		if( sum_roll_p2 == ( score1_p2 + score2_p2) ){	
			sum2 = sum2 + sum_roll_p2;
			cout << "Hahaha! sum of last digits of roll number matched sum of scores for player 2" << endl;}
		
		if( sum_roll_p2 == 4 ){
			cout << "Wohooo! Extra turn for player 2" << endl;
			extra2 = (rand()%6)+1;
			sum2 = sum2 + extra2;	
			
			while( extra2 == 4 )	{
				extra2 = (rand()%6)+1;
				sum2 = sum2 + extra2;
				cout << "Oh! Miracle got another extra turn for player 2" << endl;}	
		}
		cout << "Sum of scores of player 2 is: " << sum2 << endl ;
		
		cout << endl << "=======================================================================================" << endl;
	}
	
	
	
		if( sum1 == sum2 ){
			--i;  k=1;
			cout << "Oh! A tie lets have one more round" << endl;
			sum_++;}
		else{
			if( sum1>sum2 )	cout << player1_name << " Wins!" << endl;
			else    		cout << player2_name << " Wins!" << endl;
		}	
		

	
	}
	
	
	return 0;
}

