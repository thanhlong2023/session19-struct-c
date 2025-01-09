#include <stdio.h>
#include <string.h>

typedef struct
{
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
} Student;

void deleteStudentById(int id, Student students[], int *currentLength)
{
    int index = -1;
    for (int i = 0; i < *currentLength; ++i)
    {
        if (students[i].id == id)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        printf("Không tìm thấy sinh viên với ID %d.\n", id);
        return;
    }
    for (int i = index; i < *currentLength - 1; ++i)
    {
        students[i] = students[i + 1];
    }
    (*currentLength)--;
    printf("Đã xóa sinh viên với ID %d.\n", id);
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

    int idToDelete;
    printf("Nhập ID của sinh viên cần xóa: ");
    scanf("%d", &idToDelete);

    deleteStudentById(idToDelete, students, &currentLength);

    printf("Danh sách sinh viên sau khi xóa:\n");
    printStudents(students, currentLength);

    return 0;
}