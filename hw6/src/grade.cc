// Copyright 2022 Luke Howe
//

namespace csce240 {
namespace hw6 {

template <class T>
Grade<T>::Grade(T score) : score_(score) {
    // empty
}

template <class T>
const std::string Grade<T>::ToLetter() {
    double this_scored = score_.num();
    double this_total = score_.den();
    double val = this_scored / this_total * 100;
    // double val = this_scored;
    if (val >= 90.0)
        return "A";
    if (val >= 80.0)
        return "B";
    if (val >= 70.0)
        return "C";
    if (val >= 60.0)
        return "D";
    else
        return "F";
}

template <class T>
const std::string Grade<T>::ToLetter(unsigned int thresh) {
    double newThresh = thresh / 10;
    double this_scored = score_.num() / 1.0;
    double this_total = score_.den() / 1.0;
    double val = this_scored / this_total * 100;
    // double val = this_scored;
    if (val >= 90.0 + newThresh)
        return "A+";
    if (val >= 90.0)
        return "A";
    if (val >= 80.0 + newThresh)
        return "B+";
    if (val >= 80.0)
        return "B";
    if (val >= 70.0 + newThresh)
        return "C+";
    if (val >= 70.0)
        return "C";
    if (val >= 60.0 + newThresh)
        return "D+";
    if (val >= 60.0)
        return "D";
    else
        return "F";
}


}  // namespace hw6
}  // namespace csce240
