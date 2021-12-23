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
        UNumber AttributeSize = this->AttributeSize();
        UNumber InstanceSize = this->InstanceSize();

        /* Extract Feature Set from Data File */
        this->DataX.set_size(InstanceSize, AttributeSize);
        this->DataX.zeros();
        this->ExtractFeatureX();
    }

    Void
    DataPlain::ExtractFeatureX()
    {
        string Line;
        Double iX;  /* Index X */
        size_t Found;

        /* Ommiting Containing Lines */
        do
        {
            getline(this->_DataFile, Line);
            Found = Line.find("#");
        } while (Found != string::npos);

        /* Extract Features, One Instance at a Time */
        for (UNumber m = 0; m < this->NumInstance; m++)
        {
            stringstream StreamedLine(Line);
            for (UNumber n = 0; n < this->NumAttributes; n++)
            {
                StreamedLine >> iX;
                this->DataX(m,n) = iX;
            }
            getline(this->_DataFile, Line);
        }
        
    }

} // namespace Machfly::Datafly
