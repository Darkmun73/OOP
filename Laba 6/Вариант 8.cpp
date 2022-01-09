#include <iostream>
#include <cstring>
#include <string>
#include <vector>

struct sup_product;

/// <summary>
/// Класс "Поставщик"
/// </summary>
class Supplier
{
private:
    std::string _name;
    std::vector<sup_product> _products;
public:
    Supplier(std::string name = "", std::vector<sup_product> products = {}) : _name(name), _products(products) {}


    //Возвращает имя поставщика
    std::string get_name()
    {
        return _name;
    }

    //Возвращает товары (и их количество) продаваемые у поставщика
    std::vector<sup_product> get_products()
    {
        return _products;
    }

    //Устанавливает имя поставщика
    void set_name(std::string name)
    {
        _name = name;
    }

    //Устанавливает товары (и их количество) продаваемые у поставщика
    void set_products(std::vector<sup_product> products)
    {
        _products = products;
    }
};

/// <summary>
/// Класс "Товар"
/// </summary>
class Product
{
private:
    std::string _name;
    double _price;

public:
    Product(std::string name = "", double price = 0) : _name(name), _price(price) {}
    //Конструктор копирования
    Product(const Product& prd)
    {
        this->_name = prd._name;
        this->_price = prd._price;
    }

    //Перегрузка оператора сравнения ==
    bool operator==(const Product& prd)
    {
        return ((prd._name == _name) && (prd._price == _price));
    }
    //Перегрузка оператора присваивания =
    Product& operator=(const Product& prd)
    {
        this->_name = prd._name;
        this->_price = prd._price;
        return *this;
    }

    //Возвращает название товара
    std::string get_name()
    {
        return _name;
    }

    //Возвращает цену товара
    double get_price()
    {
        return _price;
    }

    //Устанавливает название товара
    void set_name(std::string name)
    {
        _name = name;
    }

    //Устанавливает цену товара
    void set_price(double price)
    {
        price = _price;
    }
};

/// <summary>
/// Структура содержащая товар и его количество у поставщика
/// </summary>
struct sup_product
{
    Product _prd;
    std::size_t _amount;
};

/// <summary>
/// Класс "Покупатель"
/// </summary>
class Customer
{
private:
    std::string _name;
    int _cash_amount;
public:
    Customer(std::string name = "", int cash_amount = 0) : _name(name), _cash_amount(cash_amount) {}

    //Возвращает имя покупателя
    std::string get_name()
    {
        return _name;
    }

    //Возвращает количество денег покупателя
    int get_cash_amount()
    {
        return _cash_amount;
    }

    //Устанавливает имя покупателя
    void set_name(std::string name)
    {
        _name = name;
    }

    //Устанавливает количество денег покупателя
    void set_cash_amount(int cash_amount)
    {
        _cash_amount = cash_amount;
    }

    //Покупка товара prd у поставщика sup в количестве amount штук
    void buy(Supplier &sup, Product prd, std::size_t amount)
    {
        std::size_t a = 0;
        double p = 0;
        std::size_t size = sup.get_products().size();
        //проверяем есть ли у поставщика данный товар
        for (std::size_t i = 0; i < size; i++)
        {
            if (sup.get_products()[i]._prd == prd)
            {
                a = sup.get_products()[i]._amount;
                p = sup.get_products()[i]._prd.get_price();

                //проверяем превышает ли количество покупаемого товара то число товара, которое во владении у поставщика
                if (amount > a)
                {
                    std::cout << "Данный поставщик не распологает таким количеством заданного товара.\n";
                    return;
                }
                //проверяем хватит ли покупателю денег для покупки
                if (_cash_amount < (a * p))
                {
                    std::cout << "Количества денег недостаточно для покупки.";
                    return;
                }

                _cash_amount = _cash_amount - (amount * p);
                std::vector<sup_product> sp = sup.get_products();
                sp[i]._amount = sp[i]._amount - amount;
                sup.set_products(sp);
                std::cout << "Операция покупки завершена успешно";
                break;
            }
        }
        if ((a == 0) || (p == 0))
        {
            std::cout << "Запрашиваемый товар не найден или его нет в наличии.\n";
            return;
        }
    }
};



int main()
{
    setlocale(LC_ALL, "rus");
    Product LBaum("Духи L Baum", 300);
    Product Mcuri("Духи MCuri", 500);
    Supplier DNA("ДНК Парфюме", { {LBaum, 15}, {Mcuri, 10} });
    Customer me("Matyunin Evgeny Yaroslavovich", 10000);
    me.buy(DNA, LBaum, 10);
}
