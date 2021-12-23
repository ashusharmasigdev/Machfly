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

        this->DataY.set_size(InstanceSize);
        this->DataY.zeros();
        this->ExtractFeatureY();

        this->_DataX = (Double*)(void*)malloc(InstanceSize*AttributeSize);
        this->_DataY = (Double*)(void*)malloc(InstanceSize*AttributeSize);
    }

    /// This Will Read File Data
    Void
    DataPlain::ReadCSVData()
    {
        
        // string Line;
        // size_t RowSize = 0;

        // do
        // {
        //     getline(this->File, Line);
        //     RowSize = Line.find(',');
        // } while (RowSize > 0);
        
        // cout << RowSize << endl;
        
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

            this->_DataX[m] = iX;
            
            getline(this->_DataFile, Line);
        }
        
    }

    Void
    DataPlain::ExtractFeatureY()
    {
        string Line;
        Double iY;  /* Index X */
        Double Y;
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
                StreamedLine >> iY;
            }

            StreamedLine >> Y;
            this->DataY(m) = Y;

            this->_DataY[m] = Y;

            getline(this->_DataFile, Line);
        }
        
    }

    Double
    DataPlain::GetCellFromFeatureX(Double _pX, Double _pY)
    {
        return this->DataX(_pX, _pY);
    }

    Double
    DataPlain::GetCellFromFeatureY(Double _pI)
    {
        return this->DataY(_pI);
    }

} // namespace Machfly::Datafly
