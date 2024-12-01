#include "CombatComponent.h"

#include "BlasterCourse/Character/BlasterCharacter.h"
#include "BlasterCourse/Weapon/Weapon.h"
#include "Engine/SkeletalMeshSocket.h"

UCombatComponent::UCombatComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	
}

void UCombatComponent::BeginPlay()
{
	Super::BeginPlay();
	
	
}


void UCombatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
}

void UCombatComponent::EquipWeapon(AWeapon* WeaponToEquip)
{
	if (!BlasterCharacter || !WeaponToEquip) return;

	EquippedWeapon = WeaponToEquip;
	EquippedWeapon->SetWeaponState(EWeaponState::EWS_Equipped);
	const USkeletalMeshSocket* HandSocket = BlasterCharacter->GetMesh()->GetSocketByName(FName("RightHandSocket"));
	if (HandSocket)
	{
		HandSocket->AttachActor(EquippedWeapon, BlasterCharacter->GetMesh());
	}
	EquippedWeapon->SetOwner(BlasterCharacter);
	EquippedWeapon->ShowPickupWidget(false);
}

