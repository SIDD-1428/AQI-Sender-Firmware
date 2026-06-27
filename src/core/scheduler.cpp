#include "scheduler.h"

#include "../utils/log.h"

Scheduler::Scheduler()
    : m_taskCount(0)
{
}

void Scheduler::begin()
{
    Log::info("Scheduler", "Initialized");
}

bool Scheduler::addTask(
    const char* name,
    uint32_t interval,
    void (*callback)(),
    bool repeat)
{
    if (m_taskCount >= MAX_TASKS)
    {
        Log::error("Scheduler", "Maximum task limit reached");
        return false;
    }

    Task& task = m_tasks[m_taskCount];

    task.name = name;
    task.interval = interval;
    task.lastRun = millis();
    task.callback = callback;
    task.enabled = true;
    task.repeat = repeat;
    task.executionCount = 0;

    m_taskCount++;

    Log::info(
        "Scheduler",
        String("Added Task: ") + name
    );

    return true;
}

void Scheduler::update()
{
    uint32_t currentTime = millis();

    for (uint8_t i = 0; i < m_taskCount; i++)
    {
        Task& task = m_tasks[i];

        if (!task.enabled)
        {
            continue;
        }

        if ((currentTime - task.lastRun) < task.interval)
        {
            continue;
        }

        if (task.callback != nullptr)
        {
            task.callback();

            task.executionCount++;

            Log::debug(
                "Scheduler",
                String("[")
                + task.name
                + "] Execution #"
                + String(task.executionCount)
            );
        }

        if (task.repeat)
        {
            task.lastRun += task.interval;
        }
        else
        {
            task.enabled = false;
        }
    }
}

bool Scheduler::enableTask(const char* name)
{
    for (uint8_t i = 0; i < m_taskCount; i++)
    {
        if (strcmp(m_tasks[i].name, name) == 0)
        {
            m_tasks[i].enabled = true;
            m_tasks[i].lastRun = millis();

            Log::info(
                "Scheduler",
                String("Enabled Task: ") + name
            );

            return true;
        }
    }

    return false;
}

bool Scheduler::disableTask(const char* name)
{
    for (uint8_t i = 0; i < m_taskCount; i++)
    {
        if (strcmp(m_tasks[i].name, name) == 0)
        {
            m_tasks[i].enabled = false;

            Log::info(
                "Scheduler",
                String("Disabled Task: ") + name
            );

            return true;
        }
    }

    return false;
}

uint8_t Scheduler::taskCount() const
{
    return m_taskCount;
}