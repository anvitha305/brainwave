/* brainwave.h
 * Monday, March 20th
 * Anvitha Ramachandran as part of anvitha305/brainwave
*/

#ifndef MAKE_WAV_H
#define MAKE_WAV_H

// port the brainfuck symbol to a note on the octatonic scale. [here refers to C diminished]
char* bf_note(char symbol);
// calculate frequency of a note such that it can be written to the wav file
int calc_freq(char *note);
#endif
