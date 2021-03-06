/*
 * Timer.h
 *
 *  Created on: 24 de mar de 2017
 *      Author: aluno
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "Timeout.h"
#include "Singleton.h"

typedef unsigned long Hertz;
typedef unsigned long long Microseconds;
typedef unsigned long long Milliseconds;

typedef void (*CALLBACK_t)(void);

class Timer : public Singleton<Timer> {
public:
	/*
	 * Will configure timer to the closest frequency
	 * that does not produce rounding errors.
	 * Example:
	 *   freq	-	Actual Timer Frequency (Hz)
	 *   100	-	100,1602564
	 *   500	-	504,0322581
	 *   1000	-	1041,666667
	 *   2000	-	2232,142857
	 *   5000	-	5208,333333
	 *   10000	-	15625
	 */
	Timer(Hertz freq);

	Milliseconds millis();
	Microseconds micros();

	void delay(Milliseconds ms);
	void udelay(Microseconds us);

	static void ovf_isr_handler();

	void timeoutManager();
	void addTimeout(uint32_t interval, CALLBACK_t callback);

private:
	unsigned long long _ticks;
	unsigned int _timer_base;
	Microseconds _us_per_tick;
	static TIMEOUT _vetor[4];
	int _numero_timeout;

};

#endif /* TIMER_H_ */







