//
//  main.c
//  Time As A Struct
//
//  Created by Adrian Bruce Cunanan on 4/24/13.
//  Copyright (c) 2013 ThriveStreams. All rights reserved.
//

#include <stdio.h>
#include <time.h>

const long SECS_FROM_NOW = 40000000;
const long ADJ_YEAR = 1900;

int main(int argc, const char * argv[])
{

    long secondsSince1970 = time(NULL);
    printf("It has been %ld seconds since 1970.\n", secondsSince1970);
    
    struct tm now, then;
    localtime_r(&secondsSince1970, &now);
    printf("The time is %d:%d:%d.\n", now.tm_hour, now.tm_min, now.tm_sec);
    
    long secondsFromNow = secondsSince1970 + SECS_FROM_NOW;
    printf("We want to travel to %ld seconds since 1970.\n", secondsFromNow);
    
    localtime_r(&secondsFromNow, &then);
    then.tm_year+= ADJ_YEAR; /* adjust since tm_year is since 1900 */
    then.tm_mon++; /* adjust since 0 means January */
    printf("The date 4M seconds from now will be %d-%d-%d.", then.tm_mon, then.tm_mday, then.tm_year);
    
    return 0;
}

