
#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>

#include "cesium-o3de-samplesSystemComponent.h"

namespace cesium_o3de_samples
{
    void cesium_o3de_samplesSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<cesium_o3de_samplesSystemComponent, AZ::Component>()
                ->Version(0)
                ;

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<cesium_o3de_samplesSystemComponent>("cesium_o3de_samples", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void cesium_o3de_samplesSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("cesium_o3de_samplesService"));
    }

    void cesium_o3de_samplesSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("cesium_o3de_samplesService"));
    }

    void cesium_o3de_samplesSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void cesium_o3de_samplesSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }
    
    cesium_o3de_samplesSystemComponent::cesium_o3de_samplesSystemComponent()
    {
        if (cesium_o3de_samplesInterface::Get() == nullptr)
        {
            cesium_o3de_samplesInterface::Register(this);
        }
    }

    cesium_o3de_samplesSystemComponent::~cesium_o3de_samplesSystemComponent()
    {
        if (cesium_o3de_samplesInterface::Get() == this)
        {
            cesium_o3de_samplesInterface::Unregister(this);
        }
    }

    void cesium_o3de_samplesSystemComponent::Init()
    {
    }

    void cesium_o3de_samplesSystemComponent::Activate()
    {
        cesium_o3de_samplesRequestBus::Handler::BusConnect();
    }

    void cesium_o3de_samplesSystemComponent::Deactivate()
    {
        cesium_o3de_samplesRequestBus::Handler::BusDisconnect();
    }
}
