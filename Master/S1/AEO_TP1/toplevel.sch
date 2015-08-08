<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan6" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="switches(7:0)" />
        <signal name="led(7:0)" />
        <signal name="d(7:0)" />
        <signal name="anodes(3:0)" />
        <signal name="sevenseg(6:0)" />
        <signal name="clk" />
        <signal name="d(15:0)" />
        <signal name="d(15:8)" />
        <port polarity="Input" name="switches(7:0)" />
        <port polarity="Output" name="led(7:0)" />
        <port polarity="Output" name="anodes(3:0)" />
        <port polarity="Output" name="sevenseg(6:0)" />
        <port polarity="Input" name="clk" />
        <blockdef name="ibuf8">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <rect width="96" x="128" y="-44" height="24" />
            <line x2="128" y1="-32" y2="-32" x1="224" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="-32" x1="0" />
        </blockdef>
        <blockdef name="obuf8">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="128" y1="-32" y2="-32" x1="224" />
            <rect width="64" x="0" y="-44" height="24" />
            <rect width="96" x="128" y="-44" height="24" />
        </blockdef>
        <blockdef name="afficheur">
            <timestamp>2014-9-23T15:19:37</timestamp>
            <rect width="256" x="64" y="-128" height="128" />
            <rect width="64" x="0" y="-108" height="24" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-108" height="24" />
            <line x2="384" y1="-96" y2="-96" x1="320" />
            <rect width="64" x="320" y="-44" height="24" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <blockdef name="constant">
            <timestamp>2006-1-1T10:10:10</timestamp>
            <rect width="112" x="0" y="0" height="64" />
            <line x2="112" y1="32" y2="32" x1="144" />
        </blockdef>
        <block symbolname="ibuf8" name="XLXI_1">
            <blockpin signalname="switches(7:0)" name="I(7:0)" />
            <blockpin signalname="d(7:0)" name="O(7:0)" />
        </block>
        <block symbolname="obuf8" name="XLXI_2">
            <blockpin signalname="d(7:0)" name="I(7:0)" />
            <blockpin signalname="led(7:0)" name="O(7:0)" />
        </block>
        <block symbolname="constant" name="XLXI_5">
            <attr value="00" name="CValue">
                <trait delete="all:1 sym:0" />
                <trait editname="all:1 sch:0" />
                <trait valuetype="BitVector 2 Hexadecimal" />
            </attr>
            <blockpin signalname="d(15:8)" name="O" />
        </block>
        <block symbolname="afficheur" name="XLXI_7">
            <blockpin signalname="d(15:0)" name="din(15:0)" />
            <blockpin signalname="clk" name="clk" />
            <blockpin signalname="sevenseg(6:0)" name="sevenseg(6:0)" />
            <blockpin signalname="anodes(3:0)" name="anodes(3:0)" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="624" y="768" name="XLXI_1" orien="R0" />
        <instance x="2464" y="1440" name="XLXI_2" orien="R0" />
        <branch name="switches(7:0)">
            <wire x2="624" y1="736" y2="736" x1="592" />
        </branch>
        <iomarker fontsize="28" x="592" y="736" name="switches(7:0)" orien="R180" />
        <branch name="d(7:0)">
            <attrtext style="alignment:SOFT-TVCENTER" attrname="Name" x="2320" y="1456" type="branch" />
            <wire x2="1648" y1="736" y2="736" x1="848" />
            <wire x2="1648" y1="736" y2="1408" x1="1648" />
            <wire x2="2320" y1="1408" y2="1408" x1="1648" />
            <wire x2="2464" y1="1408" y2="1408" x1="2320" />
            <wire x2="2320" y1="1408" y2="1456" x1="2320" />
            <wire x2="2320" y1="1456" y2="1504" x1="2320" />
        </branch>
        <branch name="led(7:0)">
            <wire x2="2704" y1="1408" y2="1408" x1="2688" />
            <wire x2="2720" y1="1408" y2="1408" x1="2704" />
        </branch>
        <iomarker fontsize="28" x="2720" y="1408" name="led(7:0)" orien="R0" />
        <branch name="anodes(3:0)">
            <wire x2="2096" y1="1856" y2="1856" x1="2064" />
            <wire x2="2064" y1="1856" y2="1952" x1="2064" />
            <wire x2="2160" y1="1952" y2="1952" x1="2064" />
            <wire x2="2160" y1="1952" y2="2160" x1="2160" />
            <wire x2="2080" y1="2160" y2="2160" x1="2064" />
            <wire x2="2160" y1="2160" y2="2160" x1="2080" />
            <wire x2="2064" y1="2160" y2="2224" x1="2064" />
            <wire x2="2128" y1="2224" y2="2224" x1="2064" />
            <wire x2="2128" y1="2224" y2="2416" x1="2128" />
            <wire x2="2128" y1="2416" y2="2416" x1="2064" />
        </branch>
        <iomarker fontsize="28" x="2096" y="1856" name="anodes(3:0)" orien="R0" />
        <branch name="sevenseg(6:0)">
            <wire x2="2080" y1="1792" y2="1792" x1="2064" />
            <wire x2="2096" y1="1792" y2="1792" x1="2080" />
            <wire x2="2080" y1="1792" y2="2096" x1="2080" />
            <wire x2="2080" y1="2096" y2="2096" x1="2064" />
            <wire x2="2064" y1="2096" y2="2144" x1="2064" />
            <wire x2="2144" y1="2144" y2="2144" x1="2064" />
            <wire x2="2144" y1="2144" y2="2352" x1="2144" />
            <wire x2="2144" y1="2352" y2="2352" x1="2064" />
        </branch>
        <iomarker fontsize="28" x="2096" y="1792" name="sevenseg(6:0)" orien="R0" />
        <branch name="clk">
            <wire x2="272" y1="352" y2="1856" x1="272" />
            <wire x2="272" y1="1856" y2="2112" x1="272" />
            <wire x2="1680" y1="1856" y2="1856" x1="272" />
            <wire x2="1680" y1="1856" y2="1888" x1="1680" />
            <wire x2="1680" y1="2176" y2="2176" x1="1600" />
            <wire x2="1600" y1="2176" y2="2416" x1="1600" />
            <wire x2="1680" y1="2416" y2="2416" x1="1600" />
            <wire x2="1680" y1="1888" y2="1888" x1="1616" />
            <wire x2="1616" y1="1888" y2="2160" x1="1616" />
            <wire x2="1680" y1="2160" y2="2160" x1="1616" />
            <wire x2="1680" y1="2160" y2="2176" x1="1680" />
        </branch>
        <iomarker fontsize="28" x="272" y="352" name="clk" orien="R270" />
        <branch name="d(15:0)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="1600" y="1600" type="branch" />
            <wire x2="1600" y1="1600" y2="1792" x1="1600" />
            <wire x2="1680" y1="1792" y2="1792" x1="1600" />
            <wire x2="1680" y1="1792" y2="1808" x1="1680" />
            <wire x2="1616" y1="1600" y2="1600" x1="1600" />
            <wire x2="2320" y1="1600" y2="1600" x1="1616" />
            <wire x2="2544" y1="1600" y2="1600" x1="2320" />
            <wire x2="2784" y1="1600" y2="1600" x1="2544" />
            <wire x2="1680" y1="1808" y2="1808" x1="1600" />
            <wire x2="1600" y1="1808" y2="2096" x1="1600" />
            <wire x2="1680" y1="2096" y2="2096" x1="1600" />
            <wire x2="1680" y1="2096" y2="2112" x1="1680" />
            <wire x2="1680" y1="2112" y2="2112" x1="1664" />
            <wire x2="1664" y1="2112" y2="2352" x1="1664" />
            <wire x2="1680" y1="2352" y2="2352" x1="1664" />
        </branch>
        <bustap x2="2320" y1="1600" y2="1504" x1="2320" />
        <instance x="2400" y="1456" name="XLXI_5" orien="R0">
        </instance>
        <bustap x2="2544" y1="1600" y2="1504" x1="2544" />
        <branch name="d(15:8)">
            <attrtext style="alignment:SOFT-TVCENTER" attrname="Name" x="2544" y="1496" type="branch" />
            <wire x2="2544" y1="1488" y2="1496" x1="2544" />
            <wire x2="2544" y1="1496" y2="1504" x1="2544" />
        </branch>
        <instance x="1680" y="2448" name="XLXI_7" orien="R0">
        </instance>
    </sheet>
</drawing>