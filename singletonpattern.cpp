#include <iostream>

class Singleton {
public:
    // Получение единственного экземпляра класса
    static Singleton& getInstance() {
        static Singleton instance; // Создание единственного экземпляра
        return instance;
    }

    // Пример метода класса
    void showMessage() const {
        std::cout << "Hello, I am a Singleton!\n";
    }

    // Опционально запрещаем копирование и присваивание
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

private:
    // Приватный конструктор, чтобы предотвратить создание экземпляров извне
    Singleton() {}
};

int main() {
    // Использование Singleton
    Singleton& singletonInstance = Singleton::getInstance();
    singletonInstance.showMessage();

    // Попытка создания еще одного экземпляра
    // Singleton anotherInstance; // Это вызовет ошибку компиляции

    return 0;
}
