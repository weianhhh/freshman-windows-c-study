#include "pch.h"
#include "Banana.h"

void CBanana::Init()
{
    // 随机初始化位置
    m_pos.x = rand() % 1024;
    m_pos.y = -10;

    // 初始化速度
    m_velocity.y = 1;
}

void CBanana::Draw(CPaintDC* pDC)
{
    // 绘制香蕉的代码
}

void CBanana::Update()
{
    // 更新位置的代码
     // 更新位置
    m_pos += m_velocity;

    // 检查边界
    if (m_pos.y > 768) {
        m_velocity.y = -0.8 * m_velocity.y; // 碰到地面反弹
    }
}
 