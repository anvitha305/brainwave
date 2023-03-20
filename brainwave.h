/* brainwave.h
 * Monday, March 20th
 * Anvitha Ramachandran as part of anvitha305/brainwave
*/

#ifndef MAKE_WAV_H
#define MAKE_WAV_H

// port the brainfuck symbol to a note on the octatonic scale.
char* bf_note(char symbol);
// calculate frequency of a note such that it can be written to the wav file
int calc_freq(char *note);
// writing the data to a wav file
void write_to_wav(char *fname, unsigned long samp, short int *data, int s_rate);
#endif
