
#pragma once

#include <AzCore/Component/Component.h>

#include <Ballorama/BalloramaBus.h>

namespace Ballorama
{
    class BalloramaSystemComponent
        : public AZ::Component
        , protected BalloramaRequestBus::Handler
    {
    public:
        AZ_COMPONENT(BalloramaSystemComponent, "{a82c9248-32a5-4c4b-a4ea-cea33f7421f9}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        BalloramaSystemComponent();
        ~BalloramaSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // BalloramaRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
