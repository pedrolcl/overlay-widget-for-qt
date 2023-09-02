// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QList>
#include <QMainWindow>
#include <QPair>

class QAction;
class QTabWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void createSample();

public slots:
    void openDialog();
    void printFile();

private:
    void createLetter(const QString &name,
                      const QString &address,
                      QList<QPair<QString, int> > orderItems,
                      bool sendOffers);

    QAction *printAction;
    QTabWidget *letters;
};
#endif // MAINWINDOW_H
