// Copyright (C) 2023 Pedro López-Cabanillas
// SPDX-License-Identifier: BSD-3-Clause

#ifndef OVERLAY_H
#define OVERLAY_H

#include <QBrush>
#include <QWidget>

class QGraphicsBlurEffect;
class QPaintEvent;

class Overlay : public QWidget
{
    Q_OBJECT

public:
    explicit Overlay(QWidget *parent = nullptr);
    ~Overlay() override;

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QGraphicsBlurEffect *m_blurEffect{nullptr};
    QBrush m_darkBrush{{100, 100, 100, 128}}; // semitransparent gray
};

#endif // OVERLAY_H
