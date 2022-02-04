#pragma once

#include <Cesium/EBus/OriginShiftComponentBus.h>
#include <AzCore/Component/Component.h>
#include <glm/gtc/quaternion.hpp>

namespace cesium_o3de_samples {
	class AdjustSkyOrientationComponent
		: public AZ::Component
		, public Cesium::OriginShiftNotificationBus::Handler
	{
    public:
        AZ_COMPONENT(AdjustSkyOrientationComponent, "{C0AF3360-CEF2-4DEE-9D36-3FE3D075BEA6}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);

        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);

        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);

        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

    protected:
        void Init() override;

        void Activate() override;

        void Deactivate() override;

        void OnOriginShifting(const glm::dmat4& absToRelWorld) override;

        glm::quat m_orientation{ 1.0f, 0.0f, 0.0f, 0.0f };
	};
}