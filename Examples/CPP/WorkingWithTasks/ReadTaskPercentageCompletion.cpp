#include "ReadTaskPercentageCompletion.h"

#include <Tsk.h>
#include <TaskCollection.h>
#include <Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/convert.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <Project.h>
#include <Key.h>
#include <enums/TaskKey.h>
#include <cstdint>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithTasks {

RTTI_INFO_IMPL_HASH(3791031095u, ::Aspose::Tasks::Examples::CPP::WorkingWithTasks::ReadTaskPercentageCompletion, ThisTypeBaseTypesInfo);

void ReadTaskPercentageCompletion::Run()
{
    // ExStart:ReadTaskPercentageCompletion
    // Create project instance
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    System::SharedPtr<Project> project1 = System::MakeObject<Project>(dataDir + u"TaskPercentageCompletion.mpp");
    
    // Access tasks and display percentage completion
    auto tasks = project1->get_RootTask()->get_Children();
    
    {
        auto tsk1_enumerator = (tasks)->GetEnumerator();
        decltype(tsk1_enumerator->get_Current()) tsk1;
        while (tsk1_enumerator->MoveNext() && (tsk1 = tsk1_enumerator->get_Current(), true))
        {
            System::Console::WriteLine(tsk1->Get<int32_t>(Tsk::PercentComplete()));
            System::Console::WriteLine(System::Convert::ToString(tsk1->Get<int32_t>(Tsk::PercentWorkComplete())));
            System::Console::WriteLine(System::Convert::ToString(tsk1->Get<int32_t>(Tsk::PhysicalPercentComplete())));
        }
    }
    // ExEnd:ReadTaskPercentageCompletion
}

} // namespace WorkingWithTasks
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
