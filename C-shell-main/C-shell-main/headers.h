#ifndef HEADERS_H_
#define HEADERS_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/utsname.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <signal.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <strings.h>
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include "prompt.h"
#include "warping.h"
#include "peeking.h"
#include "relative_path.h"
#include "pastevent_prog.h"
#include "procloring.h"
#include "seeking.h"
#include "seektocount.h"
#include "isPrefix.h"
// #include "background.h"

struct proc1{
    int pid;
    char *name;
    int status;
    int over;
};

#endif