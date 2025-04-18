#ifndef __PASTEVENT_PROG_H
#define __PASTEVENT_PROG_H

typedef struct events_past{
    char *instruction_executed;
} events_past;
// void pastevents(int flag, int index);
void pastevents(int flag, int index, events_past *e1);
#endif