

#include "pch.h"


#include "CAngularGuidedProjectile.h"
#include "CLevel.h"
#include "CLevelMgr.h"


void CAngularGuidedProjectile::tick(float _dt) {
    auto monsters = CLevelMgr::GetInst()->GetCurLevel()->GetMonsters();
    if (monsters.empty()) {
        return;
    }

    target = monsters[0];
    float targetDistance = 0;
    for (int i = 1; i < monsters.size(); ++i) {
        float monsterD = GetPos().Distance(monsters[i]->GetPos());
        targetDistance = GetPos().Distance(target->GetPos());
        if (monsterD < targetDistance) {
            target = monsters[i];
        }
    }
    auto curPos = GetPos();
    auto targetPos = target->GetPos();

    if(m_theta > PI){
        m_theta -= 2.f*PI;
    }
    if (m_theta < -PI) {
        m_theta += 2.f * PI;
    }


    /*Vec2 relative;
    relative.x = targetPos.x - curPos.x;
    relative.y = (targetPos.y - curPos.y);

    float angle;
    angle = atan2f(relative.y, relative.x);

    float rotateSpeed = angle / _dt;

    m_theta -= rotateSpeed * _dt;*/

    

    float targetth = atan2((-1) * (targetPos.y - curPos.y), (targetPos.x - curPos.x));
    float a = 10000.f;
    int x = m_Speed * cosf(m_theta) + (cosf(targetth) * a * _dt);


    int y = m_Speed * sinf(m_theta) + (sinf(targetth) * a * _dt);

    m_Speed = sqrtf(pow(x, 2) + pow(y, 2));
    m_theta = atan2(y, x);

    curPos.x += m_Speed * cosf(m_theta) * _dt;
    curPos.y -= m_Speed * sinf(m_theta) * _dt;

    

    SetPos(curPos);
}
