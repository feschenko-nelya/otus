#ifndef GMODEL_H
#define GMODEL_H

#include <list>
class IGElement;

/**
 * Модель графических элементов - список элементов и функции для работы с ним.
*/

class GModel
{
public:
    GModel();
    ~GModel();

    void add(IGElement *);
    IGElement *get(int index);
    void remove(int index);
    int count() const;
    void clear();

private:
    std::list<IGElement *> _gElements;

};

#endif // GMODEL_H
