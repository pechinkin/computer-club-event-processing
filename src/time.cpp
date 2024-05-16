#include <time.hpp>

Time::Time(int h, int m): hours(h), minutes(m) {};

int Time::toMinutes() {
    return hours * 60 + minutes;
};

bool Time::operator>=(Time& other) {
    return toMinutes() >= other.toMinutes();
}

bool Time::operator<(Time& other) {
    return toMinutes() < other.toMinutes();
}

Time Time::operator-(Time& other) {
    int totalMinutes = toMinutes() - other.toMinutes();
    if (totalMinutes < 0) throw invalid_argument("second is larger");
    int h = totalMinutes / 60;
    int m = totalMinutes % 60;
    return Time(h, m);
}

Time& Time::operator+=(Time& other) {
    minutes += other.minutes;
    hours += other.hours + minutes / 60;
    minutes %= 60;
    return *this;
}

ostream& operator<<(ostream& os, Time time) {
    string h, m;
    h += time.hours / 10 + '0';
    h += time.hours % 10 + '0';
    m += time.minutes / 10 + '0';
    m += time.minutes % 10 + '0';
    os << h << ':' << m;
    return os;
}
