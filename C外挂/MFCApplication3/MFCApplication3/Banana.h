#include "pch.h"
#pragma once

class CBanana
{
public:
    void Init();
    void Draw(CPaintDC* pDC);
    void Update();

private:
    CPoint m_pos;
    CPoint m_velocity;
};