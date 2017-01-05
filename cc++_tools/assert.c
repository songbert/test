#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PRINT(format, args...) printf(format, ##args)
#define PRINT_TIME(format, args...) \
{ \
    time_t t; \
    time(&t); \
    struct tm *pTM = gmtime(&t); \
    PRINT("[%4d-%02d-%02d %02d:%02d:%02d]"" "format, \
        pTM->tm_year+1900, pTM->tm_mon+1, pTM->tm_mday, pTM->tm_hour+8, pTM->tm_min, pTM->tm_sec, ##args); \
}

#define ASSERT(exp) (void)((exp)||(_assert(#exp, __FILE__ , __LINE__), 0))
void _assert(void *exp, void *file, unsigned int line)
{
    PRINT_TIME("Assertion failed: %s, FILE: %s, LINE: %d\n", (char *)exp, (char *)file, line);
    abort();
}

int main(int agrc, char **argv)
{
    //ASSERT( 0 > 1);

    printf("Return\n");
    return 0;
}

