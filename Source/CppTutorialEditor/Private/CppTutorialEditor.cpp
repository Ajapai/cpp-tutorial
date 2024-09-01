#include "CppTutorialEditor.h"

#include "MoveComponent.h"
#include "MoveComponentVisualizer.h"
#include "UnrealEdGlobals.h"
#include "Editor/UnrealEdEngine.h"

#define LOCTEXT_NAMESPACE "FCppTutorialEditorModule"

void FCppTutorialEditorModule::StartupModule()
{
    if (GUnrealEd)
    {
        const TSharedPtr<FMoveComponentVisualizer> MoveControllerVisualizer = MakeShareable(new FMoveComponentVisualizer());
        GUnrealEd->RegisterComponentVisualizer(UMoveComponent::StaticClass()->GetFName(), MoveControllerVisualizer);
        MoveControllerVisualizer->OnRegister();
    }
}

void FCppTutorialEditorModule::ShutdownModule()
{
    if (GUnrealEd)
    {
        GUnrealEd->UnregisterComponentVisualizer(UMoveComponent::StaticClass()->GetFName());
    }
    
}

#undef LOCTEXT_NAMESPACE
    
IMPLEMENT_MODULE(FCppTutorialEditorModule, CppTutorialEditor)