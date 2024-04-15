#include "dateType.h"
#include <iostream>

dateType::dateType() {
    month = 1;
    day = 1;
    year = 1900;
}

dateType::dateType(int m, int d, int y) {
    if (isValidDate(m, d, y)) {
        month = m;
        day = d;
        year = y;
    }
    else {
        std::cerr << "Invalid date. Using default date (1/1/1900)." << std::endl;
        month = 1;
        day = 1;
        year = 1900;
    }
}

void dateType::setMonth(int m) {
    if (m >= 1 && m <= 12)
        month = m;
    else
        std::cerr << "Invalid month. No changes made." << std::endl;
}

void dateType::setDay(int d) {
    if (isValidDate(month, d, year))
        day = d;
    else
        std::cerr << "Invalid day. No changes made." << std::endl;
}

void dateType::setYear(int y) {
    if (y >= 1900)
        year = y;
    else
        std::cerr << "Invalid year. No changes made." << std::endl;
}

int dateType::getMonth() const {
    return month;
}

int dateType::getDay() const {
    return day;
}

int dateType::getYear() const {
    return year;
}

bool dateType::isLeapYear() const {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int dateType::daysInMonth(int m, int y) const {
    if (m == 2) {
        if (isLeapYear())
            return 29;
        else
            return 28;
    }
    else if (m == 4 || m == 6 || m == 9 || m == 11) {
        return 30;
    }
    else {
        return 31;
    }
}

void dateType::printDate() const {
    std::cout << month << "-" << day << "-" << year << std::endl;
}

int dateType::daysPassed() const {
    int daysPassed = day - 1;
    for (int i = 1; i < month; ++i) {
        daysPassed += daysInMonth(i, year);
    }
    return daysPassed;
}

int dateType::daysRemaining() const {
    int remainingDays = daysInMonth(month, year) - day;
    for (int i = month + 1; i <= 12; ++i) {
        remainingDays += daysInMonth(i, year);
    }
    return remainingDays;
}

void dateType::setFutureDate(int days) {
    int totalDays = daysPassed() + days;
    while (totalDays > 365) {
        if (isLeapYear()) {
            if (totalDays > 366) {
                totalDays -= 366;
                year++;
            }
        }
        else {
            totalDays -= 365;
            year++;
        }
    }
    int remainingDays = totalDays;
    month = 1;
    while (remainingDays > 0) {
        int daysInCurrentMonth = daysInMonth(month, year);
        if (remainingDays >= daysInCurrentMonth) {
            remainingDays -= daysInCurrentMonth;
            month++;
        }
        else {
            day = remainingDays + 1;
            remainingDays = 0;
        }
    }
}

bool dateType::isValidDate(int m, int d, int y) const {
    if (m < 1 || m > 12)
        return false;
    if (d < 1 || d > daysInMonth(m, y))
        return false;
    if (y < 1900)
        return false;
    return true;
}