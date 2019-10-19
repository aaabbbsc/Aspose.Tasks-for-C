/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "WorkingWithProjects/ImportingAndExporting/ExportProjectDataToPrimaveraMPXFormat.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <saving/Enums/SaveFileFormat.h>
#include <Project.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

namespace ImportingAndExporting {

RTTI_INFO_IMPL_HASH(1050154123u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::ImportingAndExporting::ExportProjectDataToPrimaveraMPXFormat, ThisTypeBaseTypesInfo);

void ExportProjectDataToPrimaveraMPXFormat::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:ExportProjectDataToPrimaveraMPXFormat
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"Project1.mpp");
    
    // Save project in desired format
    project->Save(dataDir + u"ExportProjectDataToPrimaveraMPXFormat_out.xml", Aspose::Tasks::Saving::SaveFileFormat::MPX);
    // ExEnd:ExportProjectDataToPrimaveraMPXFormat
}

} // namespace ImportingAndExporting
} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
