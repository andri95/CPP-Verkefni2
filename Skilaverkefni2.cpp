#include <iostream>
#include <string>

using namespace std;

class Upplausn {
    private:
        int x;
        int y;
    
    public:
        Upplausn() : x(), y(){}

        Upplausn(int x, int y) {
            this -> x = x;
            this -> y = y;
        }

        int getX() const {
            return this -> x;
        }
        int getY() const {
            return this -> y;
        }
};

class Staerd {
    private:
        double lengd;
        double breidd;
        double haed;

    public:
        Staerd() : lengd(), breidd(), haed(){}

        Staerd(double lengd, double breidd, double haed) {
            this -> lengd = lengd;
            this -> breidd = breidd;
            this -> haed = haed;
        }

        double getLengd() const {
            return this -> lengd;
        }
        double getBreidd() const {
            return this -> breidd;
        }
        double getHaed() const {
            return this -> haed;
        }
};

class Skjavarpi {
    private:
        int birtustig;
        int skerpa;
        Upplausn upplausn;
        Staerd staerd;

    public:
        friend bool operator ==(const Skjavarpi& s1, const Skjavarpi& s2);
        friend bool operator !=(const Skjavarpi& s1, const Skjavarpi& s2);
        friend bool operator <(const Skjavarpi& s1, const Skjavarpi& s2);
        friend bool operator >(const Skjavarpi& s1, const Skjavarpi& s2);
        friend bool operator <=(const Skjavarpi& s1, const Skjavarpi& s2);
        friend bool operator >=(const Skjavarpi& s1, const Skjavarpi& s2);
        friend ostream& operator <<(ostream&, const Skjavarpi& s);

        Skjavarpi(int x, int y, int Birtustig, int Skerpa, double lengd, double breidd, double haed) {
            birtustig = Birtustig;
            skerpa = Skerpa;
            upplausn = Upplausn(x, y);
            staerd = Staerd(lengd, breidd, haed);
        }
    
    void prenta() {
        cout << this -> birtustig << " " << this -> skerpa << endl;
        cout << this -> upplausn.getX() << " " << this -> upplausn.getY() << endl;
        cout << this -> staerd.getLengd() << " " << this -> staerd.getBreidd() << " " << this -> staerd.getHaed() <<endl;
    }

    double reikna() const {
        return this -> upplausn.getX() * this -> upplausn.getY() * birtustig;
    }
};

bool operator ==(const Skjavarpi& s1, const Skjavarpi& s2) {
    return s1.reikna() == s2.reikna();
}
bool operator !=(const Skjavarpi& s1, const Skjavarpi& s2) {
    return s1.reikna() != s2.reikna();
}
bool operator <(const Skjavarpi& s1, const Skjavarpi& s2) {
    return s1.reikna() < s2.reikna();
}
bool operator >(const Skjavarpi& s1, const Skjavarpi& s2) {
    return s1.reikna() > s2.reikna();
}
bool operator <=(const Skjavarpi& s1, const Skjavarpi& s2) {
    return s1.reikna() <= s2.reikna();
}
bool operator >=(const Skjavarpi& s1, const Skjavarpi& s2) {
    return s1.reikna() >= s2.reikna();
}
ostream& operator <<(ostream& os, const Skjavarpi& s) {
    return os << "Upplausn " << s.upplausn.getX() << "x" << s.upplausn.getY()
    << ", Birtustig: " << s.birtustig << ", Skerpa: " << s.skerpa << ":1, "
    << "Lengd/Breidd/Hæð: " << s.staerd.getLengd() << "/" << s.staerd.getBreidd() << "/" << s.staerd.getHaed();
}

int main(){
    Skjavarpi s1 = Skjavarpi(1920, 1080, 5000, 1200, 30.53, 20.49, 15.99);
    Skjavarpi s2 = Skjavarpi(1280, 800, 5000, 1200, 30.53, 20.49, 15.99);

    cout << "Skjávarpi 1: " << s1 << endl;
    cout << "Skjávarpi 2: " << s2 << endl;

    // Eru þeir eins?
    if (s1 == s2) {
        cout << "Þeir eru eins" << endl;
    } else {
        cout << "Þeir eru mismunandi" << endl;
    }

    // Eru þeir mismunandi?
    if (s1 != s2) {
        cout << "Þeir eru mismunandi" << endl;
    } else {
        cout << "Þeir eru eins" << endl;
    }

    // Er s1 lélegri en s2?
    if (s1 < s2) {
        cout << "s1 er lélegri en s2" << endl;
    } else {
        cout << "s1 er ekki lélegri en s2" << endl;
    }

    // Er s1 betri en s2?
    if (s1 > s2) {
        cout << "s1 er betri en s2" << endl;
    } else {
        cout << "s1 er ekki betri en s2" << endl;
    }

    // Er s1 lélegri eða jafn góður og s2?
    if (s1 <= s2) {
        cout << "s1 er lélegri en - eða jafn góður og s2" << endl;
    } else {
        cout << "s1 er betri en - eða jafn góður og s2" << endl;
    }

    // er s1 betri eða jafn góður og s2
    if (s1 >= s2) {
        cout << "s1 er betri en - eða jafn góður og s2" << endl;
    } else {
        cout << "s1 er lélegri en - eða jafn góður og s2" << endl;
    }
};