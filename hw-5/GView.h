#ifndef GVIEW_H
#define GVIEW_H

class GDescriptor;
class GModel;

/**
 * Вывод графических элементов на устройстве вывода
*/

class GView
{
public:
    GView(GDescriptor *descriptor);
    ~GView();

    void setModel(GModel *model);
    void refresh();
    void undo();
    void redo();

private:
    GDescriptor *_descriptor = nullptr;
    GModel *_model = nullptr;

    void paint();
};

#endif // GVIEW_H
