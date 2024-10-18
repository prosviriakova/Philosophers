#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

void check_usleep_accuracy(long microseconds)
{
    struct timeval start, end;
    long elapsed_time;

    gettimeofday(&start, NULL);
    usleep(microseconds);
    gettimeofday(&end, NULL);

    elapsed_time = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);

    printf("Requested delay: %ld microseconds\n", microseconds);
    printf("Actual delay: %ld microseconds\n", elapsed_time);
}

int main()
{
    check_usleep_accuracy(10000);
    check_usleep_accuracy(50000);
    check_usleep_accuracy(100000);
    check_usleep_accuracy(200000);
    check_usleep_accuracy(400000);

    return 0;
}
