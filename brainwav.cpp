#include <iostream>
#include <fstream>
#include <string>
using namespace std;


// returns relative position on the whole step/half step scale 
int bf_pstn(char symbol)
{
	switch(symbol){
		case '>':
			return 0;
	    	case '<':
			return 2;
	     	case '+':
		  	return 3;
	     	case '-':
	        	return 5;
	     	case '.':
			return 6;
	    	case ',':
		    	return 8;
	    	case '[':
		    	return 9;
		case ']':
		    	return 11;
		default:
			return -1;
   	}
}

// create the wav file from the brainfuck source file and a base note

void brainwav()

int main(int argc, char *argv[])
{
	string s(argv[2]);
	if (argc == 2 and tolower(s)=="help")
		cout << "hiii :3";
	if(argc!= 3)
		cout << "Insufficient args. Proper usage: ./brainwav <base note> <brainfuck filename>\n";
		cout << "Use ./brainwav help to explain the program.";
	
}

