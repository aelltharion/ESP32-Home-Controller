#ifndef EVENTS_H
#define EVENTS_H

enum class SystemEvent
{
    SetToHome,
    SetToNight,
    SetToAway,
    RemoveProtection,
    MotionDetected,
    MotionUndetected,
    None
};

enum class Mode
{
    Home,
    Night,
    Away,
    Trespassing
};

#endif