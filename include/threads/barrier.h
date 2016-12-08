/*!
    \file barrier.h
    \brief Barrier synchronization primitive definition
    \author Ivan Shynkarenka
    \date 16.03.2016
    \copyright MIT License
*/

#ifndef CPPCOMMON_THREADS_BARRIER_H
#define CPPCOMMON_THREADS_BARRIER_H

#include <memory>

namespace CppCommon {

//! Barrier synchronization primitive
/*!
    A barrier for a group of threads in the source code means any thread must stop at this point
    and cannot proceed until all other threads reach this barrier.

    Thread-safe.

    https://en.wikipedia.org/wiki/Barrier_(computer_science)
*/
class Barrier
{
public:
    //! Default class constructor
    /*!
        \param threads - Count of threads to wait at the barrier
    */
    explicit Barrier(int threads);
    Barrier(const Barrier&) = delete;
    Barrier(Barrier&& barrier) noexcept;
    ~Barrier();

    Barrier& operator=(const Barrier&) = delete;
    Barrier& operator=(Barrier&& barrier) noexcept;

    //! Get the count of threads to wait at the barrier
    int threads() const noexcept;

    //! Wait at the barrier until all other threads reach this barrier
    /*!
        Will block.

        \return 'true' for the last thread that reach barrier, 'false' for each of the remaining threads
    */
    bool Wait();

private:
    class Impl;
    std::unique_ptr<Impl> _pimpl;
};

/*! \example threads_barrier.cpp Barrier synchronization primitive example */

} // namespace CppCommon

#endif // CPPCOMMON_THREADS_BARRIER_H