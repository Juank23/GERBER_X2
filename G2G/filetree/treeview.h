#pragma once

#include "filemodel.h"
#include <QTreeView>

class TreeView : public QTreeView {
    Q_OBJECT
    friend class MainWindow;

public:
    explicit TreeView(QWidget* parent = nullptr);
    ~TreeView() override = default;
    void hideOther();
    void closeFile();
    void closeFile2(const QModelIndex& index);
    void saveGcodeFile();

private:
    void updateTree();
    void updateIcons();
    FileModel* const m_model;

    void on_doubleClicked(const QModelIndex& index);
    void onSelectionChanged(const QItemSelection& selected, const QItemSelection& deselected);

    QModelIndex m_menuIndex;
    void showExcellonDialog();

protected:
    void contextMenuEvent(QContextMenuEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseDoubleClickEvent(QMouseEvent* event) override;
};
