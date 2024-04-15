#ifndef DATE_TYPE_H
#define DATE_TYPE_H

class dateType {
public:
    dateType(); // default constructor
    dateType(int m, int d, int y); // constructor with parameters

    // setter functions
    void setMonth(int m);
    void setDay(int d);
    void setYear(int y);

    // getter functions
    int getMonth() const;
    int getDay() const;
    int getYear() const;

    // other member functions
    bool isLeapYear() const;
    int daysInMonth(int m, int y) const;
    void printDate() const;
    int daysPassed() const;
    int daysRemaining() const;
    void setFutureDate(int days);

private:
    int month;
    int day;
    int year;

    // private member functions
    bool isValidDate(int m, int d, int y) const;
};

#endif // DATE_TYPE_H