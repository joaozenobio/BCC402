#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "BeeMaja.h"

P beeMaja(int n) {
    /*
     * Start from "0" and "0, 0"
     */
    n--;
    P p = {0, 0};
    int counter = 1;
    int counterTemp;
    while(n != 0) {
	/*
	 * Begin moving downwards as Willi’s coordinate system does on every complete circle
	 */
        (p.y)++;
        n--;
        counterTemp = counter - 1;

	/*
	 * While there are still steps to go on Willi's coordinate system, continue moving. Counter will
	 * decide how many steps for each direction Wiili does according to the size of the hexagon to
	 * continue moving around it. EX: The second hexagon has 12 points and two step on each direction
	 * are necessary to move around it.
	 */

	/*
	 * Move to left downward diagonal.
	 */
        while(counterTemp > 0 && n != 0) {
            (p.x)--;
            (p.y)++;
            counterTemp--;
            n--;
        }
        counterTemp = counter;

	/*
         * Move left upward diagonal.
         */
	while(counterTemp > 0 && n != 0) {
            (p.x)--;
            counterTemp--;
            n--;
        }
        counterTemp = counter;

	/*
         * Move upward.
         */
	while(counterTemp > 0 && n != 0) {
            (p.y)--;
            counterTemp--;
            n--;
        }
        counterTemp = counter;

	/*
         * Move to right upward diagonal.
         */
	while(counterTemp > 0 && n != 0) {
            (p.x)++;
            (p.y)--;
            counterTemp--;
            n--;
        }
        counterTemp = counter;

	/*
         * Move left updward diagonal.
         */
	while(counterTemp > 0 && n != 0) {
            (p.x)++;
            counterTemp--;
            n--;
        }
        counterTemp = counter;

	/*
         * Move downward.
         */
	while(counterTemp > 0 && n != 0) {
            (p.y)++;
            counterTemp--;
            n--;
        }
        counter++;
    }
    return p;
}
