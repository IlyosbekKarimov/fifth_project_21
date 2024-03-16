/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even" a % 2 == 0
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/
#include <math.h>
#include <stdio.h>

#define NMAX 30

int input(int *a, int *n);
double mean(int *a, int n);
double variance(int *a, int n);
double search(int *a, int n);

int main() {
    int n, data[NMAX];
    if (!input(data, &n)) {
        return 0;
    }
    if (getchar() == ' ') {
        printf("n/a");
        return 0;
    }
    search(data, n);
    return 0;
}

int input(int *a, int *n) {
    if (scanf("%d", n) != 1) {
        printf("n/a");
        return 0;
    }
    if (*n > NMAX) {
        printf("n/a");
        return 0;
    } else {
        for (int *p = a; p - a < *n; p++) {
            if (scanf("%d", p) != 1) {
                printf("n/a");
                return 0;
                break;
            }
        }
        return 1;
    }
}

double mean(int *a, int n) {
    double sum = 0, k = 0;
    double result;
    for (int *p = a; p - a < n; p++) {
        sum += *p;
        k++;
    }
    result = sum / k;
    return result;
}

double variance(int *a, int n) {
    double t = mean(a, n), result;
    double sum = 0, k = 0;
    for (int *p = a; p - a < n; p++) {
        sum += (*p - t) * (*p - t);
        k++;
    }
    result = (double)sum / ((double)k);
    return result;
}

double search(int *a, int n) {
    int found = 0;
    for (int *p = a; p - a < n; p++) {
        if (*p % 2 == 0 && *p >= mean(a, n) && *p <= mean(a, n) + 3 * sqrt(variance(a, n)) && *p != 0) {
            printf("%d ", *p);
            found = 1;
        }
    }
    if (found) {
        return 1;
    } else {
        printf("0");
        return 1;
    }
}