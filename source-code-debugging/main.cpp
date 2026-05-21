#include <cstdio>
#include <cstdlib>
#include <cstring>

char buf[50];

int sum_to_n(int num) {
    int i, sum = 0;
    for (i = 1; i <= num; i++)
        sum += i;
    return sum;
}

void printSum() {
    char line[10];
    printf("Enter a number: ");

    if (fgets(line, sizeof(line), stdin) != NULL) {
        strtok(line, "\n");

        sprintf(buf, "sum=%d", sum_to_n(atoi(line)));
        printf("%s\n", buf);
    }
}

int main() {
    printSum();
    return 0;
}
