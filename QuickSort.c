#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 10
#define MAX_NAME_LENGTH 50
#define MAX_MAJOR_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float gpa;
    int age;
    char major[MAX_MAJOR_LENGTH];
} Student;

void swap(Student *a, Student *b) {
    Student temp = *a;
    *a = *b;
    *b = temp;
}

// QuickSort and Partition for GPA
int partitionByGPA(Student arr[], int start, int end) {
    float pivot = arr[end].gpa;
    int partitionIndex = start;
    for (int i = start; i < end; i++) {
        if (arr[i].gpa < pivot) {
            swap(&arr[i], &arr[partitionIndex]);
            partitionIndex++;
        }
    }
    swap(&arr[partitionIndex], &arr[end]);
    return partitionIndex;
}

void quickSortByGPA(Student arr[], int start, int end) {
    if (start < end) {
        int pi = partitionByGPA(arr, start, end);
        quickSortByGPA(arr, start, pi - 1);
        quickSortByGPA(arr, pi + 1, end);
    }
}

// QuickSort and Partition for Age
int partitionByAge(Student arr[], int start, int end) {
    int pivot = arr[end].age;
    int partitionIndex = start;
    for (int i = start; i < end; i++) {
        if (arr[i].age < pivot) {
            swap(&arr[i], &arr[partitionIndex]);
            partitionIndex++;
        }
    }
    swap(&arr[partitionIndex], &arr[end]);
    return partitionIndex;
}

void quickSortByAge(Student arr[], int start, int end) {
    if (start < end) {
        int pi = partitionByAge(arr, start, end);
        quickSortByAge(arr, start, pi - 1);
        quickSortByAge(arr, pi + 1, end);
    }
}

// QuickSort and Partition for Maior
int partitionByMajor(Student arr[], int start, int end) {
    char *pivot = arr[end].major;
    int partitionIndex = start;
    for (int i = start; i < end; i++) {
        if (strcmp(arr[i].major, pivot) < 0) {
            swap(&arr[i], &arr[i]);
            partitionIndex++;
        }
    }
    swap(&arr[partitionIndex], &arr[end]);
    return partitionIndex;
}

void quickSortByMaior(Student arr[], int start, int end) {
    if (start < end) {
        int pi = partitionByMajor(arr, start, end);
        quickSortByMaior(arr, start, pi - 1);
        quickSortByMaior(arr, pi + 1, end);
    }
}

// QuickSort and Partition for Name
int partitionByName(Student arr[], int start, int end) {
    char *pivot = arr[end].name;
    int partitionIndex = start;
    for (int i = start; i < end; i++) {
        if (strcmp(arr[i].name, pivot) < 0) {
            swap(&arr[i], &arr[partitionIndex]);
            partitionIndex++;
        }
    }
    swap(&arr[partitionIndex], &arr[end]);
    return partitionIndex;
}

void quickSortByName(Student arr[], int start, int end) {
    if (start < end) {
        int pi = partitionByName(arr, start, end);
        quickSortByName(arr, start, pi - 1);
        quickSortByName(arr, pi + 1, end);
    }
}

void inputStudentRecords(Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("GPA: ");
        scanf("%f", &students[i].gpa);
        printf("Age: ");
        scanf("%d", &students[i].age);
        printf("Maior: ");
        scanf("%s", students[i].major);
    }
}

void printStudentRecords(Student students[], int n) {
    printf("Sorted Student Records:\n");
    printf("Name\t\tGPA\tAge\t\tMajor\n");
    for (int i = 0; i < n; i++) {
        printf("%-10s\t%.2f\t%-5d\t%-10s\n", students[i].name, students[i].gpa, students[i].age, students[i].major);
    }
}

int main() {
    int n;
    printf("Enter the number of student records: ");
    scanf("%d", &n);

    Student students[MAX_STUDENTS];

    inputStudentRecords(students, n);

    char criterion[10];
    printf("Enter sorting criterion (name, gpa, age, maior): ");
    scanf("%s", criterion);

    if (strcmp(criterion, "gpa") == 0) {
        quickSortByGPA(students, 0, n - 1);
    } else if (strcmp(criterion, "age") == 0) {
        quickSortByAge(students, 0, n - 1);
    } else if (strcmp(criterion, "maior") == 0) {
        quickSortByMaior(students, 0, n - 1);
    } else if (strcmp(criterion, "name") == 0) {
        quickSortByName(students, 0, n - 1);
    } else {
        printf("Invalid sorting criterion.\n");
        return 1;
    }

    printStudentRecords(students, n);

    return 0;
}