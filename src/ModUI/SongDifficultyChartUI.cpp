#include "ModUI/SongDifficultyChartUI.hpp"
using namespace SongDifficultyChart::UI;

#include "questui/shared/BeatSaberUI.hpp"
using namespace QuestUI;

DEFINE_TYPE(SongDifficultyChart::UI, SongDifficultyChartUI);


void SongDifficultyChartUI::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
{
    if (firstActivation)
    {
        UnityEngine::UI::VerticalLayoutGroup *container = BeatSaberUI::CreateVerticalLayoutGroup(get_transform());
        container->set_spacing(0.1f);

        BeatSaberUI::CreateText(container->get_transform(), "AAFHNJKEHNJFJKFHLHL");
        BeatSaberUI::CreateText(container->get_transform(), "GJUFRKGJKFOIRSOIGJI");
    }
}