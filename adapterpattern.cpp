#include <iostream>
#include <memory>

// Существующий класс с неподходящим интерфейсом
class Adaptee {
public:
    void specificRequest() const {
        std::cout << "Specific Request\n";
    }
};

// Целевой интерфейс, который ожидается клиентом
class Target {
public:
    virtual void request() const = 0;
    virtual ~Target() {}
};

// Адаптер, который преобразует интерфейс Adaptee в Target
class Adapter : public Target {
public:
    Adapter(std::unique_ptr<Adaptee> adaptee) : adaptee_(std::move(adaptee)) {}

    void request() const override {
        adaptee_->specificRequest();
    }

private:
    std::unique_ptr<Adaptee> adaptee_;
};

int main() {
    // Использование адаптера
    std::unique_ptr<Adaptee> adaptee = std::make_unique<Adaptee>();
    std::unique_ptr<Target> adapter = std::make_unique<Adapter>(std::move(adaptee));
    adapter->request();

    return 0;
}
