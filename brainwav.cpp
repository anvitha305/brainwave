#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
namespace little_endian
{
	template <typename Word>
		ostream& write_word(ostream& outs, Word value, unsigned size = sizeof(Word)){
			for (; size; --size, value >>= 8)
      				outs.put( static_cast <char> (value & 0xFF) );
    			return outs;
		}
	template <typename Word>
		istream& read_word(istream& ins, Word& value, unsigned size = sizeof(Word)){
			for (unsigned n = 0, value = 0; n < size; ++n)
      				value |= ins.get() << (8 * n);
    			return ins;
		}
}
using namespace little_endian;
// returns relative position on the whole step/half step scale 
int bf_pstn(char symbol){
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

// creates a wav file
void makeWAV(){
	ofstream fi("test.wav", ios::binary);
	fi << "RIFF----WAVEfmt "; // chunk size placeholder
	write_word(fi, 16, 4); // length of format data
	write_word(fi, 1, 2); // pcm
	write_word(fi, 2, 2); // stereo - 2 channels
	write_word(fi, 44100, 4); // sampling rate
	write_word(fi, 176400, 4); // (Sample Rate * BitsPerSample * Channels) / 8
	write_word(fi, 4, 2); // data block size
	write_word(fi, 16, 2); // bits per sample
	size_t data_chunk_pos = fi.tellp(); // write header
	fi << "data----"; // chunk size placeholder
	
	const double max_amplitude = 32760;  // "volume"
	
	size_t file_length = fi.tellp(); // file size
	fi.seekp(data_chunk_pos+4); // fix data chunk header
	write_word(fi, file_length-data_chunk_pos+8);
	fi.seekp(4);
	write_word(fi, file_length-8, 4);
	fi.close();
}

int main(int argc, char *argv[])
{
	/*vector<string> args(argv, argv+argc);
	cout << args[1] << "\n";
	if(argc!= 3){
		cout << "Incorrect args. Proper usage: ./brainwav <base note> <brainfuck filename>\n";
		cout << "The base note refers to the note at which the offsets for the whole-step half-step scale are calculated.\n";
	}
	return 0;*/
	makeWAV();
	cout << M_PI << "\n";
}

