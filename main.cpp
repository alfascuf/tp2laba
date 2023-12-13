#include <iostream>
#include "STUDENT.h"
#include "part2.h"

void BubbleSort(STUDENT arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].GetAverage() > arr[j + 1].GetAverage()) {

                STUDENT temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    const int maxStudents = 100;
    STUDENT students[maxStudents];
    int currentStudents = 0;
    int choice;
    int item;
    do {
        system("cls");

        std::cout << "�������� �������:" << std::endl;
        std::cout << "1. ���������� ������� ���������" << std::endl;
        std::cout << "2. ������� ����������� � �������� ������ �� �����" << std::endl;
        std::cout << "3. �����" << std::endl;
        std::cout << "> ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            int item;

        do {
            system("cls");

            std::cout << "��� �� ������ �������?" << std::endl;
            std::cout << "1. �������� ��������" << std::endl;
            std::cout << "2. ������� ��������� � �������� 4 � 5" << std::endl;
            std::cout << "3. ������� ���� ��������� ��������������� �� ������� ������" << std::endl; 
            std::cout << "4. ������� �������� �� �����" << std::endl;
            std::cout << "5. ������������� �������� �� �����" << std::endl;
            std::cout << "6. �����" << std::endl;  
            std::cout << "> ";
            std::cin >> item;

            try {
                if (item < 1 || item > 6) {  
                    throw std::string("������������ �����.");
                }

                switch (item) {
                case 1: {
                    STUDENT student;
                    std::cout << "������� ���������� � ����� ��������" << std::endl;
                    std::cin >> student;

                    if (currentStudents < maxStudents) {
                        students[currentStudents++] = student;
                        std::cout << "������� ��������" << std::endl;
                    }
                    else {
                        std::cout << "���������� ������������ ���������� ���������" << std::endl;
                    }
                }
                      break;

                case 2: {
                    // �������� ������� ���������� ���������
                    BubbleSort(students, currentStudents);

                    int count = 0;

                    for (int i = 0; i < currentStudents; i++) {
                        if (students[i].GetScores()[0] >= 4 && students[i].GetScores()[1] >= 4 &&
                            students[i].GetScores()[2] >= 4 && students[i].GetScores()[3] >= 4 &&
                            students[i].GetScores()[4] >= 4) {

                            if (count == 0) {
                                std::cout << std::endl << "�������� � �������� 4 � 5:" << std::endl << std::endl;
                            }

                            std::cout << students[i].GetName() << " (������ " << students[i].GetGroup() << ")" << std::endl;
                            count++;
                        }
                    }

                    if (count == 0) {
                        std::cout << std::endl << "��� ��������� � �������� 4 � 5" << std::endl;
                    }
                }
                      break;


   
                case 3: {
                    // ����� ������� ��� ������ ���� ��������� ��������������� �� ������� ������
                    STUDENT::DisplayAllSortedByAverage(students, currentStudents);
                }
                      break;
                case 4: {
                    // �������� �������� �� �����
                    std::string studentName;
                    std::cout << "������� ��� �������� ��� ��������: ";
                    std::cin >> studentName;
                    STUDENT::RemoveStudentByName(students, currentStudents, studentName);
                    system("pause");
                }
                    break;
                

                case 5: {
                    // �������������� �������� �� �����
                    std::string studentName;
                    std::cout << "������� ��� �������� ��� ��������������: ";
                    std::cin >> studentName;
                    STUDENT::EditStudentByName(students, currentStudents, studentName);
                    system("pause");
                }
                    break;
                

                case 6:  
                    break;
                }
            }
            catch (std::string s) {
                std::cout << s << std::endl;
            }

            if (item != 6) {  
                system("pause");
            }

        } while (item != 6); 
        break;
        }
        case 2: {
            // �������� ������� ��� ������� ������� �� part2.h
            partTwo();
            system("pause");
            break;
        }

        case 3:
            break;
        }

    } while (choice != 3);


    return 0;
}
