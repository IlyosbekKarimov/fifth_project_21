#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    if (!input(data, &n)) {
        return 0;
    }
    if (getchar() == ' ') {
        printf("n/a");
        return 0;
    } else {
        output(data, n);
        puts("");
        output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));
    }
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

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d ", *p);
    }
}

int max(int *a, int n) {
    int maksima = a[0];
    for (int *p = a; p - a < n; p++) {
        if (*p > maksima) {
            maksima = *p;
        }
    }
    return maksima;
}

int min(int *a, int n) {
    int minima = a[0];
    for (int *p = a; p - a < n; p++) {
        if (*p < minima) {
            minima = *p;
        }
    }
    return minima;
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

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %.6f %.6f", max_v, min_v, mean_v, variance_v);
}