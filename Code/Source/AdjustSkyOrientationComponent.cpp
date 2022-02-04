#include "AdjustSkyOrientationComponent.h"
#include <Cesium/Math/GeospatialHelper.h>
#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Component/TransformBus.h>

namespace cesium_o3de_samples {
	void AdjustSkyOrientationComponent::Reflect(AZ::ReflectContext* context)
	{
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<AdjustSkyOrientationComponent, AZ::Component>()
                ->Version(0)
                ;

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<AdjustSkyOrientationComponent>("Adjust Sky Orientation", "Keep the sky orientation to be the same when origin is shifted")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("Game"))
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
	}

	void AdjustSkyOrientationComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
	{
        provided.push_back(AZ_CRC("AdjustSkyOrientationSerivce"));
	}

	void AdjustSkyOrientationComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
	{
        incompatible.push_back(AZ_CRC("AdjustSkyOrientationSerivce"));
	}

	void AdjustSkyOrientationComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
	{
        required.push_back(AZ_CRC("TransformService", 0x8ee22c50));
	}

	void AdjustSkyOrientationComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
	{
	}

    void AdjustSkyOrientationComponent::Init()
    {
    }

    void AdjustSkyOrientationComponent::Activate()
    {
        AZ::Quaternion orientation;
        AZ::TransformBus::EventResult(orientation, GetEntityId(), &AZ::TransformBus::Events::GetWorldRotationQuaternion);
        m_orientation = glm::quat{ orientation.GetW(), orientation.GetX(), orientation.GetY(), orientation.GetZ() };

        Cesium::OriginShiftNotificationBus::Handler::BusConnect();
    }

    void AdjustSkyOrientationComponent::Deactivate()
    {
        Cesium::OriginShiftNotificationBus::Handler::BusDisconnect();
    }

    void AdjustSkyOrientationComponent::OnOriginShifting(const glm::dmat4& absToRelWorld)
    {
        glm::dmat4 relToAbsWorld{ 1.0 };
        Cesium::OriginShiftRequestBus::BroadcastResult(relToAbsWorld, &Cesium::OriginShiftRequestBus::Events::GetRelToAbsWorld);
        glm::dvec3 origin = relToAbsWorld * glm::dvec4(0.0, 0.0, 0.0, 1.0);
        glm::quat newOrientation = glm::quat(absToRelWorld * Cesium::GeospatialHelper::EastNorthUpToECEF(origin)) * m_orientation;
        AZ::TransformBus::Event(
            GetEntityId(), 
            &AZ::TransformBus::Events::SetWorldRotationQuaternion, 
            AZ::Quaternion(newOrientation.x, newOrientation.y, newOrientation.z, newOrientation.w));
    }
}