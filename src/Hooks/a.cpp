#include "main.hpp"
#include "ModConfig.hpp"
#include "Hooks.hpp"

#include "GlobalNamespace/AudioTimeSyncController.hpp"
using namespace GlobalNamespace;

using namespace UnityEngine;

bool graphCreated;
bool hasNotes;

int songTime;
float songLength;

void makeLine(Vector2 a, Vector2 b, Transform *parent)
{
    GameObject *line = GameObject::New_ctor("line");
    line->get_transform()->SetParent(parent, false);
    UI::Image *image = line->AddComponent<UI::Image *>();
    image->set_color({0.1f, 0.1f, 0.1f, 1.0f});

    RectTransform *lineTrans = line->GetComponent<RectTransform *>();
    Vector2 dir = (b - a).get_normalized();

    float dist = Vector2::Distance(a, b);
    lineTrans->set_sizeDelta(Vector2(dist + std::min(60.0f, 30.0f), std::min(4.0f, 1.0f)));
    lineTrans->set_anchoredPosition(a + dir *dist *0.5);
    lineTrans->set_localEulerAngles(Vector3(0, 0, atan2(dir.y, dir.x) * 57.29578));
}


MAKE_AUTO_HOOK_MATCH(AudioTimeSyncController_Awake, &AudioTimeSyncController::Awake, void, AudioTimeSyncController *self)
{
    AudioTimeSyncController_Awake(self);

    hasNotes = true;
    graphCreated = false;
}

MAKE_AUTO_HOOK_MATCH(AudioTimeSyncController_Update, &AudioTimeSyncController::Update, void, AudioTimeSyncController *self)
{
    AudioTimeSyncController_Update(self);

    songTime = self->songTime;

    if (!graphCreated && hasNotes)
    {
        hasNotes = false;

        songLength = *il2cpp_utils::RunMethod<float>(self, "get_songLength");
        
    }
}