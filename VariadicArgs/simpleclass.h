#ifndef SIMPLECLASS_H
#define SIMPLECLASS_H

#include <QObject>
#include <QDebug>

/*!
 * \brief The SimpleClass class
 * \details For example you have a class which has a too many overloaded functions with same argument type but
 * with different argument counts.
 *
 * Example:
 *
 * func(float a0, float a1) {}
 * func(float a0, float a1, float a2) {}
 * func(float a0, float a1, float a2, float a3) {}
 * func(float a0, float a1, float a2, float a3, float a4) {}
 * func(float a0, float a1, float a2, float a3, float a4, float a5) {}
 * ...
 * func(float a0, float a1, float a2, ..., float a11) {}
 *
 *
 * The structure management with MyStruct { float a0, a1 } or MyStruct {float a0, a1, a2 } or ...
 * is too complicated and isn't flexidble.
 *
 *
 * So we need something to pass our struct with user defined size something like python func(*args, **kwargs)
 *
 * This will help us to have a dynamic function calling with dynamic argument passing which called
 * (Expression fold or Variadic arguments)
 *
 */
class SimpleClass : public QObject
{
        Q_OBJECT
    public:
        explicit SimpleClass(QObject* parent = nullptr);

        /*
         *  Note that the addToBuffer method is not for add something to any buffer
         *  in this example. (Just a name)
         *
         */


        inline bool addToBuffer(float a0, float a1)
        {
            // Simple function details to see which method is called
            qDebug() << __PRETTY_FUNCTION__;
            return true;

        }
        inline bool addToBuffer(float a0, float a1, float a2)
        {
            // Simple function details to see which method is called
            qDebug() << __PRETTY_FUNCTION__;
            return true;

        }
        inline bool addToBuffer(float a0, float a1, float a2, float a3)
        {
            // Simple function details to see which method is called
            qDebug() << __PRETTY_FUNCTION__;
            return true;

        }
        inline bool addToBuffer(float a0, float a1, float a2, float a3, float a4)
        {
            // Simple function details to see which method is called
            qDebug() << __PRETTY_FUNCTION__;
            return true;

        }
        inline bool addToBuffer(float a0, float a1, float a2, float a3, float a4, float a5)
        {
            // Simple function details to see which method is called
            qDebug() << __PRETTY_FUNCTION__;
            return true;

        }
        inline bool addToBuffer(float a0, float a1, float a2, float a3, float a4, float a5, float a6)
        {
            // Simple function details to see which method is called
            qDebug() << __PRETTY_FUNCTION__;

            return true;
        }
        inline bool addToBuffer(float a0, float a1, float a2, float a3, float a4, float a5, float a6, float a7)
        {
            // Simple function details to see which method is called
            qDebug() << __PRETTY_FUNCTION__;

            return true;
        }
        inline bool addToBuffer(float a0, float a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8)
        {
            // Simple function details to see which method is called
            qDebug() << __PRETTY_FUNCTION__;
            return true;

        }
        inline bool addToBuffer(float a0, float a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9)
        {
            // Simple function details to see which method is called
            qDebug() << __PRETTY_FUNCTION__;
            return true;

        }

    signals:
};

#endif // SIMPLECLASS_H
