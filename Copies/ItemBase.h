#ifndef ITEMBASE_H
#define ITEMBASE_H

#include <QObject>
#include <QDebug>

class ItemBase : public QObject {
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId NOTIFY changed)
    Q_PROPERTY(int row READ row WRITE setRow NOTIFY changed)
public :
    int id() { return m_id; }
    void setId(int id) { m_id = id; emit changed(); }

    int row() { return m_row; }
    void setRow(int row) { m_row = row; emit changed(); }
signals:
    void changed();

private:
    int m_id, m_row;
};

#endif // ITEMBASE_H
