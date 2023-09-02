// Copyright (C) 2023 Pedro López-Cabanillas
// SPDX-License-Identifier: BSD-3-Clause

#include <QGraphicsBlurEffect>
#include <QPaintEvent>
#include <QPainter>

#include "overlay.h"

Overlay::Overlay(QWidget *parent)
    : QWidget{parent}
{
    setAttribute(Qt::WA_NoSystemBackground);
    setAttribute(Qt::WA_TranslucentBackground);
    m_blurEffect = new QGraphicsBlurEffect(this);
    m_blurEffect->setBlurRadius(3);
    m_blurEffect->setBlurHints(QGraphicsBlurEffect::PerformanceHint);
    if (parentWidget()) {
        parentWidget()->setGraphicsEffect(m_blurEffect);
        resize(parentWidget()->geometry().size());
        raise();
        show();
    }
}

Overlay::~Overlay()
{
    if (parentWidget()) {
        parentWidget()->setGraphicsEffect(nullptr);
    }
}

void Overlay::paintEvent(QPaintEvent *event)
{
    QPainter p{this};
    p.fillRect(rect(), m_darkBrush);
}
