### <b>PLANING :</b>
# <b>Data Types</b>

<p>

Like Panda and other already available Data Scientists, It will have a Universal Data Type for DataFrame, Parser will read data from files like .dat, .csv, .xlt etc... and will form a Dataframe with row & columns, Dataframe will have already function to sum the datas, count, etc....

Examples to Use:

Actually, MachDataFrame is renamed as FlyDataPlain[3D Data Space[x,y]] or FlyDataCube[3D Data Space[x,y,z]]
Also Make Data Generator also as Shape

Use Try And Catch

MachDataFrame* SampleData;

Will Work on Template Systems :
Will Reserve Memory

MachDataFrame* _Data = SampleData.GetRow("Salary")<String>
SampleData.GetRow(0)<Int>
SampleData.GetRow("MCH_cmd[ALL-"%Salary"]")<Will_Work_on_printf_like>
SampleData.GetCell(X,Y)
SampleData.GetColumn(X)
SampleData.Sum()
SampleData.Mean()
SampleData.Max()    /* Will Return Coordinates of Maximum Value */
SampleData.Min()
SampleData.Median() /* In MachFly there will a Math Class that will do these, DataFrame will only have inbuilt using Median by giving data invisibly */
SampleData.OutAsFile("filename.ext")

</p>