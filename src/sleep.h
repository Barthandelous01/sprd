#ifndef _SLEEP_H_
#define _SLEEP_H_

void sleep_ms(int ms);
int time_incriment(int wpm, int chunks);
void next_chunk(char *string, int start, int *end, int chunks, int length);

#endif	/* _SLEEP_H_ */
