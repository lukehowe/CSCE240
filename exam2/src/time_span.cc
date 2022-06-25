// Copyright 2022 Luke Howe
//
#include <exam2/inc/time_span.h>
#include <iostream>

// default constructor
TimeSpan::TimeSpan() : hours_(0), minutes_(0), seconds_(0) {
    // empty
}

// initialization constructor
TimeSpan::TimeSpan(int hours, int minutes, int seconds) :
                    hours_(hours), minutes_(minutes), seconds_(seconds) {
    // empty
                    }

const TimeSpan TimeSpan::Add(const TimeSpan& that) const {
    int this_hours = hours_;
    int this_minutes = minutes_;
    int this_seconds = seconds_;
    this_seconds += that.seconds();
    if (this_seconds >= 60) {
        ++this_minutes;
        this_seconds -= 60;
    }
    this_minutes += that.minutes();
    if (this_minutes >= 60) {
        ++this_hours;
        this_minutes -= 60;
    }
    this_hours += that.hours();
    return TimeSpan(this_hours, this_minutes, this_seconds);
}

const TimeSpan TimeSpan::operator+(const TimeSpan& rhs) const {
    return Add(rhs);
}

const TimeSpan TimeSpan::operator+(int rhs) const {
    int total_seconds = rhs;
    int this_hours = total_seconds / 3600;
    total_seconds = total_seconds - (this_hours*3600);
    int this_minutes = total_seconds / 60;
    total_seconds = total_seconds - (this_minutes*60);
    int this_seconds = total_seconds;
    return Add(TimeSpan(this_hours, this_minutes, this_seconds));
}

const TimeSpan operator+(int lhs, const TimeSpan& rhs) {
    int total_seconds = lhs;
    int this_hours = total_seconds / 3600;
    total_seconds = total_seconds - (this_hours*3600);
    int this_minutes = total_seconds / 60;
    total_seconds = total_seconds - (this_minutes*60);
    int this_seconds = total_seconds;
    TimeSpan temp(this_hours, this_minutes, this_seconds);
    return temp + rhs;
}


std::istream& TimeSpan::Insert(std::istream* lhs) {
    char colon;
    *lhs >> hours_ >> colon >> minutes_ >> colon >> seconds_;
    return *lhs;
}

std::istream& operator>>(std::istream& lhs, TimeSpan& rhs) {
    return rhs.Insert(&lhs);
}

std::ostream& operator<<(std::ostream& lhs, const TimeSpan& rhs) {
    lhs << rhs.hours() << " : " << rhs.minutes() << " : " << rhs.seconds();
    return lhs;
}
