/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "UsingSpreadsheet2003SaveOptions.h"

#include <visualization/View/ViewColumn.h>
#include <visualization/View/ResourceViewColumn.h>
#include <visualization/View/ProjectView.h>
#include <visualization/View/GanttChartColumn.h>
#include <visualization/View/AssignmentViewColumn.h>
#include <Tsk.h>
#include <Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/collections/list.h>
#include <saving/Excel/SpreadSheet2003/Spreadsheet2003SaveOptions.h>
#include <Rsc.h>
#include <ResourceAssignment.h>
#include <Resource.h>
#include <Project.h>
#include <Key.h>
#include <enums/TaskKey.h>
#include <enums/RscKey.h>
#include <enums/AsnKey.h>
#include <Asn.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
using namespace Aspose::Tasks::Visualization;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace ConvertingProjectData {

RTTI_INFO_IMPL_HASH(2783516275u, ::Aspose::Tasks::Examples::CPP::ConvertingProjectData::UsingSpreadsheet2003SaveOptions, ThisTypeBaseTypesInfo);

System::String UsingSpreadsheet2003SaveOptions::_anonymous_method_0(System::SharedPtr<Task> task)
{
    return task->Get(Tsk::WBS());
}

System::String UsingSpreadsheet2003SaveOptions::_anonymous_method_1(System::SharedPtr<Resource> resource)
{
    return resource->Get<System::String>(Rsc::CostCenter());
}

System::String UsingSpreadsheet2003SaveOptions::_anonymous_method_2(System::SharedPtr<ResourceAssignment> assignment)
{
    return assignment->Get<System::String>(Asn::Notes());
}

void UsingSpreadsheet2003SaveOptions::Run()
{
    
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // Read the input Project file
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"CreateProject2.mpp");
    
    // ExStart:UsingSpreadsheet2003SaveOptions
    System::SharedPtr<Spreadsheet2003SaveOptions> options = System::MakeObject<Spreadsheet2003SaveOptions>();
    System::SharedPtr<GanttChartColumn> col = System::MakeObject<GanttChartColumn>(u"WBS", 100, &UsingSpreadsheet2003SaveOptions::_anonymous_method_0);
    options->get_View()->get_Columns()->Add(col);
    
    System::SharedPtr<ResourceViewColumn> rscCol = System::MakeObject<ResourceViewColumn>(u"Cost center", 100, &UsingSpreadsheet2003SaveOptions::_anonymous_method_1);
    options->get_ResourceView()->get_Columns()->Add(rscCol);
    
    System::SharedPtr<AssignmentViewColumn> assnCol = System::MakeObject<AssignmentViewColumn>(u"Notes", 200, &UsingSpreadsheet2003SaveOptions::_anonymous_method_2);
    options->get_AssignmentView()->get_Columns()->Add(assnCol);
    
    project->Save(dataDir + u"UsingSpreadsheet2003SaveOptions_out.xml", options);
    // ExEnd:UsingSpreadsheet2003SaveOptions
}

} // namespace ConvertingProjectData
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
