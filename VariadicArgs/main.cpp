#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <QQmlContext>

#include "CallerClass.h"

/*!
 * \brief The DataBlock class
 * \details a flexible DataBlock which is used for dynamic adding directly into the SimpleClass.addToBuffer(...);
 */
struct DataBlock
{
    /** Note that this DataBlock only takes `float` type because the addToBuffer method takes only float args.
        Also remember the DataBlock members should be in range of 2~10, (also see addToBuffer to understand) **/

    float a0, a1; // Add more or remove "aX"
};

int main(int argc, char* argv[])
{
    qputenv("QT_ASSUME_STDERR_HAS_CONSOLE", "1");

    SimpleClass foo;
    DataBlock db{};

    CallerClass caller;

    auto result = caller.callAdd(foo, db);
    qDebug() << "Caller Return: " << result;

    return 0;

}
