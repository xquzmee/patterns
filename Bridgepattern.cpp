#include <iostream>
#include <memory>

// Интерфейс для реализации
class Implementor {
public:
    virtual void operationImpl() const = 0;
    virtual ~Implementor() {}
};

// Конкретная реализация
class ConcreteImplementorA : public Implementor {
public:
    void operationImpl() const override {
        std::cout << "Concrete Implementor A\n";
    }
};

class ConcreteImplementorB : public Implementor {
public:
    void operationImpl() const override {
        std::cout << "Concrete Implementor B\n";
    }
};

// Интерфейс для абстракции
class Abstraction {
public:
    virtual void operation() const = 0;
    virtual ~Abstraction() {}
};

// Расширенная абстракция
class RefinedAbstraction : public Abstraction {
public:
    RefinedAbstraction(std::unique_ptr<Implementor> implementor) : implementor_(std::move(implementor)) {}

    void operation() const override {
        implementor_->operationImpl();
    }

private:
    std::unique_ptr<Implementor> implementor_;
};

int main() {
    // Использование шаблона "Мост"
    std::unique_ptr<Implementor> implementorA = std::make_unique<ConcreteImplementorA>();
    std::unique_ptr<Abstraction> abstractionA = std::make_unique<RefinedAbstraction>(std::move(implementorA));
    abstractionA->operation();

    std::unique_ptr<Implementor> implementorB = std::make_unique<ConcreteImplementorB>();
    std::unique_ptr<Abstraction> abstractionB = std::make_unique<RefinedAbstraction>(std::move(implementorB));
    abstractionB->operation();

    return 0;
}
