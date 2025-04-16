#include "Gradebook.hpp"

void Gradebook::addOrUpdateStudent(const string &studentName, double grade) {
    studentGrades[studentName] = grade;
}

bool Gradebook::removeStudent(const string &studentName) {
    auto it = studentGrades.find(studentName);
    if (it != studentGrades.end()) {
        studentGrades.erase(it);
        return true;
    }
    return false;
}

bool Gradebook::getGrade(const string &studentName, double &grade) const {
    auto it = studentGrades.find(studentName);
    if (it != studentGrades.end()) {
        grade = it->second;
        return true;
    }
    return false;
}

bool Gradebook::studentExists(const string &studentName) const {
    return studentGrades.find(studentName) != studentGrades.end();
}

void Gradebook::printGrades() const {
    if (studentGrades.empty()) {
        cout << "Gradebook kosong\n";
        return;
    }
    for (int i = 0; i < studentGrades.size(); i++) {
        auto it = studentGrades.begin();
        advance(it, i);
        cout << i + 1 << ". " << it->first << ": " << it->second << endl;
    }
}

void Gradebook::printGradesRank() const {
    if (studentGrades.empty()) {
        cout << "Gradebook kosong\n";
        return;
    }
    vector<pair<string, double>> sortedGrades(studentGrades.begin(), studentGrades.end());
    sort(sortedGrades.begin(), sortedGrades.end(), [](const auto &a, const auto &b) {
        return a.second > b.second;
    });

    for (int i = 0; i < sortedGrades.size(); i++) {
        cout << i + 1 << ". " << sortedGrades[i].first << ": " << sortedGrades[i].second << endl;
    }
}

vector<string> Gradebook::getStudentsWithGradeAbove(double threshold) const {
    vector<string> res;
    for (const auto &student : studentGrades) {
        if (student.second > threshold) {
            res.push_back(student.first);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

double Gradebook::getAverageGrade() const {
    double avg = 0.0;
    if (studentGrades.empty()) {
        return avg;
    }
    for (const auto &student : studentGrades) {
        avg += student.second;
    }
    return avg / studentGrades.size();
}

size_t Gradebook::getNumberOfStudents() const {
    return studentGrades.size();
}