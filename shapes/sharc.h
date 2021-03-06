#pragma once

#include "shape.h"

namespace Shapes {
class Arc final : public Shape {
public:
    explicit Arc(QPointF center, QPointF pt, QPointF pt2);
    explicit Arc() { }
    ~Arc();

    // QGraphicsItem interface
    int type() const override { return GiShapeA; }
    void redraw() override;
    // Shape interface
    QString name() const override;
    QIcon icon() const override;

    void setPt(const QPointF& pt);
    void setPt2(const QPointF& pt);
    double radius() const;
    void setRadius(double radius);

    enum {
        Center,
        Point1,
        Point2,
    };

private:
    mutable double m_radius;

protected:
    // Shape interface
    void write(QDataStream& /*stream*/) const override { }
    void read(QDataStream& /*stream*/) override { }
    QPointF calcPos(Handler* sh) override;
};
}
