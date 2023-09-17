﻿#pragma once

#define SINGLETON(ClassType)                                                   \
  public:                                                                      \
    static ClassType* GetInst() {                                              \
        static ClassType inst;                                                 \
        return &inst;                                                          \
    }                                                                          \
                                                                               \
  public:                                                                      \
    ClassType* operator=(const ClassType& _Origin) = delete;                   \
                                                                               \
  private:                                                                     \
    ClassType();                                                               \
    ClassType(const ClassType& _Origin) = delete;                              \
    ~ClassType();

#define KEY_CHECK(Key, State) CKeyMgr::GetInst()->GetKeyState(Key) == State
#define DT CTimeMgr::GetInst()->GetDeltaTime()

#define KEY_TAP(Key) KEY_CHECK(Key, TAP)
#define KEY_PRESSED(Key) KEY_CHECK(Key, PRESSED)
#define KEY_RELEASED(Key) KEY_CHECK(Key, RELEASED)
#define KEY_NONE(Key) KEY_CHECK(Key, NONE)

#define PI 3.14159265348979f
#define GAME_FOLDER MyGame

#define GENERATED_OBJECT(type)                                                 \
    typedef type Super;                                                        \
    virtual void Abstract() override {}

#define DEBUG_RENDER CEngine::GetInst()->DebugRender()

enum KEY {
    _0,
    _1,
    _2,
    _3,
    _4,
    _5,
    _6,
    _7,
    _8,
    _9,

    NUM0,
    NUM1,
    NUM2,
    NUM3,
    NUM4,
    NUM5,
    NUM6,
    NUM7,
    NUM8,
    NUM9,

    Q,
    W,
    E,
    R,
    T,
    Y,
    U,
    I,
    O,
    P,

    A,
    S,
    D,
    F,
    G,
    H,
    J,
    K,
    L,

    Z,
    X,
    C,
    V,
    B,
    N,
    M,

    TAB,
    LSHIFT,
    LALT,
    LCTRL,
    SPACE,

    ESC,
    ENTER,
    BACK,

    LEFT,
    RIGHT,
    UP,
    DOWN,

    KEY_END,
};

enum KEY_STATE {
    NONE,
    TAP,
    PRESSED,
    RELEASED,
};

enum LAYER {
    DEFAULT,
    TILE,
    PLAYER,
    MONSTER,
    PLAYER_PJ,
    MONSTER_PJ,
    WORLD_STATIC,

    END = 32,
};

enum TASK_TYPE {
    // Param1 : Layer Type, Param2 : Object Adress
    CREATE_OBJECT,

    // Param1 : Object Adress
    DELETE_OBJECT,

    LEVEL_CHANGE,
};