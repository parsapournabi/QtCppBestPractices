#ifndef BASE_H
#define BASE_H

#include "ItemBase.h"
#include <windows.h>

template <typename T>
class Base : public QObject {
    static_assert(std::is_base_of_v<ItemBase, T>, "T must inherit from ItemBase class!");
public:

    Base(QObject *parent = nullptr) {
        qDebug() << "Base Constructor" << this;
    }

    int insertItem(T* itemObj, int key) {
        if (itemObj == nullptr)
            return -1;

        T *item = new T(*itemObj);
        m_items.append(item);

        item->setId(key);
        item->setRow(m_items.count() - 1);

        return m_items.constLast()->row();
    }

    int insertItems(QList<T> itemsObj) {
        qDebug() << "At Insert Item";
        for (auto &item : itemsObj) {
            item.setId(m_items.count());
            item.setRow(m_items.count());
            // qDebug() << "Item: " << item.value();
            insertItem(&item, m_items.count());
        }

        return m_items.count() - 1;
    }

    void clear() {
        for (int i = 0; i < m_items.count(); ++i) {
            delete m_items[i];
        }
        m_items.clear();
    }

    int count() const { return m_items.count(); }

    T *item(int index) {return m_items[index]; }

private:
    QVector<T *> m_items;
    // QHash<int, T*> m_mapItems;

};


#endif // BASE_H
