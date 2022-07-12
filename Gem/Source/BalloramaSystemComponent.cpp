
#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>

#include "BalloramaSystemComponent.h"

namespace Ballorama
{
    void BalloramaSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<BalloramaSystemComponent, AZ::Component>()
                ->Version(0)
                ;

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<BalloramaSystemComponent>("Ballorama", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void BalloramaSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("BalloramaService"));
    }

    void BalloramaSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("BalloramaService"));
    }

    void BalloramaSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void BalloramaSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    BalloramaSystemComponent::BalloramaSystemComponent()
    {
        if (BalloramaInterface::Get() == nullptr)
        {
            BalloramaInterface::Register(this);
        }
    }

    BalloramaSystemComponent::~BalloramaSystemComponent()
    {
        if (BalloramaInterface::Get() == this)
        {
            BalloramaInterface::Unregister(this);
        }
    }

    void BalloramaSystemComponent::Init()
    {
    }

    void BalloramaSystemComponent::Activate()
    {
        BalloramaRequestBus::Handler::BusConnect();
    }

    void BalloramaSystemComponent::Deactivate()
    {
        BalloramaRequestBus::Handler::BusDisconnect();
    }
}
