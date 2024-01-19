#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;


void Display( int );
bool Check_guess( char , string );
void Decision( string , string );

int main()
{
	int misses=0;
	string guess_word , name;				
	srand(time(0));

	string  words_arr[]={"air","all","allow","almost","alone","along","already","also","although","always","american","among","amount","analysis","animal","another","answer","any","anyone","baby","back","bad","bag","ball","bank","bar","software","programming","computer",
						"programmer","machine","algorithm","hardware","computing","software ","processor","program","development","editor","logic","compiler","interpreter","source","executable","link","computer memory","bios","integrated ","microcomputer","microprocessor","cybersystem",
						"library","computerize","mainframe","motherboard","graphics","business","television","information", "art","computable","computational",
						"computerologist","debugging","nanocomputer","programing","compute","supercomputer","ibook","hostmaster","antivirus","computerism","laptop","computerbased","softmodem","predictor",
						"telecomputer","cybersavvy","multinetworked",
						"screensaver","cyberjunkie","cyberterrorism","cyberinteraction","cybernetwork","interactive","macintosh","appender","linguistics","calculator","misclick","systems","cobol","sumer","editing","application","python","javascript","hacking","blockchain","fast"
						};
	    
		int size_of_arr = sizeof(words_arr)/sizeof(words_arr[0]);		//Getting size of array
		
		guess_word = words_arr[ rand()%size_of_arr ];					//For extracting a word to guess
		//If we initialize it in the start we cannot use this function of string. It creates of same size as of the word
		string hide_word( guess_word.length() , '_');				    //For hidding letters with '_'

	cout << guess_word << "  " << hide_word << endl;
	
	Decision( hide_word , guess_word );
	
	return 0;
}

bool Check_guess( char letter , string guess_word )					//Checks whether the letter is present or not
{
	int cnt=0;
	for( int i=0 ; i<guess_word.length() ; ++i )
			if( guess_word[i]==letter )			cnt++;
			
	return cnt;	
}


void Decision( string hide_word , string guess_word)
{

	int misses=0;
	char Guess_rep[30] , cnt=0 ;						//Char and count to store letters entered to check repetition
	
	cout << "Guessed word is: " <<  guess_word << endl;
		
	while ( (hide_word != guess_word) && (misses<6) )				//Condtion whether player wins or loses
	{
		bool rep=0;								//bool for repetition of letters
		char letter;
		
		Display( misses );							//Displays hangman in upated state
		
		cout << "\nYour hidden word: " << hide_word << endl;		
		cout << "\nMisses: " << misses << endl;						
	
		cout << "Enter your letter: ";			cin >> letter;
		
		for ( int i=0 ; i<30 ; ++i )							//Checks whether the letter repeats or not
			if( Guess_rep[i] == letter  )
			{
				rep=1;	break;
			}
				
		if ( rep )									//For continuing loop if letter repeats
		{
			system("clear");
			cout << "Oh!You entered same letter again.\n";
			continue;	
		}
				
		Guess_rep[cnt] = letter;
		cnt++;
			
		system("clear");
				
		if( Check_guess( letter , guess_word) == 0 )				//Wrong guess
		{
			misses++;
			cout << "Oho! Wrong guess.\n";
		}				
		else
		{
			cout << "Aha! You got it right.\n"; 					//Right guess

			for( int i=0 ; i<guess_word.length() ; ++i )
				if( guess_word[i]==letter )
					hide_word[i]=letter;									//UPdates my hide_word					
		}						
	}
	
	if( misses == 6 )												//If lost
	{
		Display( misses );
		cout << "You Lost!\n"
			 << "Word was: " << guess_word << endl;				
	}
	else 															//If Won
		cout << "\n\nWoohoo!\nCongratulation! You won.\n";
	
	
}


void Display( int misses )
{

	if( misses==0 ){
		cout << "\t\t\t+---+\n"
			 << "\t\t\t|   |\n"
			 << "\t\t\t    |\n"
			 << "\t\t\t    |\n"
			 << "\t\t\t    |\n"
			 << "\t\t\t    |\n"
			 << "\t\t     ==========\n";
	}
	
	else if( misses==1 ){
		cout << "\t\t\t+---+\n"
			 << "\t\t\t|   |\n"
			 << "\t\t\tO   |\n"
			 << "\t\t\t    |\n"
			 << "\t\t\t    |\n"
			 << "\t\t\t    |\n"
			 << "\t\t     ==========\n";
	}
	
	else if( misses==2 ){
		cout << "\t\t\t+---+\n"
			 << "\t\t\t|   |\n"
			 << "\t\t\tO   |\n"
			 << "\t\t\t|   |\n"
			 << "\t\t\t    |\n"
			 << "\t\t\t    |\n"
			 << "\t\t     ==========\n";
	}
	else if( misses==3 ){
		cout << "\t\t\t+---+\n"
			 << "\t\t\t|   |\n"
			 << "\t\t\tO   |\n"
			 << "\t\t       /|   |\n"
			 << "\t\t\t    |\n"
			 << "\t\t\t    |\n"
			 << "\t\t     ==========\n";
	}
	else if( misses==4 ){
		cout << "\t\t\t+---+\n"
			 << "\t\t\t|   |\n"
			 << "\t\t\tO   |\n"			
			 << "\t\t       /|\\  |\n"
			 << "\t\t\t    |\n"
			 << "\t\t     ==========\n";
	}
	
	else if( misses==5 ){
		cout << "\t\t\t+---+\n"
			 << "\t\t\t|   |\n"
			 << "\t\t\tO   |\n"			
			 << "\t\t       /|\\  |\n"
			 << "\t\t       /    |\n"
			 << "\t\t     ==========\n";
	}
	
	else if( misses==6 ){
		cout << "\t\t\t+---+\n"
			 << "\t\t\t|   |\n"
			 << "\t\t\tO   |\n"
			 << "\t\t       /|\\  |\n"
			 << "\t\t       / \\  |\n"
			 << "\t\t     ==========\n";
	}
}

















