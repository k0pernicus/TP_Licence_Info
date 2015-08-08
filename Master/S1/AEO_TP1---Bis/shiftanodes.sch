<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan6" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="clk" />
        <signal name="enable190" />
        <signal name="anodes(3:0)" />
        <signal name="anodes(3)" />
        <signal name="anodes(2)" />
        <signal name="anodes(1)" />
        <signal name="anodes(0)" />
        <port polarity="Input" name="clk" />
        <port polarity="Input" name="enable190" />
        <port polarity="Output" name="anodes(3:0)" />
        <blockdef name="fde">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="64" y1="-192" y2="-192" x1="0" />
            <line x2="64" y1="-256" y2="-256" x1="0" />
            <line x2="320" y1="-256" y2="-256" x1="384" />
            <rect width="256" x="64" y="-320" height="256" />
            <line x2="80" y1="-112" y2="-128" x1="64" />
            <line x2="64" y1="-128" y2="-144" x1="80" />
        </blockdef>
        <block symbolname="fde" name="XLXI_5">
            <blockpin signalname="clk" name="C" />
            <blockpin signalname="enable190" name="CE" />
            <blockpin signalname="anodes(3)" name="D" />
            <blockpin signalname="anodes(0)" name="Q" />
        </block>
        <block symbolname="fde" name="XLXI_6">
            <attr value="1" name="INIT">
                <trait verilog="all:0 dp:1" />
                <trait vhdl="all:0 gm:1" />
                <trait valuetype="Bit" />
            </attr>
            <blockpin signalname="clk" name="C" />
            <blockpin signalname="enable190" name="CE" />
            <blockpin signalname="anodes(0)" name="D" />
            <blockpin signalname="anodes(1)" name="Q" />
        </block>
        <block symbolname="fde" name="XLXI_7">
            <attr value="1" name="INIT">
                <trait verilog="all:0 dp:1" />
                <trait vhdl="all:0 gm:1" />
                <trait valuetype="Bit" />
            </attr>
            <blockpin signalname="clk" name="C" />
            <blockpin signalname="enable190" name="CE" />
            <blockpin signalname="anodes(1)" name="D" />
            <blockpin signalname="anodes(2)" name="Q" />
        </block>
        <block symbolname="fde" name="XLXI_8">
            <attr value="1" name="INIT">
                <trait verilog="all:0 dp:1" />
                <trait vhdl="all:0 gm:1" />
                <trait valuetype="Bit" />
            </attr>
            <blockpin signalname="clk" name="C" />
            <blockpin signalname="enable190" name="CE" />
            <blockpin signalname="anodes(2)" name="D" />
            <blockpin signalname="anodes(3)" name="Q" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1408" y="480" name="XLXI_5" orien="R0">
            <attrtext style="fontsize:28;fontname:Arial;displayformat:NAMEEQUALSVALUE" attrname="INIT" x="0" y="-64" type="instance" />
        </instance>
        <instance x="1408" y="1008" name="XLXI_6" orien="R0">
            <attrtext style="fontsize:28;fontname:Arial;displayformat:NAMEEQUALSVALUE" attrname="INIT" x="0" y="-64" type="instance" />
        </instance>
        <instance x="1408" y="1488" name="XLXI_7" orien="R0">
            <attrtext style="fontsize:28;fontname:Arial;displayformat:NAMEEQUALSVALUE" attrname="INIT" x="0" y="-64" type="instance" />
        </instance>
        <instance x="1408" y="1952" name="XLXI_8" orien="R0">
            <attrtext style="fontsize:28;fontname:Arial;displayformat:NAMEEQUALSVALUE" attrname="INIT" x="0" y="-64" type="instance" />
        </instance>
        <branch name="clk">
            <wire x2="752" y1="112" y2="352" x1="752" />
            <wire x2="1408" y1="352" y2="352" x1="752" />
            <wire x2="752" y1="352" y2="880" x1="752" />
            <wire x2="1408" y1="880" y2="880" x1="752" />
            <wire x2="752" y1="880" y2="1360" x1="752" />
            <wire x2="1408" y1="1360" y2="1360" x1="752" />
            <wire x2="752" y1="1360" y2="1824" x1="752" />
            <wire x2="1408" y1="1824" y2="1824" x1="752" />
        </branch>
        <iomarker fontsize="28" x="752" y="112" name="clk" orien="R270" />
        <branch name="enable190">
            <wire x2="368" y1="208" y2="304" x1="368" />
            <wire x2="816" y1="304" y2="304" x1="368" />
            <wire x2="368" y1="304" y2="832" x1="368" />
            <wire x2="816" y1="832" y2="832" x1="368" />
            <wire x2="368" y1="832" y2="1312" x1="368" />
            <wire x2="816" y1="1312" y2="1312" x1="368" />
            <wire x2="368" y1="1312" y2="1760" x1="368" />
            <wire x2="1408" y1="1760" y2="1760" x1="368" />
            <wire x2="816" y1="288" y2="304" x1="816" />
            <wire x2="1408" y1="288" y2="288" x1="816" />
            <wire x2="816" y1="816" y2="832" x1="816" />
            <wire x2="1408" y1="816" y2="816" x1="816" />
            <wire x2="816" y1="1296" y2="1312" x1="816" />
            <wire x2="1408" y1="1296" y2="1296" x1="816" />
        </branch>
        <iomarker fontsize="28" x="368" y="208" name="enable190" orien="R270" />
        <iomarker fontsize="28" x="2112" y="176" name="anodes(3:0)" orien="R270" />
        <branch name="anodes(3:0)">
            <wire x2="2112" y1="176" y2="224" x1="2112" />
            <wire x2="2112" y1="224" y2="752" x1="2112" />
            <wire x2="2112" y1="752" y2="1232" x1="2112" />
            <wire x2="2112" y1="1232" y2="1696" x1="2112" />
            <wire x2="2112" y1="1696" y2="1904" x1="2112" />
        </branch>
        <bustap x2="2016" y1="1696" y2="1696" x1="2112" />
        <branch name="anodes(3)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="1904" y="1696" type="branch" />
            <wire x2="1408" y1="224" y2="224" x1="1344" />
            <wire x2="1344" y1="224" y2="496" x1="1344" />
            <wire x2="2000" y1="496" y2="496" x1="1344" />
            <wire x2="2000" y1="496" y2="1696" x1="2000" />
            <wire x2="2016" y1="1696" y2="1696" x1="2000" />
            <wire x2="1904" y1="1696" y2="1696" x1="1792" />
            <wire x2="2000" y1="1696" y2="1696" x1="1904" />
        </branch>
        <bustap x2="2016" y1="1232" y2="1232" x1="2112" />
        <branch name="anodes(2)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="1904" y="1232" type="branch" />
            <wire x2="1328" y1="1568" y2="1696" x1="1328" />
            <wire x2="1408" y1="1696" y2="1696" x1="1328" />
            <wire x2="1888" y1="1568" y2="1568" x1="1328" />
            <wire x2="1888" y1="1232" y2="1232" x1="1792" />
            <wire x2="1904" y1="1232" y2="1232" x1="1888" />
            <wire x2="2016" y1="1232" y2="1232" x1="1904" />
            <wire x2="1888" y1="1232" y2="1568" x1="1888" />
        </branch>
        <bustap x2="2016" y1="752" y2="752" x1="2112" />
        <branch name="anodes(1)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="1904" y="752" type="branch" />
            <wire x2="1344" y1="1104" y2="1232" x1="1344" />
            <wire x2="1408" y1="1232" y2="1232" x1="1344" />
            <wire x2="1904" y1="1104" y2="1104" x1="1344" />
            <wire x2="1904" y1="752" y2="752" x1="1792" />
            <wire x2="2016" y1="752" y2="752" x1="1904" />
            <wire x2="1904" y1="752" y2="1104" x1="1904" />
        </branch>
        <bustap x2="2016" y1="224" y2="224" x1="2112" />
        <branch name="anodes(0)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="1904" y="224" type="branch" />
            <wire x2="1344" y1="624" y2="752" x1="1344" />
            <wire x2="1408" y1="752" y2="752" x1="1344" />
            <wire x2="1920" y1="624" y2="624" x1="1344" />
            <wire x2="1904" y1="224" y2="224" x1="1792" />
            <wire x2="1920" y1="224" y2="224" x1="1904" />
            <wire x2="2016" y1="224" y2="224" x1="1920" />
            <wire x2="1920" y1="224" y2="624" x1="1920" />
        </branch>
    </sheet>
</drawing>