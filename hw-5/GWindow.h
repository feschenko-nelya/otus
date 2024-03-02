#ifndef GWINDOW_H
#define GWINDOW_H

#include "GManager.h"
#include "GView.h"

#include <memory>
#include <string>

class GDescriptor;

/**
 * Окно работы с графическими элементами.
*/

class GWindow final
{
public:
    enum class EditMode
    {
        Edit,
        ReadOnly
    };

    GWindow(EditMode mode, const std::string &filename);
    ~GWindow();

    bool open() const;
    void close() const;
    void save();

private:
    std::string _filename;
    GDescriptor *_descriptor = nullptr;
    std::unique_ptr<GManager> _manager;
    std::unique_ptr<GView> _view;
    std::unique_ptr<GModel> _model;

    void createElement();
    void removeElement();
};

#endif // GWINDOW_H
