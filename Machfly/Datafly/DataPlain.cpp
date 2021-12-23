#include <iostream>
#include <fstream>
#include <sstream>

#include <Extras/ErrorFunc.h>
#include <Datafly/DataPlain.h>

using namespace std;
using namespace Machfly::Extras;

namespace Machfly::Datafly
{
    
    /// This Will Read File Data
    Void
    DataPlain::ReadFileData()
    {
        /* Extract No. of Instances and Attributes */
        UNumber InstanceSize = this->InstanceSize();
        UNumber AttributeSize = this->AttributeSize();
    }

} // namespace Machfly::Datafly
