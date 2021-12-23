#include "SVDocumentClass.h"

#include <fstream>


namespace Machfly::SVDocument
{

    SeparatorArgs::SeparatorArgs(const char _pSeparator = ',',
                      const bool _pTrim = false)
        : Separator(_pSeparator),
          Trim(_pTrim)
    {}


    /**
     * @brief Construct a new Document:: Document object
     */
    Document::Document(const string& _pPath = std::string(),
                       const SeparatorArgs& _pSeparatorArgs = SeparatorArgs())
    : DocumentPath(_pPath),
      DocumentSeprator(_pSeparatorArgs)  /* Setters */
    {
        if(!DocumentPath.empty())
        {
            /* Start Reading the File */
            ReadDocument();
        }
        else
        {
            std::cerr << "SVDocumentParser[ERROR]:Document::Document()" << std::endl
                      << "DocumentPath Parameter is Empty!" << endl;
        }
    }


    Document::~Document() {}


    void Document::ReadDocument()
    {
        /* Read File */
        std::ifstream fileStream;
        fileStream.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        fileStream.open(DocumentPath, std::ios::binary);

        if(!fileStream.is_open())
        {
            std::cerr << "SVDocumentParser[ERROR]:Document::ReadDocument()" << std::endl
                      << "Can't Find Given File!" << endl;
        }

        ReadDocument(fileStream);

    }

    void Document::ReadDocument(std::istream& _pStream)
    {
        Clear();
    }

    void Document::Clear()
    {
        DocumentData.clear();
    }

    
} // namespace Machfly::SVDoc
