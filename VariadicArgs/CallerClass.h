#ifndef CALLERCLASS_H
#define CALLERCLASS_H

#include "simpleclass.h"

#include <span>
#include <math.h>

/**
   Please see SimpleClass description
**/


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

class CallerClass : public QObject
{
        Q_OBJECT
    public :
        explicit CallerClass(QObject* parent = nullptr) : QObject{parent} {}

        template <typename T>
        inline auto callAdd(SimpleClass& foo, T& strct)
        {
            auto s = toSpan(strct);
            return callAddImpl(foo, s, std::make_index_sequence < sizeof(T) / sizeof(float) > {});
        }

    protected:


        template <std::size_t ...I>
        inline auto callAddImpl(SimpleClass& foo, std::span<float> sp, std::index_sequence<I...>)
        {
            return foo.addToBuffer(sp[I]...);
        }

        template <typename T>
        inline std::span<float> toSpan(T& strct) const
        {
            return std::span<float>(reinterpret_cast<float*>(&strct),
                                    sizeof(T) / sizeof(float));
        }






};


#endif // CALLERCLASS_H
