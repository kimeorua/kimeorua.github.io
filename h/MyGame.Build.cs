// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MyGame : ModuleRules
{
	public MyGame(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
		PrivateDependencyModuleNames.AddRange(new string[] { "GameplayAbilities", "GameplayTags", "GameplayTasks" }); //�����Ƽ �ý��� ����� ���� ���(�÷����� üũ�� ����)
    }
}