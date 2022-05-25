//
// Created by joaozenobio on 13/05/22.
//

#ifndef PARTE1_CDVII_H
#define PARTE1_CDVII_H


#include <time.h>

/**
 * Structer that define each record of the system.
 * @param type represents the car movement: enter the road, exists the road.
 */
typedef struct {
    char license[21];
    struct tm date;
    char type[6];
    int location;
}Record;

/**
 * Compare two records based on the license number.
 */
int compLicense(const void *a, const void *b);

/**
 * Compare two records based on the date.
 */
int compDate(const void *a, const void *b);

/**
 * Compare two records firstly based on the license number and then on the date.
 */
int compRecord(const void *a, const void *b);


int cdvii();


#endif //PARTE1_CDVII_H
