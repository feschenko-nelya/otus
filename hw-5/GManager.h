#ifndef GMANAGER_H
#define GMANAGER_H

#include <string>
class GModel;

/**
 * Менеджер загрузки и выгрузки графических элементов в/из памяти (на текущий момент это файл).
*/

class GManager
{
public:
    GManager(GModel *model, const std::string &filename);
    ~GManager();

    bool load();
    bool save();

private:
    GModel *_model = nullptr;
    const std::string &_filename;

};

#endif // GMANAGER_H
