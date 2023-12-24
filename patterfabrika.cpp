#include <iostream>
#include <memory>

// Абстрактный базовый класс
class Product {
public:
    virtual void display() const = 0;
    virtual ~Product() {}
};

// Конкретные классы продуктов
class ConcreteProduct1 : public Product {
public:
    void display() const override {
        std::cout << "ConcreteProduct1\n";
    }
};

class ConcreteProduct2 : public Product {
public:
    void display() const override {
        std::cout << "ConcreteProduct2\n";
    }
};

// Абстрактный класс фабрики
class Creator {
public:
    virtual std::unique_ptr<Product> createProduct() const = 0;
    virtual ~Creator() {}
};

// Конкретные классы фабрик
class ConcreteCreator1 : public Creator {
public:
    std::unique_ptr<Product> createProduct() const override {
        return std::make_unique<ConcreteProduct1>();
    }
};

class ConcreteCreator2 : public Creator {
public:
    std::unique_ptr<Product> createProduct() const override {
        return std::make_unique<ConcreteProduct2>();
    }
};

int main() {
    // Использование фабрик
    std::unique_ptr<Creator> creator1 = std::make_unique<ConcreteCreator1>();
    std::unique_ptr<Product> product1 = creator1->createProduct();
    product1->display();

    std::unique_ptr<Creator> creator2 = std::make_unique<ConcreteCreator2>();
    std::unique_ptr<Product> product2 = creator2->createProduct();
    product2->display();

    return 0;
}
