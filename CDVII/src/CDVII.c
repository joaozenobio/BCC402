#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "CDVII.h"

int compLicense(const void *a, const void *b) {
    return strcmp(((Record*)a)->license,((Record*)b)->license);
}

int compDate(const void *a, const void *b) {
    return difftime(mktime(&((Record*)a)->date), mktime(&((Record*)b)->date));
}

int compRecord(const void *a, const void *b) {
    int result = compLicense(a, b);
    if(result != 0) {
    	return result;
    }
    else {
    	return compDate(a, b);
    }
}


int cdvii() {
    int N;
    fscanf(stdin, "%d", &N);
    for(int i = 0; i < N; i++) {
        getchar();
        /**
         * Get the fare in cents/kilometer for each hour of the day in 24h system.
         */
        int farePerHour[24];
        for(int j = 0; j < 24; j++) {
            fscanf(stdin, "%d", &farePerHour[j]);
        }
        Record records[1000];
        getchar();
        int counter = 0;
        /**
         * Get each record.
         */
        for(int k = 0; k < 1000; k++) {
            char buffer[100];
            fgets(buffer, 100, stdin);
            buffer[strlen(buffer)-1] = '\0';
            /**
             * Check if blank line was found, that means all records were collected.
             */
            if(strlen(buffer) == 0) break;
            sscanf(buffer, "%s %d:%d:%d:%d %s %d", records[k].license, &(records[k].date.tm_mon),
                                                   &(records[k].date.tm_mday), &(records[k].date.tm_hour),
                                                   &(records[k].date.tm_min), records[k].type,
                                                   &(records[k].location));
            counter++;
        }
        /**
         * Sort records to separate than by their license number and date.
         */
        qsort(records, counter, sizeof(Record), compRecord);
        for(int l = 0; l < counter;) {
            char licenseAux[21];
	    strcpy(licenseAux, records[l].license);
	    /**
 	     * Calculate the total fare for each license number comparing enterings and exits from the road already sorted and united one after the other by date.
 	     */
	    double fareSum = 2;
	    while(strcmp(records[l].license, licenseAux) == 0) {
		fareSum += 1;
	    	if(strcmp(records[l].type, "enter") == 0 && strcmp(records[l+1].type, "exit") == 0) {
		    fareSum += (records[l+1].location -  records[l].location) * (0.01 * farePerHour[records[l].date.tm_hour]);
		}
		l += 2;
	    }
	    /**
 	     * Print the license number and its corresponding fare.
 	     */
	    printf("%s %.2lf\n", licenseAux, fareSum);
        }
    }
    return 0;
}
