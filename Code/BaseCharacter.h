// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameplayTagContainer.h"
#include <GameplayEffectTypes.h>
#include "AbilitySystemInterface.h"
#include "MagicKnightAttributeSet.h"
#include "BaseCharacter.generated.h"

UCLASS(config = Game)
class PF_MAGICKNIGHT_API ABaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

//---------------------------------------------------����----------------------------------------------------//
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes", meta = (AllowPrivateAccess = "true"))
	class UAbilitySystemComponent* AbilitySystemComponent; //�����Ƽ �ý��� ������Ʈ

	UPROPERTY()
	UMagicKnightAttributeSet* Attributes; //��Ʈ����Ʈ

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attributes")
	TSubclassOf<class UGameplayEffect> DefaultAttributeEffect; //�⺻ ���� ������ GameplayEffect

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attributes")
	TArray<TSubclassOf<class UGameplayAbility>>DefaultAbility; //����ϴ� GameplayAbility

//----------------------------------------------------�Լ�----------------------------------------------------//
public:
	// Sets default values for this character's properties
	ABaseCharacter();

	FORCEINLINE UAbilitySystemComponent* GetAbilitySystemComponent() const { return AbilitySystemComponent; };

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void PossessedBy(AController* NewController) override; //ĳ���Ͱ� ���� �Ǿ����� ȣ�� ��
	virtual void OnRep_PlayerState() override; //���� �˸�(�����Ƽ�� �⺻������ �����Ǿ� ����)
	virtual void InitalizeAttribute(); //��Ʈ����Ʈ �ʱ�ȭ
	virtual void GiveAbilities(); //�����Ƽ �ο�

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};