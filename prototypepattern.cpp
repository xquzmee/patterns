#include <iostream>
#include <unordered_map>

// Абстрактный прототип
class Prototype {
public:
    virtual Prototype* clone() const = 0;
    virtual void display() const = 0;
    virtual ~Prototype() {}
};

// Конкретный прототип
class ConcretePrototype : public Prototype {
public:
    ConcretePrototype(int data) : data_(data) {}

    Prototype* clone() const override {
        return new ConcretePrototype(*this);
    }

    void display() const override {
        std::cout << "ConcretePrototype: " << data_ << "\n";
    }

private:
    int data_;
};

// Прототипный менеджер
class PrototypeManager {
public:
    void registerPrototype(int key, Prototype* prototype) {
        prototypes_[key] = prototype;
    }

    Prototype* getPrototype(int key) const {
        auto it = prototypes_.find(key);
        if (it != prototypes_.end()) {
            return it->second->clone();
        }
        return nullptr;
    }

    ~PrototypeManager() {
        for (auto& pair : prototypes_) {
            delete pair.second;
        }
    }

private:
    std::unordered_map<int, Prototype*> prototypes_;
};

int main() {
    // Использование паттерна "Прототип"
    PrototypeManager manager;

    // Регистрация прототипов
    manager.registerPrototype(1, new ConcretePrototype(10));
    manager.registerPrototype(2, new ConcretePrototype(20));

    // Создание новых объектов через клонирование
    Prototype* prototype1 = manager.getPrototype(1);
    Prototype* prototype2 = manager.getPrototype(2);

    // Вывод информации о клонированных объектах
    if (prototype1) {
        prototype1->display();
        delete prototype1;
    }

    if (prototype2) {
        prototype2->display();
        delete prototype2;
    }

    return 0;
}
