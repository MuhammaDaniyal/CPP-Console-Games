#include <iostream>
using namespace std;

int main()
{

	char maze[7][6];
	int posi=1 , posj=1 , pre_posi=1 , pre_posj=1;
	char move;

	do{

		for ( int i=0 ; i<8 ;++i )					//For making maze
		{	for ( int j=0 ; j<7 ; ++j )
			{			
				if   ( i==0 || i==7 || j==0 || ( j==6 && i!=3 ) || ( i==3 && j==2 ) || (i==3 && j==3) || (i==5 && j==2) ) 
			    {
					maze[i][j] = '#';
					cout << maze[i][j]; 
				}
				else if ( posi==i && posj==j )
				{
					maze[i][j] = '*';
					cout << maze[i][j];
				}
				else
			 	{
					maze[i][j] = ' ';		
					cout << maze[i][j];
				}
			}
			cout << endl;
		}

		
		cin.get(move);
	
		pre_posi=posi;	pre_posj=posj;
	
			if      ( move=='d' )  posj++;	
			else if ( move=='a' )  posj--;		
			else if ( move=='w' ) 	posi--; 		
			else if ( move=='s' ) 	posi++; 	 	

		if ( posi==3 && posj==6 );
			
		
		else if ( maze[posi][posj] == '#' )
		{
			posi=pre_posi;		posj=pre_posj;
			cout << "\a";
		}
		
		system("clear");
	
		if ( posi==3 && posj==6 )	cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t[   You Win!  ]\n\n\n\n\n\n\n";


	}while( !(posi==3 && posj==6) );
	


return 0;
}
