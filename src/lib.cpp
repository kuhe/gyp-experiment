
#include <string>

using std::string;

string stringIdentity(string s) {
    return s;
}

double numberIdentity(double n) {
    return n;
}

const char* hmm() {
    string hmm = "hmm";
    return hmm.c_str();
}

string appendString(string in) {
    return in + " etc.";
}