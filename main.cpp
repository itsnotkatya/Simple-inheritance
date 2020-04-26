#include <iostream>
using namespace std;

enum SEX {M, F};
class Human {
protected:
     SEX sex;
     int age;
    public:

    Human(int age, SEX sex) {
        this -> age = age;
        this -> sex = sex;
    }

    int getAge() {return age;};
    void setAge(int Age) {this -> age = Age;};

     int getSex() {return sex;};
    void setSex(SEX _sex) {this -> sex = _sex;};

};


class Student: public Human {
protected:
    static std::string RecordBook;
public:
    Student(int age, SEX sex, const std::string &recordBook) : Human(age, sex) {
        Student :: RecordBook = recordBook;
    };
    const std::string &getRecordBook (const std::string &recordBook) { //передаем по сслке чтобы экономить память и не вызывать копирвание
        return recordBook;
    };
    void setRecordBook (const std::string &recordBook) {
        Student :: RecordBook = recordBook;
    }
};

class Specialist : public Human {
protected:
    int Knowledge;
    int Prosvetlenie;
public:
    Specialist (int age, SEX sex, int knowledge, int prosvetlenie) : Human(age, sex) {
        this -> Knowledge = knowledge;
        this -> Prosvetlenie = prosvetlenie;
    };
    int getKnowledge() {return Knowledge;};
    void setKnowledge(int knowledge) {this -> Knowledge = knowledge;};

    int getProsvetlenie() {return Prosvetlenie;};
    void setProsvetlenie(int prosvetlenie) {this -> Prosvetlenie = prosvetlenie;};
};

class GoodStudent :  public Student {
protected:
    int Raiting;
    int Comission;
public:
    GoodStudent(int age, SEX sex, const std::string &Name, int raiting, int comission) : Student (age, sex, RecordBook) {
        this -> Raiting = raiting;
        this -> Comission = comission;
    };
    int getRaiting() {return Raiting;};
    void setRaiting(int raiting) {this -> Raiting = raiting;};

    int getComission() {return Comission;};
    void setComission(int comission) {this -> Comission = comission;};

};


class Proffesor : public  GoodStudent, Specialist {
protected:
    std::string Subject;
public:
    Proffesor (int age, SEX sex, const std::string &Name, int &raiting, int &comission, std::string &subject) : GoodStudent(age, sex, Name, raiting, comission), Specialist(age, sex, Knowledge, Prosvetlenie) {
        this -> Subject = subject;
    };
    const std::string &getSubject (const std::string &subject) {       //передаем по сслке чтобы экономить память и не вызывать копирвание
        return subject;
    };
    void setSubject (const std::string &subject) {
        this -> Subject = subject;
    }

};


int main() {

    //Proffesor Javier (45, M, "Bardem", 25, 0, "Biology");
    GoodStudent Paul (21,M,"Atreides",18, 5);
    GoodStudent Chani (19, F,"Kynes", 18,  4);


    Paul.setRaiting(4);
    cout << "Chani's raiting" << Paul.GoodStudent::getRaiting() << endl;
    Chani.setRaiting(2);
    Chani.setComission(10);
    Chani.getSex();
    Chani.setSex(M);
    Paul.getAge();
    Paul.setAge(20);
    Chani.getRaiting();
    


    if ((Chani.getRaiting() < 3) && (Chani.getComission() > 8)) {
        cout << "Student is expelled" << endl;
    }

    if ((Paul.getRaiting() > 4 ) && (Paul.getComission() > 0)) {
        cout << "Student " << endl;
    }
    return 0;
}