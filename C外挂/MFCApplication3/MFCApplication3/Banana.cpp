#include "pch.h"
#include "Banana.h"

void CBanana::Init()
{
    // �����ʼ��λ��
    m_pos.x = rand() % 1024;
    m_pos.y = -10;

    // ��ʼ���ٶ�
    m_velocity.y = 1;
}

void CBanana::Draw(CPaintDC* pDC)
{
    // �����㽶�Ĵ���
}

void CBanana::Update()
{
    // ����λ�õĴ���
     // ����λ��
    m_pos += m_velocity;

    // ���߽�
    if (m_pos.y > 768) {
        m_velocity.y = -0.8 * m_velocity.y; // �������淴��
    }
}
 