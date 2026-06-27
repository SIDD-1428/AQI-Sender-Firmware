#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <Arduino.h>

class Scheduler
{
public:

    Scheduler();

    void begin();

    bool addTask(
        const char* name,
        uint32_t interval,
        void (*callback)(),
        bool repeat = true
    );

    void update();

    bool enableTask(const char* name);

    bool disableTask(const char* name);

    uint8_t taskCount() const;

private:

    struct Task
    {
        const char* name;

        uint32_t interval;

        uint32_t lastRun;

        void (*callback)();

        bool enabled;

        bool repeat;

        uint32_t executionCount;     // NEW
    };

    static constexpr uint8_t MAX_TASKS = 10;

    Task m_tasks[MAX_TASKS];

    uint8_t m_taskCount;
};

#endif