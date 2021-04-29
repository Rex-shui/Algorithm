//
//  tools.c
//  AlgorithmRepository
//
//  Created by 水小水 on 2021/4/23.
//

#include "tools.h"

static char ret[32] = {0};

char *getSysTime()
{
    time_t timer;
    struct tm *now;
    
    timer = time(NULL);
    
    now = localtime(&timer);
    
    memset(ret, 0, 32);
    
    sprintf(ret, "%04d-%02d-%02d %02d:%02d:%02d", now->tm_year+1900, now->tm_mon+1,
            now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec);
    
    return ret;
}

int getRand(int range)
{

	int r = rand()%range;

	return r;
}
