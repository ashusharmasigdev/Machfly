#pragma once


namespace Machfly::Datafly
{
    
    class Cell
    {

        private:

            /* data */
            /* std::vector */

        public:

            Cell(/* args */);

            template <typename T>
            T GetValue();

            /* Now It will be used like this, */
            /***
             * Cell _mycell;
             * _mycell >> 6
             * Now mycell have value 6
            */

            template <typename T>
            constexpr T operator>>(const T _data)
            {
                this.data = _data;
            }

            /**
             * Now, cout << _mycell
             * Then Value of cell will printed
            */
            template <typename T>
            constexpr T operator<<(const Cell& _self)
            {
                return _self.data;
            }

            /**
             * Now, cout << _mycell
             * Then Value of cell will printed
            */
            template <typename T>
            constexpr T operator+(const T _data)
            {
                this.data + _data;
                return this.data;
            }

            bool empty()
            {
                return true;
            }

            ~Cell();

    };

    /* Work for Row, Column */
    class Series
    {
        private:

            /* data */
            /* std::vector<cell> Cells .clear(), .empty() */

        public:

            Series(/* args */);

            template <typename T>
            T GetCell(const int _index);

            ~Series();

    };
    
    

    class Dataframe
    {

        private:

            /* std::vector<Series> Data() \ Data.at(0).begin */

        public:

            Dataframe();

            

    };
    


} // namespace Machfly::Datafly
