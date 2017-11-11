#pragma once

#include "CoreMinimal.h"
#include "IpNetDriver.h"
#include "SpatialNetDriver.generated.h"

class UEntityPipeline;
class UEntityRegistry;
class UCallbackDispatcher;
class USpatialOSComponentUpdater;
class USpatialOS;

UCLASS()
class NUF_API USpatialNetDriver : public UIpNetDriver
{
	GENERATED_BODY()
	
	virtual bool InitBase(bool bInitAsClient, FNetworkNotify* InNotify, const FURL& URL, bool bReuseAddressAndPort, FString& Error) override;
	virtual int32 ServerReplicateActors(float DeltaSeconds) override;
	virtual void TickDispatch(float DeltaTime) override;

private:
	UPROPERTY()
	USpatialOS* SpatialOSInstance;

	UPROPERTY()
	USpatialOSComponentUpdater* SpatialOSComponentUpdater;

	UPROPERTY()
	UEntityRegistry* EntityRegistry;

	UFUNCTION()
	void OnSpatialOSConnected();

	UFUNCTION()
	void OnSpatialOSConnectFailed();

	UFUNCTION()
	void OnSpatialOSDisconnected();
};