#include <bits/stdc++.h>

/* Viết chương trình khởi tạo cấu trúc sinh viên có các thuộc tính id, name, age và phoneNumber.
Khai báo mảng sinh viên có 5 phần tử và gán giá trị cho mảng đã khai báo.

Xây dựng hàm sắp xếp sinh viên có tham số là mảng sinh viên. Hàm sẽ tiến hành sắp xếp lại mảng sinh viên theo tên sinh viên.

Gọi hàm để sắp xếp sinh viên, in mảng sinh viên ra màn hình để kiểm tra. */

typedef struct
{
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
} Student;

int cmp(const void *a, const void *b)
{
    Student *studentA = (Student *)a;
    Student *studentB = (Student *)b;
    return strcmp(studentA->name, studentB->name);
}

void printStudents(const Student students[], int length)
{
    for (int i = 0; i < length; ++i)
    {
        printf("ID: %d, Tên: %s, Tuổi: %d, SĐT: %s\n", students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }
}

int main()
{
    Student students[5] = {
        {1, "Cao", 20, "123-456-7890"},
        {2, "Thanh", 21, "234-567-8901"},
        {3, "Long", 22, "345-678-9012"},
        {4, "CaoLong", 23, "456-789-0123"},
        {5, "ThanhCao", 24, "567-890-1234"}};
    int currentLength = 5;

    printf("Danh sách sinh viên ban đầu:\n");
    printStudents(students, currentLength);

    qsort(students, currentLength, sizeof(Student), cmp);
    printf("\n");
    printf("Danh sách sinh viên sau khi sắp xếp:\n");
    printStudents(students, currentLength);

    return 0;
}