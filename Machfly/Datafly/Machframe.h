/**
 * @file Machframe.h
 * @author Ashu Sharma (ashusharma.sigmadev@gmail.com)
 * @brief Data Container, Reader and Retriever [Single Header File]
 * @version 0.1
 * @date 2021-12-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <fstream>

namespace Machfly
{

    /* Datagrid */

    enum class SVFieldState {
        UnquotedField,
        QuotedField,
        QuotedQuote
    };

    struct MachDocument
    {
        explicit MachDocument(const std::string _pDocName)
                : DocumentName(_pDocName)
        {}

        std::string DocumentName;
    };
    
    

    class Machframe
    {

        private:

            std::vector<std::vector<std::string>>   FrameData;
            std::map<std::string, size_t>           FrameColumnsList;
            std::map<std::string, size_t>           FrameRowsList;

            // MachDocument                            DocumentParameters;

        public:

            // explicit Machframe(MachDocument& _pDocParams = MachDocument())
            //     : DocumentParameters(_pDocParams)
            // {}
            explicit Machframe()
            {}

            /* Including Row Name and Column Name */
            void GetCell(const size_t _Col, const size_t _Row)
            {
                std::cout << FrameData.at(_Col).at(_Row) << std::endl;
            }

            void PrintDataGrid()
            {
                for (size_t i = 0; i < FrameData.size(); i++)
                {
                    for (size_t k = 0; k < FrameData.at(i).size(); k++)
                    {
                        GetCell(i,k);
                    }
                    
                }
                
            }

            template <typename T>
            void SetCell(const size_t _ColumnId, const size_t _RowId, const T& _CellData)
            {
                // FrameData.at(_RowId).at(_ColumnId) = _CellData;
            }

            void LoadSVDocument(const std::string& _FileName = std::string())
            {
                std::fstream SVDocument;
                SVDocument.open(_FileName, std::ios::in);
                ReadSVDocStream(SVDocument);
                SVDocument.close();
            }

            void ReadSVDocStream(std::fstream &svdoc)
            {
                std::string row;
                while (!svdoc.eof())
                {
                    std::getline(svdoc, row);
                    if(svdoc.bad() || svdoc.fail())
                    {
                        break;
                    }
                    auto Fields = ParseSVRow(row);
                    FrameData.push_back(Fields);
                }
                
            }

            std::vector<std::string> ParseSVRow(const std::string &_Row)
            {
                SVFieldState fieldState = SVFieldState::UnquotedField;
                std::vector<std::string> Fields {""};
                size_t i = 0;   /* Current Field Index */

                for (char c : _Row)
                {
                    switch (fieldState)
                    {
                        case SVFieldState::UnquotedField:
                            switch (c)
                            {
                                case ',':   /* Comma found [Seprator] */
                                    Fields.push_back(""); i++;
                                    break;
                                case '"':
                                    fieldState = SVFieldState::QuotedField;
                                    break;
                                default:
                                    Fields[i].push_back(c);
                                    break;
                            }
                            break;
                        
                        case SVFieldState::QuotedField:
                            switch (c)
                            {
                                case '"':
                                    fieldState = SVFieldState::QuotedQuote;
                                    break;
                                default:
                                    Fields[i].push_back(c);
                                    break;
                            }
                            break;
                        
                        case SVFieldState::QuotedQuote:
                            switch (c)
                            {
                                case ',':
                                    Fields.push_back(""); i++;
                                    fieldState = SVFieldState::UnquotedField;
                                    break;
                                case '"':
                                    Fields[i].push_back('"');
                                    fieldState = SVFieldState::QuotedField;
                                    break;
                                default:
                                    fieldState = SVFieldState::UnquotedField;
                                    break;
                            }
                    }
                }

                return Fields;
                
            }

    };
    


} // namespace Machfly
