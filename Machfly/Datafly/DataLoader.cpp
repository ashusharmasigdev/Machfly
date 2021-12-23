#include <iostream>
#include <fstream>
#include <sstream>

#include <Extras/ErrorFunc.h>
#include <Datafly/DataLoader.h>

using namespace std;
using namespace Machfly::Extras;

namespace Machfly::Datafly
{

    /// @param _pFileName       : Path and name of the File containing the Data
    /// @param _pMaxColumns     : Will Limit the Maximum Selection of Columns, If 0, then All
    /// @param _pMaxRows        : Will Limit the Maximum Selection of Rows, If 0, then All

    Void
    DataLoader::LoadData(const DString _pFileName, UNumber _pMaxRows = 0, UNumber _pMaxColumns = 0)
    {

        if(!_pFileName)
        {
            ErrorFunc::ReleaseFatal("\n>> Machfly : Error[DataLoader::LoadData] Invalid FileName Provided.\n", true);
        }
        
        this->_DataFilePath = _pFileName;

        if(_pMaxRows > 0)
        {
            this->MaxRows = _pMaxRows;
        }

        if(_pMaxColumns > 0)
        {
            this->MaxColumns = _pMaxColumns;
        }

    }

    /// Map the Instances Size
    UNumber
    DataLoader::InstanceSize()
    {
        fstream _InputFile;
        _InputFile.open(this->_DataFilePath, ios::in);

        if(!_InputFile.is_open())
        {
            cout << "Given File Path : " << this->_DataFilePath << endl;
            ErrorFunc::ReleaseFatal("\n>> Machfly : Error[DataLoader::InstanceSize] Can't open File!", true);
        }
        else
        {
            cout << "File Successfully Opened : " << this->_DataFilePath << endl;
        }

        string Line;
        size_t Found;

        /* Ommiting Lines Containing '#' */
        do
        {
            getline(_InputFile, Line);
            Found = Line.find("#");
        } while (Found != string::npos);

        /* Extracting number of Instances on File */
        while (!_InputFile.eof())
        {
            getline(_InputFile, Line);
            this->NumInstance++;
        }

        cout << "\nNumber of Instances on File : " << this->NumInstance << endl;
        
        _InputFile.close();

        return this->NumInstance;

    }

    /// Map the Attributes Size
    UNumber
    DataLoader::AttributeSize()
    {
        fstream _InputFile;
        _InputFile.open(this->_DataFilePath, ios::in);

        if(!_InputFile.is_open())
        {
            ErrorFunc::ReleaseFatal("\n>> Machfly : Error[DataLoader::InstanceSize] Can't open File!", true);
        }

        string Line;
        string Attribute;
        size_t Found;

        /* Ommiting Lines Containing '#' */
        do
        {
            getline(_InputFile, Line);
            Found = Line.find("#");
        } while (Found != string::npos);

        stringstream StreamedLine(Line);
        StreamedLine >> Attribute;

        /* Extracting number of Instances on File */
        while (StreamedLine >> Attribute)
        {
            this->NumAttributes++;
        }

        cout << "\nNumber of Attributes on File : " << this->NumAttributes << endl;
        
        _InputFile.close();

        return this->NumAttributes;
    }

} // namespace Machfly::Datafly
