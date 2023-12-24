#include <iostream>
#include <string>

// Класс, который мы строим
class Product {
public:
    void setPartA(const std::string& partA) {
        partA_ = partA;
    }

    void setPartB(const std::string& partB) {
        partB_ = partB;
    }

    void setPartC(const std::string& partC) {
        partC_ = partC;
    }

    void show() const {
        std::cout << "Product Parts: " << partA_ << ", " << partB_ << ", " << partC_ << "\n";
    }

private:
    std::string partA_;
    std::string partB_;
    std::string partC_;
};

// Интерфейс Строителя
class Builder {
public:
    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual void buildPartC() = 0;
    virtual Product getResult() const = 0;
    virtual ~Builder() {}
};

// Конкретный строитель
class ConcreteBuilder : public Builder {
public:
    void buildPartA() override {
        product_.setPartA("Part A");
    }

    void buildPartB() override {
        product_.setPartB("Part B");
    }

    void buildPartC() override {
        product_.setPartC("Part C");
    }

    Product getResult() const override {
        return product_;
    }

private:
    Product product_;
};

// Директор, который управляет процессом построения
class Director {
public:
    Director(std::unique_ptr<Builder> builder) : builder_(std::move(builder)) {}

    void construct() {
        builder_->buildPartA();
        builder_->buildPartB();
        builder_->buildPartC();
    }

    Product getResult() const {
        return builder_->getResult();
    }

private:
    std::unique_ptr<Builder> builder_;
};

int main() {
    // Использование паттерна "Строитель"
    std::unique_ptr<Builder> builder = std::make_unique<ConcreteBuilder>();
    Director director(std::move(builder));

    director.construct();
    Product product = director.getResult();
    product.show();

    return 0;
}
