#include <iostream>

using namespace std;

class Observer {
public:
    virtual void update(const string& message) = 0;
};

class ConcreteObserver : public Observer {
    string name;
public:
    ConcreteObserver(const string& name) : name(name) {}

    void update(const string& message) override {
        cout << name << " received message: " << message << endl;
    }
};

class Subject {
    Observer* observer;
public:
    void addObserver(Observer* observer) {
        this->observer = observer;
    }

    void removeObserver(Observer* observer) {
        // Remove the observer (not implemented in this example)
    }

    void notifyObserver(const string& message) {
        observer->update(message);
    }
};

int main() {
    ConcreteObserver observer1("Observer 1");
    ConcreteObserver observer2("Observer 2");

    Subject subject;
    subject.addObserver(&observer1);
    subject.notifyObserver("Hello Observer 1!");

    subject.addObserver(&observer2);
    subject.notifyObserver("Hello Observer 2!");

    return 0;
}