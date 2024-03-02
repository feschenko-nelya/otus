#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <memory>

class GWindow;

/**
 * Главное окно программы.
*/

class MainWidow
{
public:
    MainWidow();
    ~MainWidow();

    void openFile() const;
    void saveFile() const;
    void printFile() const;
    void exportFile() const;
    void importFile() const;
    void removeFile() const;
    void closeFile() const;
    void close() const;

private:
    std::unique_ptr<GWindow *> _gWindow;

};

#endif // MAINWINDOW_H
