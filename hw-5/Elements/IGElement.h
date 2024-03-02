#ifndef IGELEMENT_H
#define IGELEMENT_H

#include <string>

/**
 * Интерфейс графического элемента.
 * Основные функции: рисование, стирание, сериализация и десериализация
*/

class IGElement
{
public:
    IGElement();
    ~IGElement();

    virtual void paint();
    virtual void erase();
    virtual std::string serialize();
    virtual void unserialize(const std::string &data);
};

#endif // IGELEMENT_H
