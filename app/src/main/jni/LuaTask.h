//
// Created by Administrator on 2019/7/18.
//

#ifndef ANDROIDLUA_LUATASK_H
#define ANDROIDLUA_LUATASK_H

#include <sys/types.h>
#include <pthread.h>
#include <jni.h>

#include "LuaEngine.h"

class LuaTask {

public:
    LuaTask(const char* luaBuff);

    virtual ~LuaTask();

    void startWork();

    void stopWork();

    bool isRunning();

private:
    static void *startWorkInner(void *args);

private:
    const char* mLuaBuff;
    pthread_t mThreadId;
    LuaEngine *mLuaEngine;
};

#endif //ANDROIDLUA_LUATASK_H
