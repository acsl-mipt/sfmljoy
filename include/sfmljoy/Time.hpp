////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2018 Laurent Gomila (laurent@sfml-dev.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#ifndef SFMLJOY_TIME_HPP
#define SFMLJOY_TIME_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <sfmljoy/Config.hpp>


namespace sfmljoy
{
////////////////////////////////////////////////////////////
/// \brief Represents a time value
///
////////////////////////////////////////////////////////////
class Time
{
public:

    ////////////////////////////////////////////////////////////
    /// \brief Default constructor
    ///
    /// Sets the time value to zero.
    ///
    ////////////////////////////////////////////////////////////
    Time();

    ////////////////////////////////////////////////////////////
    /// \brief Return the time value as a number of seconds
    ///
    /// \return Time in seconds
    ///
    /// \see asMilliseconds, asMicroseconds
    ///
    ////////////////////////////////////////////////////////////
    float asSeconds() const;

    ////////////////////////////////////////////////////////////
    /// \brief Return the time value as a number of milliseconds
    ///
    /// \return Time in milliseconds
    ///
    /// \see asSeconds, asMicroseconds
    ///
    ////////////////////////////////////////////////////////////
    Int32 asMilliseconds() const;

    ////////////////////////////////////////////////////////////
    /// \brief Return the time value as a number of microseconds
    ///
    /// \return Time in microseconds
    ///
    /// \see asSeconds, asMilliseconds
    ///
    ////////////////////////////////////////////////////////////
    Int64 asMicroseconds() const;

    ////////////////////////////////////////////////////////////
    // Static member data
    ////////////////////////////////////////////////////////////
    static const Time Zero; ///< Predefined "zero" time value

private:

    friend Time seconds(float);
    friend Time milliseconds(Int32);
    friend Time microseconds(Int64);

    ////////////////////////////////////////////////////////////
    /// \brief Construct from a number of microseconds
    ///
    /// This function is internal. To construct time values,
    /// use sfmljoy::seconds, sfmljoy::milliseconds or sfmljoy::microseconds instead.
    ///
    /// \param microseconds Number of microseconds
    ///
    ////////////////////////////////////////////////////////////
    explicit Time(Int64 microseconds);

private:

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    Int64 m_microseconds; ///< Time value stored as microseconds
};

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Construct a time value from a number of seconds
///
/// \param amount Number of seconds
///
/// \return Time value constructed from the amount of seconds
///
/// \see milliseconds, microseconds
///
////////////////////////////////////////////////////////////
Time seconds(float amount);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Construct a time value from a number of milliseconds
///
/// \param amount Number of milliseconds
///
/// \return Time value constructed from the amount of milliseconds
///
/// \see seconds, microseconds
///
////////////////////////////////////////////////////////////
Time milliseconds(Int32 amount);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Construct a time value from a number of microseconds
///
/// \param amount Number of microseconds
///
/// \return Time value constructed from the amount of microseconds
///
/// \see seconds, milliseconds
///
////////////////////////////////////////////////////////////
Time microseconds(Int64 amount);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of == operator to compare two time values
///
/// \param left  Left operand (a time)
/// \param right Right operand (a time)
///
/// \return True if both time values are equal
///
////////////////////////////////////////////////////////////
bool operator ==(Time left, Time right);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of != operator to compare two time values
///
/// \param left  Left operand (a time)
/// \param right Right operand (a time)
///
/// \return True if both time values are different
///
////////////////////////////////////////////////////////////
bool operator !=(Time left, Time right);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of < operator to compare two time values
///
/// \param left  Left operand (a time)
/// \param right Right operand (a time)
///
/// \return True if \a left is lesser than \a right
///
////////////////////////////////////////////////////////////
bool operator <(Time left, Time right);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of > operator to compare two time values
///
/// \param left  Left operand (a time)
/// \param right Right operand (a time)
///
/// \return True if \a left is greater than \a right
///
////////////////////////////////////////////////////////////
bool operator >(Time left, Time right);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of <= operator to compare two time values
///
/// \param left  Left operand (a time)
/// \param right Right operand (a time)
///
/// \return True if \a left is lesser or equal than \a right
///
////////////////////////////////////////////////////////////
bool operator <=(Time left, Time right);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of >= operator to compare two time values
///
/// \param left  Left operand (a time)
/// \param right Right operand (a time)
///
/// \return True if \a left is greater or equal than \a right
///
////////////////////////////////////////////////////////////
bool operator >=(Time left, Time right);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of unary - operator to negate a time value
///
/// \param right Right operand (a time)
///
/// \return Opposite of the time value
///
////////////////////////////////////////////////////////////
Time operator -(Time right);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of binary + operator to add two time values
///
/// \param left  Left operand (a time)
/// \param right Right operand (a time)
///
/// \return Sum of the two times values
///
////////////////////////////////////////////////////////////
Time operator +(Time left, Time right);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of binary += operator to add/assign two time values
///
/// \param left  Left operand (a time)
/// \param right Right operand (a time)
///
/// \return Sum of the two times values
///
////////////////////////////////////////////////////////////
Time& operator +=(Time& left, Time right);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of binary - operator to subtract two time values
///
/// \param left  Left operand (a time)
/// \param right Right operand (a time)
///
/// \return Difference of the two times values
///
////////////////////////////////////////////////////////////
Time operator -(Time left, Time right);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of binary -= operator to subtract/assign two time values
///
/// \param left  Left operand (a time)
/// \param right Right operand (a time)
///
/// \return Difference of the two times values
///
////////////////////////////////////////////////////////////
Time& operator -=(Time& left, Time right);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of binary * operator to scale a time value
///
/// \param left  Left operand (a time)
/// \param right Right operand (a number)
///
/// \return \a left multiplied by \a right
///
////////////////////////////////////////////////////////////
Time operator *(Time left, float right);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of binary * operator to scale a time value
///
/// \param left  Left operand (a time)
/// \param right Right operand (a number)
///
/// \return \a left multiplied by \a right
///
////////////////////////////////////////////////////////////
Time operator *(Time left, Int64 right);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of binary * operator to scale a time value
///
/// \param left  Left operand (a number)
/// \param right Right operand (a time)
///
/// \return \a left multiplied by \a right
///
////////////////////////////////////////////////////////////
Time operator *(float left, Time right);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of binary * operator to scale a time value
///
/// \param left  Left operand (a number)
/// \param right Right operand (a time)
///
/// \return \a left multiplied by \a right
///
////////////////////////////////////////////////////////////
Time operator *(Int64 left, Time right);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of binary *= operator to scale/assign a time value
///
/// \param left  Left operand (a time)
/// \param right Right operand (a number)
///
/// \return \a left multiplied by \a right
///
////////////////////////////////////////////////////////////
Time& operator *=(Time& left, float right);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of binary *= operator to scale/assign a time value
///
/// \param left  Left operand (a time)
/// \param right Right operand (a number)
///
/// \return \a left multiplied by \a right
///
////////////////////////////////////////////////////////////
Time& operator *=(Time& left, Int64 right);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of binary / operator to scale a time value
///
/// \param left  Left operand (a time)
/// \param right Right operand (a number)
///
/// \return \a left divided by \a right
///
////////////////////////////////////////////////////////////
Time operator /(Time left, float right);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of binary / operator to scale a time value
///
/// \param left  Left operand (a time)
/// \param right Right operand (a number)
///
/// \return \a left divided by \a right
///
////////////////////////////////////////////////////////////
Time operator /(Time left, Int64 right);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of binary /= operator to scale/assign a time value
///
/// \param left  Left operand (a time)
/// \param right Right operand (a number)
///
/// \return \a left divided by \a right
///
////////////////////////////////////////////////////////////
Time& operator /=(Time& left, float right);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of binary /= operator to scale/assign a time value
///
/// \param left  Left operand (a time)
/// \param right Right operand (a number)
///
/// \return \a left divided by \a right
///
////////////////////////////////////////////////////////////
Time& operator /=(Time& left, Int64 right);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of binary / operator to compute the ratio of two time values
///
/// \param left  Left operand (a time)
/// \param right Right operand (a time)
///
/// \return \a left divided by \a right
///
////////////////////////////////////////////////////////////
float operator /(Time left, Time right);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of binary % operator to compute remainder of a time value
///
/// \param left  Left operand (a time)
/// \param right Right operand (a time)
///
/// \return \a left modulo \a right
///
////////////////////////////////////////////////////////////
Time operator %(Time left, Time right);

////////////////////////////////////////////////////////////
/// \relates Time
/// \brief Overload of binary %= operator to compute/assign remainder of a time value
///
/// \param left  Left operand (a time)
/// \param right Right operand (a time)
///
/// \return \a left modulo \a right
///
////////////////////////////////////////////////////////////
Time& operator %=(Time& left, Time right);

} // namespace sfmljoy


#endif // SFMLJOY_TIME_HPP


////////////////////////////////////////////////////////////
/// \class sfmljoy::Time
/// \ingroup system
///
/// sfmljoy::Time encapsulates a time value in a flexible way.
/// It allows to define a time value either as a number of
/// seconds, milliseconds or microseconds. It also works the
/// other way round: you can read a time value as either
/// a number of seconds, milliseconds or microseconds.
///
/// By using such a flexible interface, the API doesn't
/// impose any fixed type or resolution for time values,
/// and let the user choose its own favorite representation.
///
/// Time values support the usual mathematical operations:
/// you can add or subtract two times, multiply or divide
/// a time by a number, compare two times, etc.
///
/// Since they represent a time span and not an absolute time
/// value, times can also be negative.
///
/// Usage example:
/// \code
/// sfmljoy::Time t1 = sfmljoy::seconds(0.1f);
/// Int32 milli = t1.asMilliseconds(); // 100
///
/// sfmljoy::Time t2 = sfmljoy::milliseconds(30);
/// Int64 micro = t2.asMicroseconds(); // 30000
///
/// sfmljoy::Time t3 = sfmljoy::microseconds(-800000);
/// float sec = t3.asSeconds(); // -0.8
/// \endcode
///
/// \code
/// void update(sfmljoy::Time elapsed)
/// {
///    position += speed * elapsed.asSeconds();
/// }
///
/// update(sfmljoy::milliseconds(100));
/// \endcode
///
/// \see sfmljoy::Clock
///
////////////////////////////////////////////////////////////