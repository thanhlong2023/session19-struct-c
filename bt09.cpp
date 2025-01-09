#include <bits/stdc++.h>

/*Kết hợp các bài tập trước, xây dựng chương trình hiển thị và thực hiện các chức năng theo menu sau:

    MENU

Hiển thị danh sách sinh viên

Thêm sinh viên

Sửa thông tin sinh viên

Xóa sinh viên

Tìm kiếm sinh viên

Sắp xếp danh sách sinh viên

Thoát

 Lựa chọn của bạn:

Sau khi nhập lựa chọn chương trình sẽ thực hiện chức năng tương ứng, sau khi thực hiện chức năng menu sẽ lại hiện lên. Chương trình sẽ lặp lại liên tục cho đến khi người dùng chọn thoát.*/

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

int main()
{
    Student sinhvien[100] = {
        {1, "Cao", 20, "123-456-7890"},
        {2, "Thanh", 21, "234-567-8901"},
        {3, "Long", 22, "345-678-9012"},
        {4, "CaoLong", 23, "456-789-0123"},
        {5, "ThanhCao", 24, "567-890-1234"}};
    int currentLength = 5;
    int choice;
    do
    {
        printf("Menu\n");
        printf("1. Hiển thị danh sách sinh viên\n");
        printf("2. Thêm sinh viên\n");
        printf("3. Sửa thông tin sinh viên\n");
        printf("4. Xóa sinh viên\n");
        printf("5. Tìm kiếm sinh viên\n");
        printf("6. Sắp xếp danh sách sinh viên\n");
        printf("7. Thoát\n");
        printf("Lựa chọn của bạn: ");
        scanf("%d", &choice);
        getchar(); // Để xử lý ký tự newline còn lại trong bộ đệm
        switch (choice)
        {
        case 1:
        {
            printf("Danh sách sinh viên:\n");
            for (int i = 0; i < currentLength; ++i)
            {
                printf("ID: %d, Tên: %s, Tuổi: %d, SĐT: %s\n", sinhvien[i].id, sinhvien[i].name, sinhvien[i].age, sinhvien[i].phoneNumber);
            }
            break;
        }
        case 2:
        {
            Student newStudent;
            int idNew = currentLength + 1;
            newStudent.id = idNew;
            printf("Nhập tên sinh viên: ");
            fgets(newStudent.name, 50, stdin);
            newStudent.name[strcspn(newStudent.name, "\n")] = '\0'; // Xóa ký tự newline
            printf("Nhập tuổi sinh viên: ");
            scanf("%d", &newStudent.age);
            getchar();
            printf("Nhập số điện thoại sinh viên: ");
            scanf("%s", newStudent.phoneNumber);
            getchar();
            sinhvien[currentLength] = newStudent;
            currentLength++;
            printf("Đã thêm sinh viên mới.\n");
            break;
        }
        case 3:
        {
            int idEdit;
            printf("Nhập ID của sinh viên cần sửa: ");
            scanf("%d", &idEdit);
            getchar();
            int index = -1;
            for (int i = 0; i < currentLength; ++i)
            {
                if (sinhvien[i].id == idEdit)
                {
                    index = i;
                    break;
                }
            }
            if (index == -1)
            {
                printf("Không tìm thấy sinh viên với ID %d.\n", idEdit);
                break;
            }
            printf("Nhập tên sinh viên: ");
            fgets(sinhvien[index].name, 50, stdin);
            sinhvien[index].name[strcspn(sinhvien[index].name, "\n")] = '\0'; // Xóa ký tự newline
            printf("Nhập tuổi sinh viên: ");
            scanf("%d", &sinhvien[index].age);
            getchar();
            printf("Nhập số điện thoại sinh viên: ");
            scanf("%s", sinhvien[index].phoneNumber);
            getchar();
            printf("Đã sửa thông tin sinh viên.\n");
            break;
        }
        case 4:
        {
            int idDelete;
            printf("Nhập ID của sinh viên cần xóa: ");
            scanf("%d", &idDelete);
            getchar();
            int index = -1;
            for (int i = 0; i < currentLength; ++i)
            {
                if (sinhvien[i].id == idDelete)
                {
                    index = i;
                    break;
                }
            }
            if (index == -1)
            {
                printf("Không tìm thấy sinh viên với ID %d.\n", idDelete);
                break;
            }
            for (int i = index; i < currentLength - 1; ++i)
            {
                sinhvien[i] = sinhvien[i + 1];
            }
            currentLength--;
            printf("Đã xóa sinh viên với ID %d.\n", idDelete);
            break;
        }
        case 5:
        {
            char nameSearch[50];
            printf("Nhập tên sinh viên cần tìm: ");
            fgets(nameSearch, 50, stdin);
            nameSearch[strcspn(nameSearch, "\n")] = '\0'; // Xóa ký tự newline
            int found = 0;
            for (int i = 0; i < currentLength; ++i)
            {
                if (strcmp(sinhvien[i].name, nameSearch) == 0)
                {
                    printf("ID: %d, Tên: %s, Tuổi: %d, SĐT: %s\n", sinhvien[i].id, sinhvien[i].name, sinhvien[i].age, sinhvien[i].phoneNumber);
                    found = 1;
                }
            }
            if (found == 0)
            {
                printf("Không tìm thấy sinh viên với tên %s.\n", nameSearch);
            }
            break;
        }
        case 6:
        {
            qsort(sinhvien, currentLength, sizeof(Student), cmp);
            printf("Danh sách sinh viên sau khi sắp xếp:\n");
            for (int i = 0; i < currentLength; ++i)
            {
                printf("ID: %d, Tên: %s, Tuổi: %d, SĐT: %s\n", sinhvien[i].id, sinhvien[i].name, sinhvien[i].age, sinhvien[i].phoneNumber);
            }
            break;
        }
        case 7:
        {
            printf("Thoát chương trình.\n");
            break;
        }
        default:
        {
            printf("Lựa chọn không hợp lệ. Vui lòng chọn lại.\n");
            break;
        }
        }
    } while (choice != 7);
    return 0;
}