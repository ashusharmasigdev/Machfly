#include "SVDocumentClass.h"

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

    }

    
} // namespace Machfly::SVDoc
