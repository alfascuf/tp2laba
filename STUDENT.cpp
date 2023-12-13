#include "STUDENT.h"

using namespace std;

STUDENT::STUDENT() {
    cout << "STUDENT: ������ �����������" << endl;
    name = "tmp";
    group = 1;

    for (int i = 0; i < scoresCount; i++)
        scores[i] = 5;
}

STUDENT::STUDENT(const STUDENT& student) {
    cout << "STUDENT: ����������� �����������" << endl;
    name = student.name;
    group = student.group;

    for (int i = 0; i < scoresCount; i++)
        scores[i] = student.scores[i];
}

STUDENT::STUDENT(string name, int group, int scores[]) {
    cout << "STUDENT: ����������� � �����������" << endl;
    this->name = name;
    this->group = group;

    for (int i = 0; i < scoresCount; i++)
        this->scores[i] = scores[i];
}

string STUDENT::GetName() {
    return name;
}

int STUDENT::GetGroup() {
    return group;
}

const int* STUDENT::GetScores() const {
    return scores;
}


double STUDENT::GetAverage() {
    double average = 0;

    for (int i = 0; i < scoresCount; i++)
        average += scores[i];

    return average / 5.0;
}

void STUDENT::SetName(string name) {
    this->name = name;
}

void STUDENT::SetGroup(int group) {
    this->group = group;
}

void STUDENT::SetScores(const int* scores) {
    for (int i = 0; i < scoresCount; i++)
        this->scores[i] = scores[i];
}



STUDENT& STUDENT::operator=(const STUDENT& student) {
    if (this == &student)
        return *this;

    name = student.name;
    group = student.group;

    for (int i = 0; i < scoresCount; i++)
        scores[i] = student.scores[i];

    return *this;
}

STUDENT::~STUDENT() {
    cout << "STUDENT: ����������" << endl;
}

ostream& operator<<(ostream& os, const STUDENT& student) {
    os << "���: " << student.name << endl;
    os << "������: " << student.group << endl;
    os << "������: ";

    for (int i = 0; i < scoresCount; i++)
        os << student.scores[i] << " ";

    os << endl;

    return os;
}

istream& operator>>(istream& is, STUDENT& student) {
    cout << "������� ���: ";
    cin.ignore();
    getline(is, student.name);

    cout << "������� ����� ������: ";
    is >> student.group;

    if (student.group < 1)
        throw string("����� ������ ������ ���� �������������");

    cout << "������� ������: ";
    bool crash = false;

    for (int i = 0; i < scoresCount; i++) {
        is >> student.scores[i];

        if (student.scores[i] < 1 || student.scores[i] > 5)
            crash = true;
    }

    if (crash)
        throw string("������ ������ ���� �� 1 �� 5");

    return is;
}


void STUDENT::DisplayInfo() const {
    cout << "���: " << name << endl;
    cout << "������: " << group << endl;
    cout << "������: ";

    for (int i = 0; i < scoresCount; i++)
        cout << scores[i] << " ";

    cout << endl;
}


void STUDENT::DisplayAllSortedByAverage(STUDENT arr[], int n) {
    // ���������� ��������� �� ������� ������
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].GetAverage() > arr[j + 1].GetAverage()) {
                // �����
                STUDENT temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // ����� ����������
    std::cout << std::endl << "�������� ��������������� �� ������� ������:" << std::endl << std::endl;

    for (int i = 0; i < n; i++) {
        arr[i].DisplayInfo();
        std::cout << "������� ����: " << arr[i].GetAverage() << std::endl << std::endl;
    }
}


void STUDENT::RemoveStudentByName(STUDENT arr[], int& n, const std::string& name) {
    // ����� �������� �� �����
    for (int i = 0; i < n; ++i) {
        if (arr[i].GetName() == name) {
            // ����������� ���� ��������� ������ �� ���������� �� ���� ������� �����
            for (int j = i; j < n - 1; ++j) {
                arr[j] = arr[j + 1];
            }
            // ���������� ���������� ���������
            --n;
            std::cout << "������� " << name << " ������." << std::endl;
            return;
        }
    }

    std::cout << "������� " << name << " �� ������." << std::endl;
}

void STUDENT::EditStudentByName(STUDENT arr[], int n, const std::string& name) {
    // ����� �������� �� �����
    for (int i = 0; i < n; ++i) {
        if (arr[i].GetName() == name) {
            // �������������� ������ ��������
            std::cin >> arr[i];
            std::cout << "������� " << name << " ��������������." << std::endl;
            return;
        }
    }

    std::cout << "������� " << name << " �� ������." << std::endl;
}