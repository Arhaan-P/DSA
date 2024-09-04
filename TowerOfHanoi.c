#include <stdio.h>
#include <math.h>

void numberofMoves(int n) {
    int power = pow(2, n);
    printf("Total number of moves: %d", power - 1);
}

void towerofhanoi(int n, char from, char to, char mid) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    towerofhanoi(n - 1, from, mid, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    towerofhanoi(n - 1, mid, to, from);
}
int main() {
    int n;
    scanf("%d", &n);
    towerofhanoi(n, 'A', 'C', 'B');
    numberofMoves(n);
}