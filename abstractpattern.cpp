#include <iostream>
#include <memory>

// Абстрактные продукты
class AbstractProductA {
public:
    virtual void display() const = 0;
    virtual ~AbstractProductA() {}
};

class AbstractProductB {
public:
    virtual void show() const = 0;
    virtual ~AbstractProductB() {}
};

// Конкретные продукты для семейства A
class ProductA1 : public AbstractProductA {
public:
    void display() const override {
        std::cout << "Product A1\n";
    }
};

class ProductA2 : public AbstractProductA {
public:
    void display() const override {
        std::cout << "Product A2\n";
    }
};

// Конкретные продукты для семейства B
class ProductB1 : public AbstractProductB {
public:
    void show() const override {
        std::cout << "Product B1\n";
    }
};

class ProductB2 : public AbstractProductB {
public:
    void show() const override {
        std::cout << "Product B2\n";
    }
};

// Абстрактная фабрика
class AbstractFactory {
public:
    virtual std::unique_ptr<AbstractProductA> createProductA() const = 0;
    virtual std::unique_ptr<AbstractProductB> createProductB() const = 0;
    virtual ~AbstractFactory() {}
};

// Конкретные фабрики
class ConcreteFactory1 : public AbstractFactory {
public:
    std::unique_ptr<AbstractProductA> createProductA() const override {
        return std::make_unique<ProductA1>();
    }

    std::unique_ptr<AbstractProductB> createProductB() const override {
        return std::make_unique<ProductB1>();
    }
};

class ConcreteFactory2 : public AbstractFactory {
public:
    std::unique_ptr<AbstractProductA> createProductA() const override {
        return std::make_unique<ProductA2>();
    }

    std::unique_ptr<AbstractProductB> createProductB() const override {
        return std::make_unique<ProductB2>();
    }
};

// Клиентский код
void clientCode(const AbstractFactory& factory) {
    std::unique_ptr<AbstractProductA> productA = factory.createProductA();
    std::unique_ptr<AbstractProductB> productB = factory.createProductB();

    productA->display();
    productB->show();
}

int main() {
    // Использование паттерна "Абстрактная фабрика"
    ConcreteFactory1 factory1;
    clientCode(factory1);

    ConcreteFactory2 factory2;
    clientCode(factory2);

    return 0;
}
